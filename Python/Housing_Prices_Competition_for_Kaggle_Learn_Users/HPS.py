import pandas as pd
import numpy as np
from sklearn.tree import DecisionTreeRegressor
from sklearn.preprocessing import OrdinalEncoder
from sklearn.metrics import mean_absolute_error
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor
from sklearn.impute import SimpleImputer


# прочитали файлы
houses_data_train = pd.read_csv("C:\\vscode\Python\Housing_Prices_Competition_for_Kaggle_Learn_Users\\train.csv")
houses_data_valid = pd.read_csv("C:\\vscode\Python\Housing_Prices_Competition_for_Kaggle_Learn_Users\\test.csv")

# выбрали что ищем и что идет в дерево
y_train = houses_data_train.SalePrice
X_train = houses_data_train[houses_data_train.columns]
X_valid = houses_data_valid[houses_data_valid.columns]

# вствка среднего значения по колонке в места где Nan
my_imputer = SimpleImputer()
imputed_X_train = pd.DataFrame(my_imputer.fit_transform(X_train))
imputed_X_valid = pd.DataFrame(my_imputer.transform(X_valid))

# отбор колонок в которых лежат строчки
s = (X_train.dtypes == "object")
object_cols = list(s[s].index)

# преобразование колонок со строчками во что-то другое
label_X_train = X_train.copy()
label_X_valid = X_valid.copy()
ordinal_encoder = OrdinalEncoder()
label_X_train[object_cols] = ordinal_encoder.fit_transform(X_train[object_cols])
label_X_valid[object_cols] = ordinal_encoder.transform(X_valid[object_cols])

# тренировка и предикт модели
house_model = RandomForestRegressor(n_estimators=100, random_state=0)
house_model.fit(label_X_train, y_train)
preds = house_model.predict(X_valid)

print("Предикт модели: " + preds)

