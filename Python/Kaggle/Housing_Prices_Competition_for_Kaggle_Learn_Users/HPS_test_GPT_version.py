import pandas as pd
import numpy as np
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import OneHotEncoder
from xgboost import XGBRegressor
from sklearn.model_selection import RandomizedSearchCV

# Чтение файлов
houses_data_train = pd.read_csv("C:\\vscode\Python\Housing_Prices_Competition_for_Kaggle_Learn_Users\\train.csv")
houses_data_valid = pd.read_csv("C:\\vscode\Python\Housing_Prices_Competition_for_Kaggle_Learn_Users\\test.csv")

# Определение целевой переменной и признаков
y_train = houses_data_train.SalePrice
X_train = houses_data_train.drop(columns='SalePrice')
X_valid = houses_data_valid.copy()

# Определение категориальных признаков
object_cols = X_train.select_dtypes(include=["object"]).columns.tolist()

# Применение One-Hot Encoding
ordinal_encoder = OneHotEncoder(handle_unknown='ignore', sparse_output=False)
label_X_train = pd.DataFrame(ordinal_encoder.fit_transform(X_train[object_cols]), columns=ordinal_encoder.get_feature_names_out(object_cols))
label_X_valid = pd.DataFrame(ordinal_encoder.transform(X_valid[object_cols]), columns=ordinal_encoder.get_feature_names_out(object_cols))

# Удаление категориальных колонок из оригинальных данных
num_X_train = X_train.drop(columns=object_cols)
num_X_valid = X_valid.drop(columns=object_cols)

# Объединение числовых и закодированных категориальных признаков
OH_X_train = pd.concat([num_X_train.reset_index(drop=True), label_X_train.reset_index(drop=True)], axis=1)
OH_X_valid = pd.concat([num_X_valid.reset_index(drop=True), label_X_valid.reset_index(drop=True)], axis=1)

# Импутация пропусков в числовых данных
numeric_imputer = SimpleImputer(strategy='mean')
imputed_X_train = pd.DataFrame(numeric_imputer.fit_transform(OH_X_train.select_dtypes(include=['float64', 'int64'])), columns=OH_X_train.select_dtypes(include=['float64', 'int64']).columns)
imputed_X_valid = pd.DataFrame(numeric_imputer.transform(OH_X_valid.select_dtypes(include=['float64', 'int64'])), columns=OH_X_valid.select_dtypes(include=['float64', 'int64']).columns)

# Объединение импутированных данных с остальными колонками
OH_X_train = pd.concat([imputed_X_train, OH_X_train.drop(columns=OH_X_train.select_dtypes(include=['float64', 'int64']).columns)], axis=1)
OH_X_valid = pd.concat([imputed_X_valid, OH_X_valid.drop(columns=OH_X_valid.select_dtypes(include=['float64', 'int64']).columns)], axis=1)

# Добавление синтетических признаков
OH_X_train['TotalSF'] = OH_X_train['TotalBsmtSF'] + OH_X_train['1stFlrSF'] + OH_X_train['2ndFlrSF']
OH_X_valid['TotalSF'] = OH_X_valid['TotalBsmtSF'] + OH_X_valid['1stFlrSF'] + OH_X_valid['2ndFlrSF']

# Поиск по сетке для гиперпараметров
param_distributions = {
    'n_estimators': [100, 200, 500, 1000, 1500, 2000],
    'learning_rate': [0.01, 0.05, 0.1],
    'max_depth': [3, 5, 7],
    'subsample': [0.6, 0.8, 1.0],
    'colsample_bytree': [0.6, 0.8, 1.0]
}

xgb_model = XGBRegressor(n_jobs=5)
random_search = RandomizedSearchCV(xgb_model, param_distributions, n_iter=50, scoring='neg_mean_squared_error', cv=3)
random_search.fit(OH_X_train, y_train)

# Лучшая модель
best_model = random_search.best_estimator_

# Предсказание
preds = best_model.predict(OH_X_valid)

# Сохранение результатов
answer = pd.DataFrame({'Id': houses_data_valid.Id, 'SalePrice': preds})
answer.to_csv("sample_submission.csv", index=False)
