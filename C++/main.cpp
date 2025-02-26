#include <stdlib.h>
#include <stdio.h>
#include "Simple.h"
#include <iostream>
using namespace std;

int main()
{
    int i_data;
    cin >> i_data;
    Simple obj;
    obj.number_1(i_data);
    obj.getter();
    obj.plus();
    obj.getter();
    cin >> i_data;
    obj.open = obj.open * i_data;
    obj.getter();
    obj.call_closed();
    obj.getter();
    return (0);
}
