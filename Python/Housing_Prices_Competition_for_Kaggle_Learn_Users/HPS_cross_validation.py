import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.metrics import mean_squared_error
from sklearn.ensemble import RandomForestRegressor
from sklearn.preprocessing import OrdinalEncoder
from sklearn.impute import SimpleImputer


houses_data_train = pd.read_csv("C:\\vscode\Python\Housing_Prices_Competition_for_Kaggle_Learn_Users\\train.csv")
houses_data_valid = pd.read_csv("C:\\vscode\Python\Housing_Prices_Competition_for_Kaggle_Learn_Users\\test.csv")

# выбрали что ищем и что идет в дерево
y_train = houses_data_train.SalePrice
X_train = houses_data_train[houses_data_train.columns]
X_valid = houses_data_valid[houses_data_valid.columns]

X_valid = X_valid.dropna(axis=1)
X_train = X_train[X_valid.columns]

# Разделение данных на обучающую и тестовую выборки
X_train, X_test, y_train, y_test = train_test_split(X_train, y_train, test_size=0.6, random_state=42)


# отбор колонок в которых лежат строчки
s = (X_train.dtypes == "object")
object_cols = list(s[s].index)

# преобразование колонок со строчками во что-то другое
label_X_train = X_train.copy()
label_X_valid = X_valid.copy()
label_X_test = X_test.copy()
ordinal_encoder = OrdinalEncoder()
label_X_train[object_cols] = ordinal_encoder.fit_transform(X_train[object_cols])
label_X_valid[object_cols] = ordinal_encoder.transform(X_valid[object_cols])
label_X_test[object_cols] = ordinal_encoder.transform(X_test[object_cols])


# вствка среднего значения по колонке в места где Nan
numeric_imputer = SimpleImputer(strategy='mean')

# Импутация пропусков в числовых данных
imputed_X_train = pd.DataFrame(numeric_imputer.fit_transform(X_train.select_dtypes(include=['float64', 'int64'])), columns=X_train.select_dtypes(include=['float64', 'int64']).columns)
imputed_X_valid = pd.DataFrame(numeric_imputer.transform(X_valid.select_dtypes(include=['float64', 'int64'])), columns=X_valid.select_dtypes(include=['float64', 'int64']).columns)
imputed_X_test = pd.DataFrame(numeric_imputer.transform(X_test.select_dtypes(include=['float64', 'int64'])), columns=X_test.select_dtypes(include=['float64', 'int64']).columns)
model = RandomForestRegressor(n_estimators=100, random_state=42)

# Выполняем кросс-валидацию
cv_scores = cross_val_score(model, label_X_train, y_train, cv=5, scoring='neg_mean_squared_error')

# Поскольку cross_val_score возвращает отрицательные значения MSE, мы берем их абсолютные значения
mse_scores = -cv_scores

# Выводим результаты кросс-валидации
print("Mean Squared Error для каждого фолда:", mse_scores)
print("Среднее значение MSE:", np.mean(mse_scores))

# Обучаем модель на всей обучающей выборке
model.fit(label_X_train, y_train)

# Предсказываем на тестовой выборке
y_pred = model.predict(label_X_test)

# Оцениваем модель на тестовых данных
test_mse = mean_squared_error(y_test, y_pred)
print("Mean Squared Error на тестовой выборке:", test_mse)