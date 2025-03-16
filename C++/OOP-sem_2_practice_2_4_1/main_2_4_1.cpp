#include "newClass_2_4_1.cpp"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

void func_1(string line, newClass_2_4_1 &obj) {
    istringstream stream(line);
    int num;
    while (stream >> num) {
        if (num == 0 || obj.add(num) == false) {
            break;
        }
    }
}

int main() {
    int size;
    string name, line;

    // 1 СТЕК
    cin >> name >> size;
    newClass_2_4_1 obj(name, size);
    cout.setf(ios::left);
    cout << obj.get_name() << " " << obj.size << endl;
    cin.ignore();
    getline(cin, line);
    func_1(line, obj);

    // 2 СТЕК
    cin >> name >> size;
    newClass_2_4_1 obj_2(name, size);
    cout.setf(ios::left);
    cout << obj_2.get_name() << " " << obj_2.size << endl;
    cin.ignore();
    getline(cin, line);
    func_1(line, obj_2);

    cout.width(15);
    cout << obj.get_name();
    cout.width(15);
    cout << obj_2.get_name() << endl;
    ;

    while (obj.get_size() != 0) {
        cout.width(15);
        cout.setf(ios::right);
        cout << obj.remove();
        if (obj_2.get_size() != 0) {
            cout.width(15);
            cout.setf(ios::right);
            cout << obj_2.remove() << endl;
            continue;
        }
        break;
    }
    return 0;
}