#ifndef __NEWCLASS_2_4_1__H
#define __NEWCLASS_2_4_1__H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class newClass_2_4_1
{
private:
    vector<int> numbers;
    string name;

public:
    int size;
    newClass_2_4_1(string name, int size); // Объявление конструктора
    bool add(int value);
    int remove();
    string get_name();
    int get_size();
};
#endif