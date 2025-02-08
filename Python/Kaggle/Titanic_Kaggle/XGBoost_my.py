import pandas as pd
import numpy as np
from xgboost import XGBRegressor
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import OneHotEncoder
from sklearn.model_selection import RandomizedSearchCV
import optuna

#  0.94516116


# Чтение файлов
data_titanic_train = pd.read_csv("C:\Practice-Informatics\Python\Titanic_Kaggle\\train.csv")
data_titanic_test = pd.read_csv("C:\Practice-Informatics\Python\Titanic_Kaggle\\test.csv")

# Определение целевой переменной и признаков
y_train = data_titanic_train.Survived

X_train = data_titanic_train.drop(columns='Survived')
X_test = data_titanic_test.copy()
X_train = X_train.drop(columns='Embarked')
X_test = X_test.drop(columns='Embarked')
X_train = X_train.drop(columns='Name')
X_test = X_test.drop(columns='Name')
X_train = X_train.drop(columns='Fare')
X_test = X_test.drop(columns='Fare')
X_train = X_train.drop(columns='SibSp')
X_test = X_test.drop(columns='SibSp')


# Определение категориальных признаков
object_cols = X_train.select_dtypes(include=["object"]).columns.tolist()

# Применение One-Hot Encoding
ordinal_encoder = OneHotEncoder(handle_unknown='ignore', sparse_output=False)
label_X_train = pd.DataFrame(ordinal_encoder.fit_transform(X_train[object_cols]), columns=ordinal_encoder.get_feature_names_out(object_cols))
label_X_test = pd.DataFrame(ordinal_encoder.transform(X_test[object_cols]), columns=ordinal_encoder.get_feature_names_out(object_cols))

# Удаление категориальных колонок из оригинальных данных
num_X_train = X_train.drop(columns=object_cols)
num_X_test = X_test.drop(columns=object_cols)

# Объединение числовых и закодированных категориальных признаков
OH_X_train = pd.concat([num_X_train.reset_index(drop=True), label_X_train.reset_index(drop=True)], axis=1)
OH_X_test = pd.concat([num_X_test.reset_index(drop=True), label_X_test.reset_index(drop=True)], axis=1)

# Импутация пропусков в числовых данных
numeric_imputer = SimpleImputer(strategy='median')
imputed_X_train = pd.DataFrame(numeric_imputer.fit_transform(OH_X_train.select_dtypes(include=['float64', 'int64'])), columns=OH_X_train.select_dtypes(include=['float64', 'int64']).columns)
imputed_X_test = pd.DataFrame(numeric_imputer.transform(OH_X_test.select_dtypes(include=['float64', 'int64'])), columns=OH_X_test.select_dtypes(include=['float64', 'int64']).columns)

# Объединение импутированных данных с остальными колонками
OH_X_train = pd.concat([imputed_X_train, OH_X_train.drop(columns=OH_X_train.select_dtypes(include=['float64', 'int64']).columns)], axis=1)
OH_X_valid = pd.concat([imputed_X_test, OH_X_test.drop(columns=OH_X_test.select_dtypes(include=['float64', 'int64']).columns)], axis=1)

def objective(trial):
    param = {
        'objective': 'reg:squarederror',
        'n_estimators': trial.suggest_int('n_estimators', 100, 1000),
        'max_depth': trial.suggest_int('max_depth', 3, 10),
        'learning_rate': trial.suggest_float('learning_rate', 0.01, 0.3),
        'subsample': trial.suggest_float('subsample', 0.5, 1.0),
        'colsample_bytree': trial.suggest_float('colsample_bytree', 0.5, 1.0),
        'gamma': trial.suggest_float('gamma', 0.0, 5.0),
    }
    model = XGBRegressor(**param)
    model.fit(OH_X_train, y_train)
    return model.score(OH_X_train, y_train)

# Настройка и запуск оптимизации
study = optuna.create_study(direction='maximize')
study.optimize(objective, n_trials=300)

# Предсказания на валидационной выборке
best_model = XGBRegressor(**study.best_params)
best_model.fit(OH_X_train, y_train)
preds = best_model.predict(OH_X_valid)

# Сохранение результатов
answer = pd.DataFrame({'PassengerId': data_titanic_test.PassengerId, 'Survived': np.round(preds).astype(int)})
answer.to_csv("Titanic.csv", index=False)