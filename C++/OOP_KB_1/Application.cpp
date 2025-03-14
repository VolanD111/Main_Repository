#include "Application.h"
#include "Base.h"
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

Application::Application(Base *obj, string name) : Base(obj, name) {
    objects[name] = this;
}

Application::Application(nullptr_t a) : Base(nullptr, "Highest object") {
    objects["Highest object"] = this;
}

void Application::build_tree_objects() {
    vector<string> objects_here;
    string line, primary_object, child_object, word;
    while (getline(cin, line)) {
        istringstream stream(line);
        while (stream >> word) {
            objects_here.push_back(word);
        }
        if (objects_here.size() == 1) {
            this->setter_name(objects_here[0]);
            objects_here.clear();
            objects[this->getter_name()] = this;
            continue;
        }
        primary_object = objects_here[0];
        child_object = objects_here[1];
        objects_here.clear();
        if (primary_object == child_object) {
            break;
        } else {
            Application *primary_object_ptr =
                new Application(objects[primary_object], child_object);
            objects[child_object] = primary_object_ptr;
        }
    }
}

void Application::print_tree() {
    cout << this->getter_name() << endl; // Вывод корневого объекта
    vector<Base *> current_level = {this};

    while (!current_level.empty()) {
        vector<Base *> next_level;
        bool first = true;

        for (auto obj : current_level) {
            if (!obj->children_objects.empty()) {
                if (!first)
                    cout << endl; // Разделение уровней строкой
                first = false;

                cout << obj->getter_name();
                for (auto sub : obj->children_objects) {
                    cout << "  " << sub->getter_name();
                    next_level.push_back(sub);
                }
            }
        }
        current_level = next_level;
        if (current_level.empty()) {
            break;
        }
        cout << endl;
    }
}

int Application::exec_app() {
    print_tree();
    return 0;
}