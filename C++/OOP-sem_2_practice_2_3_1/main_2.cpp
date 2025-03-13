#include "newClass.h"
#include "newUnion.h"
#include <iostream>

using namespace std;

int main() {
    newUnion obj_un;
    newClass obj_cl;
    string line;
    cin >> line;
    for (int i = 0; i < 4; i++) {
        obj_un.list[i] = line[i];
        obj_cl.list[i] = line[i];
    }
    int input_open;
    cin >> hex >> input_open;
    if (input_open != 0) {
        while (input_open != 0) {
        }
    }
    return 0;
}