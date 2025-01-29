import pandas as pd
import numpy as np
from sklearn.preprocessing import OrdinalEncoder
from sklearn.ensemble import RandomForestRegressor
from sklearn.impute import SimpleImputer


# прочитали файлы
houses_data_train = pd.read_csv("C:\\vscode\Python\Housing_Prices_Competition_for_Kaggle_Learn_Users\\train.csv")
houses_data_valid = pd.read_csv("C:\\vscode\Python\Housing_Prices_Competition_for_Kaggle_Learn_Users\\test.csv")

# выбрали что ищем и что идет в дерево
y_train = houses_data_train.SalePrice
X_train = houses_data_train[houses_data_train.columns]
X_valid = houses_data_valid[houses_data_valid.columns]

# удаление колонок со строчками и которых есть Nan
X_valid = X_valid.dropna(axis=1)
X_train = X_train[X_valid.columns]

# отбор колонок в которых лежат строчки
s = (X_train.dtypes == "object")
object_cols = list(s[s].index)


# преобразование колонок со строчками во что-то другое
label_X_train = X_train.copy()
label_X_valid = X_valid.copy()
ordinal_encoder = OrdinalEncoder()
label_X_train[object_cols] = ordinal_encoder.fit_transform(X_train[object_cols])
label_X_valid[object_cols] = ordinal_encoder.transform(X_valid[object_cols])

# вствка среднего значения по колонке в места где Nan
numeric_imputer = SimpleImputer(strategy='mean')

# Импутация пропусков в числовых данных
imputed_X_train = pd.DataFrame(numeric_imputer.fit_transform(X_train.select_dtypes(include=['float64', 'int64'])), columns=X_train.select_dtypes(include=['float64', 'int64']).columns)
imputed_X_valid = pd.DataFrame(numeric_imputer.transform(X_valid.select_dtypes(include=['float64', 'int64'])), columns=X_valid.select_dtypes(include=['float64', 'int64']).columns)


# тренировка и предикт модели
house_model = RandomForestRegressor(n_estimators=100, random_state=0)
house_model.fit(label_X_train, y_train)
preds = house_model.predict(label_X_valid)

answer = pd.DataFrame({'Id': X_valid.index + 1461, 'SalePrice': preds})
answer.to_csv("sample_submission.csv", index=False)