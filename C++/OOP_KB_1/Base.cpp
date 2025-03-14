#include "Base.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Base::Base(Base *head_object, string name) {
    this->head_object = head_object;
    this->name = name;
    if (head_object) {
        head_object->children_objects.push_back(this);
    }
}

Base::~Base() {
    for (auto child : children_objects) {
        delete child;
    }
}

string Base::getter_name() { return name; }

Base *Base::getter_head_object() { return head_object; }

int Base::setter_name(string Newname) {
    for (int i = 0; i < children_objects.size(); i++) {
        if (children_objects[i]->getter_name() == Newname) {
            return false;
        }
    }
    name = Newname;
    return true;
}

Base *Base::getter_child_object(string name) {
    for (int i = 0; i < children_objects.size(); i++) {
        if (children_objects[i]->getter_name() == name) {
            return children_objects[i];
        }
    }
    return nullptr;
}
