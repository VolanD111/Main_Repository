#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Simple
{

private:
    long long int n;

public:
    Simple() : n(0) {}
    long long int getter() const
    {
        return n;
    }
    void setter(long long int newValue)
    {
        n = newValue;
    }
    int counts() const
    {
        return to_string(abs(n)).length();
    }
};

int main()
{
    Simple obj;
    long long int number;
    cin >> number;
    obj.setter(number);
    cout << obj.getter() << endl;
    cout << obj.counts() << endl;
    return (0);
}
