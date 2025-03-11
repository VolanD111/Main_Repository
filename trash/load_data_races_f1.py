import fastf1
import firebase_admin
from firebase_admin import credentials, firestore
import pandas as pd
import numpy as np


cred = credentials.Certificate("C:\\vscode\\trash\\formula1-a36bb-firebase-adminsdk-fbsvc-aa4b53a2b7.json")
firebase_admin.initialize_app(cred)
db = firestore.client()
collection_ref = db.collection("date_races")
df = fastf1.get_event_schedule(2025)
df = df.replace({np.nan: None})
for index, row in df.iterrows():
    # 🔹 Генерируем ключ документа (если нет Country, используем индекс)
    country = str(row["Country"]) if pd.notna(row["Country"]) else f"race_{index}"

    # 🔹 Конвертируем данные в стандартные типы Python (чтобы Firestore их принял)
    race_data = row.to_dict()
    
    # 🔹 Преобразуем numpy-значения в стандартные Python-типы
    for key, value in race_data.items():
        if isinstance(value, np.integer):
            race_data[key] = int(value)
        elif isinstance(value, np.floating):
            race_data[key] = float(value)
        elif isinstance(value, pd.Timestamp):  # Если есть Timestamp, конвертируем в строку
            race_data[key] = value.strftime("%Y-%m-%d %H:%M:%S")

    # 🔹 Загружаем данные в Firestore
    doc_ref = collection_ref.document(country)