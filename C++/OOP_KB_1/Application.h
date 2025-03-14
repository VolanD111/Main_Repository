#ifndef __APPLICATION__H
#define __APPLICATION__H
#include "Base.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Application : public Base {
    unordered_map<std::string, Base *> objects;

  public:
    Application(Base *, std::string name);
    Application(nullptr_t a);
    void build_tree_objects();
    void print_tree();
    int exec_app();
};

#endif