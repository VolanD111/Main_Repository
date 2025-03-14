#ifndef __BASE__H
#define __BASE__H
#include <iostream>
#include <string>
#include <vector>

class Base {
  protected:
    Base *head_object;
    std::string name;

  public:
    std::vector<Base *> children_objects;
    Base(Base *head_object, std::string name = "Highest object");
    ~Base();
    int setter_name(std::string Newname);
    std::string getter_name();
    Base *getter_head_object();
    Base *getter_child_object(std::string name);
    void print_tree();
};

#endif