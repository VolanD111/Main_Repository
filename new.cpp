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

// int check_correct(string number)
// {
//     map<char, int> symbols = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
//     map<char, int> check = {{'I', 0}, {'V', 0}, {'X', 0}, {'L', 0}, {'C', 0}, {'D', 0}, {'M', 0}};
//     char checking[3] = {'L', 'V', 'D'};
//     int count_last = 0;
//     char last;
//     for (int i = 0; i < number.size(); i++)
//     {
//         if (symbols.count(number[i]) == 0)
//         {
//             return 0;
//         }
//         if (number[i] == last)
//         {
//             count_last += 1;
//             if (count_last > 3)
//             {
//                 return 0;
//             }
//         }
//         else
//         {
//             if (i == 0)
//             {
//                 last = number[i];
//                 count_last += 1;
//             }
//             else
//             {
//                 last = number[i];
//                 count_last = 1;
//             }
//         }
//     }
//     bool checks = false;
//     for (int i = 0; i < number.size(); i++)
//     {
//         if (i >= 1)
//         {
//             if (i == 1 && (symbols[number[i - 1]] < symbols[number[i]] && (number.substr(i - 1, 2) == "IX" | number.substr(i - 1, 2) == "IV" | number.substr(i - 1, 2) == "XL" | number.substr(i - 1, 2) == "XC" | number.substr(i - 1, 2) == "CD" | number.substr(i - 1, 2) == "CM")))
//             {
//                 return 1;
//             }
//             else if (not checks && i >= 2 && (symbols[number[i - 2]] >= symbols[number[i]]) && (symbols[number[i - 1]] < symbols[number[i]] && (number.substr(i - 1, 2) == "IX" | number.substr(i - 1, 2) == "IV" | number.substr(i - 1, 2) == "XL" | number.substr(i - 1, 2) == "XC" | number.substr(i - 1, 2) == "CD" | number.substr(i - 1, 2) == "CM")))
//             {
//                 checks = true;
//                 return 1;
//             }
//             else if (symbols[number[i - 1]] >= symbols[number[i]])
//             {
//                 continue;
//             }
//             else
//             {
//                 return 0;
//             }
//         }
//     }
//     for (int i = 0; i < number.size(); i++)
//     {
//         check[number[i]] += 1;
//         if ((number[i] == 'V' || number[i] == 'L' || number[i] == 'D') && check[number[i]] > 1)
//         {
//             return 0;
//         }
//     }
//     if (number.find("XCX") == npos())
//     {
//         cout << "Вы ввели неправильное число" << endl;
//         return 0;
//     }
//     return 1;
// }

// void sixth()
// {
//     map<char, int> slovar = {{'I', 1}, {'X', 10}, {'V', 5}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
//     string line;
//     bool check = true;
//     int number = 0, count_I = 0; // 5 50 500 должны встречаться один раз в числе
//     cout << "Вводите число в римской записи: ";
//     cin >> line;
//     if (check_correct(line))
//     {
//         for (int i = 0; i < line.size(); i++)
//         {
//             if (i > 0 && slovar[line[i - 1]] >= slovar[line[i]])
//             {
//                 number += slovar[line[i]];
//                 if (line[i] == 'I')
//                 {
//                     count_I += 1;
//                 }
//                 else
//                 {
//                     count_I = 0;
//                 }
//             }
//             else if (i == 0)
//             {
//                 number += slovar[line[i]];
//                 if (line[i] == 'I')
//                 {
//                     count_I += 1;
//                 }
//                 else
//                 {
//                     count_I = 0;
//                 }
//             }
//             else if (line.substr(i - 1, 2) == "IX")
//             {
//                 number += 8;
//                 count_I = 0;
//             }
//             else if (line.substr(i - 1, 2) == "IV")
//             {
//                 number += 3;
//                 count_I = 0;
//             }
//             else if (line.substr(i - 1, 2) == "XL")
//             {
//                 number += 30;
//                 count_I = 0;
//             }
//             else if (line.substr(i - 1, 2) == "XC")
//             {
//                 number += 80;
//                 count_I = 0;
//             }
//             else if (line.substr(i - 1, 2) == "CD")
//             {
//                 number += 300;
//                 count_I = 0;
//             }
//             else if (line.substr(i - 1, 2) == "CM")
//             {
//                 number += 800;
//                 count_I = 0;
//             }
//             else
//             {
//                 cout << "Вы ввели неправильное число" << endl;
//                 check = false;
//                 break;
//             }
//         }
//         if (check)
//         {
//             cout << number << endl;
//         }
//     }
//     else
//     {
//         cout << "Вы ввели неправильное число" << endl;
//     }
// }

void check()
{
    string arr[] = {"Hello", "World", "C++", "Programming"};
    int size = sizeof(arr) / sizeof(arr[0]); // Определяем размер массива

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}

int main()
{
    check();
}