import pandas as pd
import numpy as np

# Пример DataFrame
data = {
    'A': [1, 2, 3, np.nan],
    'B': ['a', 'b', 'c', np.nan],
    'C': [4.5, 5.5, np.nan, 7.5],
    'E': [10, 20, 30, 40],
    "F": ["a", "b", "c", "d"]
}
df = pd.DataFrame(data)

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

print(delete_columns)
