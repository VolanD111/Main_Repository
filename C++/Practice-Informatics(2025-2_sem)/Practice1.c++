#include <iostream>
#include <string>

using namespace std;

class Simple
{
private:
    long long n;

public:
    // Конструктор по умолчанию
    Simple() : n(0) {}

    // Метод для задания значения n
    void setValue(long long value)
    {
        n = value;
    }

    // Метод для вычисления количества цифр в числе
    int countDigits() const
    {
        return to_string(abs(n)).length();
    }

    // Метод для получения значения n
    long long getValue() const
    {
        return n;
    }
};

int main()
{
    Simple obj;
    long long userInput;

    cout << "Введите число: ";
    cin >> userInput;

    obj.setValue(userInput);

    cout << "Значение свойства n: " << obj.getValue() << endl;
    cout << "Количество цифр: " << obj.countDigits() << endl;

    return 0;
}
