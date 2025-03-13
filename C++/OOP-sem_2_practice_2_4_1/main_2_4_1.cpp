#include "newClass_2_4_1.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void func_1(string line, newClass_2_4_1 &obj)
{
    istringstream stream(line);
    int num;
    while (stream >> num) // Читаем числа из строки
    {
        if (num == 0 || obj.add(num) == false) // Если число 0 или не удалось добавить — выход
        {
            break;
        }
    }
}

int main()
{
 int size;
    string name, line;

    // ПЕРВЫЙ СТЕК
    cin >> name >> size;
    newClass_2_4_1 obj(name, size);
    cout.width(15);
    cout.setf(ios::left);
    cout << obj.get_name() << " " << obj.get_size() << endl;
    cin.ignore();
    getline(cin, line);
    func_1(line, obj);

    // ВТОРОЙ СТЕК
    cin >> name >> size;
    newClass_2_4_1 obj_2(name, size);
    cout.width(15);
    cout.setf(ios::left);
    cout << obj_2.get_name() << " " << obj_2.get_size() << endl;
    cin.ignore();
    getline(cin, line);
    func_1(line, obj_2);

    cout << obj.get_name() << "\t" << obj_2.get_name() << endl;

    // СРАВНЕНИЕ СТЕКОВ
    while (obj.get_size() != 0 && obj_2.get_size() != 0)
    {
        cout.width(15);
        cout.setf(ios::right);
        cout << obj.remove() << "\t" << "[" << obj_2.remove() << "]" << endl;
    }
    return 0;
}