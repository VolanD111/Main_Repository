#ifndef __NEWUNION__H
#define __NEWUNION__H

union newUnion
{
private:
    short closed;

public:
    int open;
    char list[4];
    void setClosed(short newValue);
    short getClosed();
};

#endif