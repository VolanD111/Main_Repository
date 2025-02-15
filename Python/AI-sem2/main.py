import numpy as np

answer = np.arange(25).reshape(5,5)
for i in range(len(answer)):
    for j in range(len(answer[i])):
        if i == 0 or i == len(answer):
            answer[i][j] = 1
        elif j == 0 or j == len(answer[i]):
            answer[i][j] = 1
        else:
            answer[i][j] = 0
print(answer)