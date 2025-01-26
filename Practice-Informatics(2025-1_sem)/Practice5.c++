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
#include <unordered_map>
#include <algorithm>
#define _USE_MATH_DEFINES
using namespace std;

int number1_division(int first, int second)
{
    if (first == 0 || second == 0)
    {
        return -1;
    }
    while (max(first, second) % min(first, second) != 0)
    {
        if (first > second)
        {
            first = first % second;
        }
        else
        {
            second = second % first;
        }
    }
    return fabs(min(first, second));
}

int number1_subtraction(int first, int second)
{
    if (first <= 0 || second <= 0)
    {
        return -1;
    }
    while (max(first, second) - min(first, second) != 0)
    {
        if (first > second)
        {
            first = first - second;
        }
        else
        {
            second = second - first;
        }
    }
    return fabs(first);
}

void number1()
{
    int first, second;
    cout << "Введите большее число: ";
    cin >> first;
    cout << "Введите меньшее число: ";
    cin >> second;
    cout << "НОД вычисленный делением - " << number1_division(first, second) << endl;
    cout << "НОД вычисленный вычитанием - " << number1_subtraction(first, second) << endl;
}

void number2()
{
    int n, j, m = 2;
    int count = 0;
    cout << "Введите n: ";
    cin >> n;
    int *not_simple = new int[n];
    for (int i = 0; i <= n; i++)
    {
        not_simple[i] = i;
    }
    while (m < n)
    {
        if (not_simple[m] != 0)
        {
            j = pow(m, 2);
            while (j < n)
            {
                not_simple[j] = 0;
                j = j + m;
            }
        }
        m = m + 1;
    }
    for (int i = 0; i < n; i++)
    { /// подсчет кол-во простых чисел
        if (not_simple[i] != 0 && not_simple[i] != 1)
        {
            count += 1;
        }
    }
    int answer[count];
    int step = 0;
    for (int i = 0; i < n; i++) /// уборка 0 с помощью нового массива
    {
        if (not_simple[i] != 0 && not_simple[i] != 1)
        {
            answer[i - step] = not_simple[i];
        }
        else
        {
            step = step + 1;
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << answer[i] << endl;
    }

    delete[] not_simple;
}

void number3_20()
{
    string line;
    int mini_int = 10000;
    char mini_char;
    int *counter = new int[255];
    for (int i = 0; i < 255; i++)
    { // обнуляем список в котором ведется подсчет
        counter[i] = -1;
    }
    ofstream text("number3_20");
    cout << "Вводите свою мешанину(для того чтобы остановить ввод введите '1'): ";
    while (getline(cin, line))
    {
        if (line == "1")
        {
            break;
        }
        else
        {
            text << line;
        }
    }
    text.close();
    ifstream text1("number3_20");
    while (getline(text1, line))
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (counter[int(line[i])] == -1)
            {
                counter[int(line[i])] = 1;
            }
            else
            {
                counter[int(line[i])] += 1;
            }
        }
    }
    text1.close();
    for (int i = 0; i < 255; i++)
    {
        if (counter[i] > 0 && mini_int > counter[i])
        {
            mini_int = counter[i];
            mini_char = static_cast<char>(i);
        }
    }
    cout << "Наименее часто встречающийся символ - " << mini_char << " кол-во: " << mini_int;

    delete[] counter;
}

string lower(string word)
{
    string line = "";
    for (int i = 0; i < word.size(); i++)
    {
        line += tolower(word[i]);
    }
    return line;
}

void bubbleSort(string words[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (lower(words[j]) > lower(words[j + 1]))
            {
                swap(words[j], words[j + 1]);
            }
        }
    }
}

void number3_40()
{
    cout << "Вводите слова через пробел(чтобы остановить ввод введите '1')" << endl;
    ofstream text1("number3_40");
    int count = 0;
    string line, line_correct;
    while (getline(cin, line))
    {
        if (line == "1")
        {
            break;
        }
        else
        {
            text1 << line;
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] != ' ')
                {
                    continue;
                }
                else
                {
                    count += 1;
                }
            }
            count += 1;
        }
    }
    text1.close();
    string words[count];
    count = 0;
    ifstream text2("number3_40");
    while (getline(text2, line))
    {
        line_correct = "";
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] != ' ')
            {
                line_correct += line[i];
            }
            else
            {
                words[count] = line_correct;
                line_correct = "";
                count += 1;
            }
        }
        words[count] = line_correct;
    }
    bubbleSort(words, count);
    ofstream text3("number3_40");
    for (int i = 0; i <= words->size(); i++)
    {
        text3 << words[i] << endl;
    }
    text3.close();
}

int number5_20_chet_number(string number)
{
    for (int i = 0; i <= number.size(); i++)
    {
        if (static_cast<int>(number[i]) % 2 != 0)
        {
            return 1;
        }
    }
    return 0;
}

void number5_20()
{
    int count = 0;
    string line;
    cout << "Вводите сначало номер затем фамилию через пробел(Пример: 88005553535 Мошенники)" << endl;
    cout << "Каждый новый номер с новой строки (Чтобы остановить ввод введите '1')" << endl;
    ofstream text1("phone.txt");
    while (getline(cin, line))
    {
        if (line == "1")
        {
            break;
        }
        else
        {
            text1 << line << endl;
            count += 1;
        }
    }
    text1.close();
    ifstream text2("phone.txt");
    string number = "", second_name = "";
    bool check = true;
    string answer[count];  // правильные номера и фамилии через пробел
    string numbers[count]; // только номера для сортировки
    int count_1 = -1;
    while (getline(text2, line))
    {
        number = "";
        second_name = "";
        check = true;
        for (int i = 0; i < line.size(); i++)
        {
            if (check)
            {
                if (line[i] == ' ')
                {
                    if (number5_20_chet_number(number) == 0)
                    {
                        check = false;
                        count_1 += 1;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    number += line[i];
                }
            }
            else
            {
                second_name += line[i];
            }
        }
        if (check == false)
        {
            cout << "Телефон: " << number << " Фамилия: " << second_name << endl;
            answer[count_1] = number + " " + second_name;
            numbers[count_1] = number;
        }
    }
    text2.close();
    bubbleSort(numbers, count_1 + 1);
    ofstream text3("answer.txt");
    for (int k = 0; k < count; k++)
    {
        for (int j = 0; j < count; j++)
        {
            number = "";
            second_name = "";
            check = true;
            for (int i = 0; i < answer[j].size(); i++)
            {
                if (check)
                {
                    if (answer[j][i] == ' ')
                    {
                        if (number5_20_chet_number(number) == 0)
                        {
                            check = false;
                            count_1 += 1;
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        number += answer[j][i];
                    }
                }
                else
                {
                    second_name += answer[j][i];
                }
            }
            if (check == false && numbers[k] == number)
            {
                text3 << number + " " + second_name << endl;
            }
        }
    }
    text3.close();
}

int check_square(vector<vector<int>> all)
{
    for (int i = 0; i < all.size(); i++)
    {
        if (all[i].size() != all.size())
        {
            return 1;
        }
    }
    return 0;
}

int check_diagonal(vector<vector<int>> all)
{
    int left_to_right = 0, right_to_left = 0;
    for (int i = 0; i < all.size(); i++)
    {
        left_to_right += all[i][i];
    }
    for (int i = all.size() - 1; i >= 0; i--)
    {
        right_to_left += all[i][i];
    }
    if (left_to_right != right_to_left)
    {
        return 1;
    }
    return 0;
}

void number_5_54()
{
    vector<vector<int>> all;
    vector<int> column;
    string line, number;
    int current, correct = 0;
    cout << "Вводите построчно матрицу, между столбцами ставьте один пробел" << endl;
    cout << "Для того чтобы закончить ввод введите 1" << endl;
    while (getline(cin, line))
    {
        if (line != "1")
        {
            column.clear();
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == ' ')
                {
                    column.push_back(stoi(number));
                    number = "";
                    continue;
                }
                else
                {
                    number += line[i];
                }
            }
            column.push_back(stoi(number));
            all.push_back(column);
            number = "";
        }
        else
        {
            break;
        }
    }
    if (check_square(all) == 0)
    {
        for (int i = 0; i < all.size(); i++)
        {
            current = 0;
            for (int j = 0; j < all[i].size(); j++)
            {
                current += all[i][j];
            }
            if (correct == 0)
            {
                correct = current;
            }
            else if (correct != current)
            {
                cout << "Введенная матрица не 'магическая' ((" << endl;
                exit(0);
            }
        }
        if (check_diagonal(all) == 0)
        {
            cout << "Введенная матрица 'магическая'" << endl;
        }
    }
}

int main()
{
    while (true)
        number1();
    // number2();
    // number3_20();
    // number3_40();
    // number5_20();
    // number_5_54();
    return 0;
}