#include "Simple.h"
using namespace std;

void Simple::number_1(int newValue)
{
    open = newValue;
    closed = newValue * 2;
}

void Simple::plus()
{
    open = open + 1;
    closed = closed + 4;
}

void Simple::call_closed()
{
    invisible();
}

void Simple::invisible()
{
    open = open + 4;
    closed = closed + 8;
}

void Simple::getter()
{
    cout << "Value of the available property " << open << "; Value of a hidden property " << closed << endl;
}