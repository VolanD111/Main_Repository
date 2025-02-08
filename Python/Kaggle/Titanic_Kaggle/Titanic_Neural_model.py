from tensorflow import keras
from keras import layers
import numpy as np
import pandas as pd

# Чтение файлов
data_titanic_train = pd.read_csv("C:\Practice-Informatics\Python\Titanic_Kaggle\\train.csv")
data_titanic_test = pd.read_csv("C:\Practice-Informatics\Python\Titanic_Kaggle\\test.csv")

# Разделение данных на две обучающие выборки
df_train_1 = data_titanic_train.sample(frac=0.7, random_state=0)
df_train_2 = data_titanic_train.drop(df_train_1.index)


# Scale to [0, 1]
max_ = df_train_1.max(axis=0)
min_ = df_train_1.min(axis=0)
df_train_1 = (df_train_1 - min_) / (max_ - min_)
df_train_2 = (df_train_2 - min_) / (max_ - min_)
df_test = (data_titanic_test - min_) / (max_ - min_)


# Определение целевой переменной и признаков
X_train_1 = df_train_1.drop(columns='Survived')
y_train_1 = df_train_1.Survived

X_train_2 = df_train_2.drop(columns='Survived')
y_train_2 = df_train_2.Survived

X_test = df_test.drop(columns='Survived')
y_test = df_test.Survived


model = keras.Sequential([
    layers.Dense(128, activation='relu', input_shape=[len(X_train_1.keys())]),
    layers.Dense(64, activation='relu'),
    layers.Dense(1, activation='sigmoid')
])

model.compile(
    optimizer='adam',
    loss='mae'
)

model.fit(
    X_train_1, y_train_1,
    validation_data=(X_train_2, y_train_2),
    batch_size=256,
    epochs=10,
)

preds = model.predict(X_test)

answer = pd.DataFrame({'PassengerId': data_titanic_test.PassengerId, 'Survived': np.round(preds).astype(int)})
answer.to_csv("Titanic_neural.csv", index=False)