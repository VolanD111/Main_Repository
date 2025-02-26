#ifndef SIMPLE_H
#define SIMPLE_H

#include <iostream>

class Simple
{
private:
    int closed;
    void invisible();

public:
    int open;
    void number_1(int newValue);
    void plus();
    void call_closed();
    void getter();
};

#endif