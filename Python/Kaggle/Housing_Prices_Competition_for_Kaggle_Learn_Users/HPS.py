import pandas as pd
import numpy as np
from sklearn.preprocessing import OrdinalEncoder
from sklearn.ensemble import RandomForestRegressor
from sklearn.impute import SimpleImputer

def delete(df):
    delete_columns = []
    for index in df.columns.tolist():
        check_str = False
        check_nan = False
        for value in df[index].tolist():
            if isinstance(value, str):  # Проверка на строку
                check_str = True
            elif pd.isna(value):  # Проверка на NaN
                check_nan = True
        # Если есть строки и NaN, добавляем столбец в список для удаления
        if check_str and check_nan:
            delete_columns.append(index)
    return delete_columns


# прочитали файлы
houses_data_train = pd.read_csv("C:\\vscode\Python\Housing_Prices_Competition_for_Kaggle_Learn_Users\\train.csv")
houses_data_valid = pd.read_csv("C:\\vscode\Python\Housing_Prices_Competition_for_Kaggle_Learn_Users\\test.csv")

# выбрали что ищем и что идет в дерево
y_train = houses_data_train.SalePrice
X_train = houses_data_train[houses_data_train.columns]
X_valid = houses_data_valid[houses_data_valid.columns]

# удаление колонок со строчками и которых есть Nan
delete_columns = delete(X_valid)
X_valid = X_valid.drop(columns=delete_columns)
X_train = X_train[X_valid.columns]

# колонки в которых есть Nan
cols_with_missing = [col for col in X_train.columns
                     if X_train[col].isnull().any()]

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

for col in cols_with_missing:
    label_X_train[col + '_was_missing'] = label_X_train[col].isnull()
    label_X_valid[col + '_was_missing'] = label_X_valid[col].isnull()

# Импутация пропусков в числовых данных
imputed_X_train = pd.DataFrame(numeric_imputer.fit_transform(label_X_train.select_dtypes(include=['float64', 'int64'])), columns=label_X_train.select_dtypes(include=['float64', 'int64']).columns)
imputed_X_valid = pd.DataFrame(numeric_imputer.transform(label_X_valid.select_dtypes(include=['float64', 'int64'])), columns=label_X_valid.select_dtypes(include=['float64', 'int64']).columns)

# тренировка и предикт модели
house_model = RandomForestRegressor(n_estimators=130, random_state=0)
house_model.fit(imputed_X_train, y_train)
preds = house_model.predict(imputed_X_valid)

answer = pd.DataFrame({'Id': X_valid.index + 1461, 'SalePrice': preds})
answer.to_csv("sample_submission.csv", index=False)