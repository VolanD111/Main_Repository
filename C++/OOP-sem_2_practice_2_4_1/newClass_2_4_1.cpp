#include "newClass_2_4_1.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

newClass_2_4_1::newClass_2_4_1(string name, int size) {
    this->name = name;
    this->size = size;
}

bool newClass_2_4_1::add(int value) {
    if (numbers.size() == size) {
        return false;
    } else {
        numbers.push_back(value);
        return true;
    }
}

int newClass_2_4_1::remove() {
    if (numbers.empty()) {
        return 0;
    } else {
        int last = numbers.back();
        numbers.pop_back();
        return last;
    }
}

int newClass_2_4_1::get_size() { return numbers.size(); }

string newClass_2_4_1::get_name() { return name; }