import math

def calculator(x, y, operation):
    if operation == '+':
        return x + y
    elif operation == '-':
        return x - y
    elif operation == '*':
        return x * y
    elif operation == '/':
        if y == 0:
            return 'Делить на 0 нельзя'
        return x / y
    elif operation == 'exp':
        return math.exp(x + y)
    elif operation == 'sin':
        return math.sin(x + y)
    elif operation == 'cos':
        return math.cos(x + y)
    elif operation == 'pow':
        return x ** y
    else:
        return 'Такой операции нет'

x = float(input('Введите x: '))
y = float(input('Введите y: '))
operation = input('Введите операцию (+, -, *, /, exp, sin, cos, pow): ')

result = calculator(x, y, operation)
print("Результат:", result)
