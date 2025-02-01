import pandas as pd

answer = pd.read_csv("C:\Practice-Informatics\sample_submission.csv")
correct = pd.DataFrame({'PassengerId': answer.PassengerId, 'Survived': round(answer.Survived, 0).astype(int)})
correct.to_csv("C:\Practice-Informatics\correct.csv", index=False)