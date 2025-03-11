#include <iostream>
#include "newClass.h"
#include "newUnion.h"
using namespace std;

int main()
{
    newUnion obj_un;
    newClass obj_cl;
    string line;
    cin >> line;
    for (int i = 0; i < 4; i++)
    {
        obj_un.list[i] = line[i];
        obj_cl.list[i] = line[i];
    }
    int input_open;
    cin >> hex >> input_open;
    while (input_open != 0)
    {
        if (input_open == 19533)
        {
            int input_closed;
            cin >> hex >> input_closed;
            if (input_closed == 19533)
            {
            }
            else // УДОВЛЕТВОРЯЮЩЕЕ МНОЖЕСТВО ЭТО ЧИСЛА КОТОРЫЕ МОЖНО ПЕРЕВЕСТИ ИЗ ASCII НОРМАЛЬНО ПО ЭТОЙ 16-РИЧНОЙ ХРЕНИ
            {
                cout << "Data of the short type is incorrect: " << hex << input_closed << endl;
            }
        }
        else
        {
            cout << "Data of the int type is incorrect: " << hex << input_open << endl;
        }
    }

    return 0;
}