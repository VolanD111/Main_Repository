import pandas as pd

# Пример данных
data = {'A': [1, 2, 3], 'B': [4, 5, 6]}
df = pd.DataFrame(data)
print(df)

# Используем iloc для доступа по позициям
print(df.iloc[1])  # Доступ по позиции строки
print(df.iloc[1, 1])  # Доступ по позиции строки и позиции столбца