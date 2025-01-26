#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;

string lower(string word)
{
    string line = "";
    for (int i = 0; word.size(); i++)
    {
        line += tolower(word[i]);
    }
    return line;
}

void ShakerSort(vector<int> &values)
{
    if (values.empty())
    {
        return;
    }
    int left = 0;
    int right = values.size() - 1;
    while (left <= right)
    {
        for (int i = right; i > left; --i)
        {
            if (tolower(values[i - 1]) > tolower(values[i]))
            {
                swap(values[i - 1], values[i]);
            }
        }
        ++left;
        for (int i = left; i < right; ++i)
        {
            if (tolower(values[i]) > tolower(values[i + 1]))
            {
                swap(values[i], values[i + 1]);
            }
        }
        --right;
    }
}

void first()
{
    double S, p, n, m, r;
    cout << "Введите S ";
    cin >> S;
    cout << "Введите p ";
    cin >> p;
    cout << "Введите n ";
    cin >> n;
    r = p / 100.;
    if (S > 0 && p > 0 && n > 0)
    {
        cout << "m == " << (S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1));
    }
    else if (S > 0 && p == 0 && n > 0)
    {
        cout << "m == " << S / (12 * n);
    }
    else
    {
        cout << "S, p, n должны быть больше 0!!!";
    }
}

void second()
{
    double S, n, m, r, start;
    cout << "Введите S ";
    cin >> S;
    cout << "Введите m ";
    cin >> m;
    cout << "Введите n ";
    cin >> n;
    start = 20;
    for (double p = start; true; p += start)
    {
        r = p / 100;
        if ((S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1)) == m)
        {
            cout << "p == " << p << endl;
            break;
        }
        else if ((S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1)) > m)
        {
            p -= start;
            start = start / 2.;
        }
    }
}

void third()
{
    string line;
    ofstream text("file number one.txt");
    text << "Питон лучше чем С++";
    text.close();
    ifstream text1("file number one.txt");
    if (text1.is_open())
    {
        while (getline(text1, line))
        {
            cout << line << endl;
        }
        cout << "Файл был успешно открыт и прочитан" << endl;
        text1.close();
    }
    else
    {
        cout << "Файл не открыт. Проверьте его название/его существование." << endl;
    }
}

int check(string line)
{
    string number = "";
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

void fourth()
{
    string line, number = "";
    ofstream data0("test.txt");
    cout << "Вводите свою мешанину" << endl;
    getline(cin, line);
    data0 << line;
    data0.close();
    ifstream data1("test.txt");
    if (data1.is_open())
    {
        while (getline(data1, line))
        {
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
                    if (number != "")
                    {
                        cout << number << " ";
                        number = "";
                    }
                }
            }
            if (check(number) == 1)
            {
                cout << number;
            }
        }
    }
    else
    {
        cout << "Файл не открыт. Проверьте его название/его существование." << endl;
    }
}

void fifth()
{
    string line;
    vector<int> data;
    cout << "Введите строку состоящую только из букв" << endl;
    cin >> line;
    for (int i = 0; i < line.size(); i++)
        data.push_back(int(line[i]));
    ShakerSort(data);
    for (int i = 0; i < data.size(); i++)
    {
        cout << char(data[i]);
    }
}

int main()
{
    // first();
    // second();
    // third();
    // fourth(); // сделал нужно сдать
    fifth(); // сделал нужно сдать
}