#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <bits/stdc++.h>
#include <map>
#include <windows.h>
#include <wingdi.h>
#include <cstdlib>
#define _USE_MATH_DEFINES
using namespace std;

int check_number(string line)
{
    string number;
    for (int i = 0; i < line.size(); i++)
    {
        if (isdigit(line[i]) == 1 | (line[i] == '.' && (i + 1) < line.size() && isdigit(line[i + 1]) == 1))
        {
            number += line[i];
        }
        else if (number == "" and line[i] == '-')
        {
            number += '-';
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

void first()
{
    string line, number = "";
    double summa = 0;
    ofstream text("summa.txt");
    cout << "Вводите числа: " << endl;
    getline(cin, line);
    if (line.find(" ") != string::npos)
    {
        text << line;
    }
    else
    {
        text << line << endl;
        for (int i = 0; i < 9; i++)
        {
            cin >> line;
            if (check_number(line) == 1)
            {
                text << line << endl;
            }
            else
            {
                cout << "ВВОДИТЬ НАДО ЧИСЛА";
                exit(0);
            }
        }
    }
    text.close();
    ifstream text1("summa.txt");
    while (getline(text1, line))
    {
        if (line.find(" ") != string::npos)
        {
            for (int j = 0; j < line.size(); j++)
            {
                if (line[j] == ' ')
                {
                    if (check_number(number) == 1)
                    {
                        summa += stod(number);
                        number = "";
                    }
                    else
                    {
                        cout << "ВВОДИТЬ НАДО ЧИСЛА ПО-РУССКИ НАПИСАЛ ЖЕ";
                        exit(0);
                    }
                }
                else
                {
                    number.append(1, line[j]);
                }
            }
            summa += stod(number);
        }
        else
        {
            summa += stod(line);
        }
    }
    cout << summa << endl;
}

int sign(double a)
{
    if (a > 0)
    {
        return 1;
    }
    else if (a == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void second()
{
    double a;
    cout << "Введите число: ";
    cin >> a;
    switch (sign(a))
    {
    case 1:
        cout << "Число положительное";
        break;
    case 0:
        cout << "Число равно 0";
        break;
    case -1:
        cout << "Число положительное";
        break;
    default:
        break;
    };
}

double circle(double R)
{
    if (R > 0)
        return M_PI * pow(R, 2);
    return 0.0;
}

double rectangle(double a, double b)
{
    if (a > 0 && b > 0)
        return a * b;
    return 0.0;
}

bool check_triangle(double a, double b, double c)
{
    if (max(max(a, b), c) < min(min(a, b), c) + (a + b + c) - max(max(a, b), c) && a > 0 && b > 0 && c > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

double triangle_3(double a, double b, double c)
{
    double p;
    if (check_triangle(b, c, a) > 0)
    {
        p = (b + c + a) / 2.;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    return 0.0;
}

void third()
{
    int input;
    double R, l, k;
    cout << "Для вычисления площади геом фигур введите цифры: " << endl;
    cout << "1 - для вычиления S треугольника" << endl;
    cout << "2 - для вычиления S прямоугольника" << endl;
    cout << "3 - для вычиления S круга" << endl;
    cin >> input;
    switch (input)
    {
    case 1:
        cout << "Введите 1 сторону: ";
        cin >> R;
        cout << "Введите 2 сторону: ";
        cin >> l;
        cout << "Введите 3 сторону: ";
        cin >> k;
        if (triangle_3(R, l, k) > 0)
            cout << triangle_3(R, l, k) << endl;
        else
            cout << "Невозмножно вычислить" << endl;
        break;
    case 2:
        cout << "Вычисление S прямоугольника" << endl;
        cout << "Введите 1 сторону: ";
        cin >> l;
        cout << "Введите 2 сторону: ";
        cin >> k;
        if (rectangle(l, k) > 0)
            cout << rectangle(l, k) << endl;
        else
            cout << "Стороны должны быть положительными" << endl;
        break;
    case 3:
        cout << "Вычисление S круга" << endl;
        cout << "Для этого введите радиус" << endl;
        cin >> R;
        if (circle(R) > 0)
            cout << circle(R) << endl;
        else
            cout << "Радиус должен быть положительным" << endl;
        break;
    default:
        break;
    }
}

void forth()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    bool check = true;
    for (int i = 0; i < 13; i++)
    {
        if (i < 4)
        {
            for (int j = 0; j < 12; j++)
            {
                SetConsoleTextAttribute(h, 0x115);
                cout << "*";
            }
            if (check)
            {
                check = false;
                for (int k = 0; k < 25; k++)
                {
                    SetConsoleTextAttribute(h, 0x40);
                    cout << " ";
                }
                SetConsoleTextAttribute(h, 0x00);
                cout << endl;
            }
            else
            {
                check = true;
                for (int k = 0; k < 25; k++)
                {
                    SetConsoleTextAttribute(h, 0x70);
                    cout << " ";
                }
                SetConsoleTextAttribute(h, 0x00);
                cout << endl;
            }
        }
        else
        {
            if (check)
            {
                check = false;
                for (int k = 0; k < 37; k++)
                {
                    SetConsoleTextAttribute(h, 0x40);
                    cout << " ";
                }
                SetConsoleTextAttribute(h, 0x00);
                cout << endl;
            }
            else
            {
                check = true;
                for (int k = 0; k < 37; k++)
                {
                    SetConsoleTextAttribute(h, 0x70);
                    cout << " ";
                }
                SetConsoleTextAttribute(h, 0x00);
                cout << endl;
            }
        }
    }
}

bool is_roman(string s)
{
    string l = "IVXLCDM";
    int a[7] = {0}; // подсчет различных символов в строке
    string s1 = "";
    // проверка на существование символа римского числа
    for (char h : s)
    {
        if (l.find(h) == string::npos)
            return false;
        s1 += l.find(h);
    }
    for (int i = 0; i < s1.size(); i++)
    {
        int u = s1[i];
        a[u] += 1;
        // проверка на наличие максимум 3 символов
        if (u < 6 and a[u] >= 4)
            return false;
        if (u % 2 == 1 and a[u] >= 2)
            return false;
        if (i > 0 and i + 1 < s1.size())
        {
            if (s1[i - 1] == s1[i + 1] and s[i - 1] < s[i])
                return false;
        }
    }

    return true;
}

void sixth()
{
    cout << "Вводите число в римской системе: ";
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > 'Z')
            s[i] = s[i] - 'a' + 'A';
    }
    if (!is_roman(s))
    {
        cout << "Неправильно";
        return;
    }
    int result = 0;
    string l = "IVXLCDM";
    short just = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        short u = l.find(s[i]);
        if (u >= just)
        {
            result += pow(10, u / 2) * (1 + 4 * (u % 2));
            just = u;
        }
        else
            result -= pow(10, u / 2) * (1 + 4 * (u % 2));
    }
    cout << result << endl;
}

void eighth()
{
    double sum = 0;
    int counts[3][4] = {{5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0}};
    double answer[3][2] = {};
    double answer_1_max = 0, answer_1_min = 100000, answer_2_max = 0, answer_2_min = 1000, answer_3 = 0, answer_4 = 0, answer_5 = 0;
    double commission[4][2] = {{1.2, 0.5}, {2.8, 0.4}, {5, 1}, {2, 1.5}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum = counts[i][0] * commission[0][j] + counts[i][1] * commission[1][j] + counts[i][2] * commission[2][j] + counts[i][3] * commission[3][j];
            answer[i][j] = sum;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (answer[i][0] > answer_1_max)
        {
            answer_1_max = answer[i][0];
        }
        if (answer[i][0] < answer_1_min)
        {
            answer_1_min = answer[i][0];
        }
        if (answer[i][1] > answer_2_max)
        {
            answer_2_max = answer[i][1];
        }
        if (answer_2_min > answer[i][1])
        {
            answer_2_min = answer[i][1];
        }
        answer_3 += answer[i][0];
        answer_4 += answer[i][1];
        answer_5 += answer[i][0] += answer[i][1];
    }
    cout << "Ответ на 1 вопрос: макс 2 продавец - " << answer_1_max << " и мин 3 продавец - " << answer_1_min << endl;
    cout << "Ответ на 2 вопрос: макс 1 продавец - " << answer_2_max << " и мин 3 продавец - " << answer_2_min << endl;
    cout << "Ответ на 3 вопрос: " << answer_3 << endl;
    cout << "Ответ на 4 вопрос: " << answer_4 << endl;
    cout << "Ответ на 5 вопрос: " << answer_5 << endl;
}

int main()
{
    while (true)
        // first(); // сделал сдать / сдал
        // second(); // сделал сдать / сдал
        // third(); // сделал сдать / сдал
        // forth(); // сдать  сдать / сдал
        // fifth();
        sixth(); // сделал сдать /
    // seventh(); // сделал сдать / сдал
    // eighth(); // сделал сдать / сдал
}