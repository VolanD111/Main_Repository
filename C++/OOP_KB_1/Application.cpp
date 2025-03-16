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

Application::Application(nullptr_t) : Base(nullptr, "Highest object") {
    objects["Highest object"] = this;
}

void Application::build_tree_objects() {
    string line;
    while (getline(cin, line)) {
        istringstream stream(line);
        vector<string> words;
        string word;

        while (stream >> word) {
            words.push_back(word);
        }

        if (words.empty())
            continue;

        if (words.size() == 1) { // Установка имени главного объекта
            this->setter_name(words[0]);
            objects[this->getter_name()] = this;
            continue;
        }

        string primary_object = words[0];
        string child_object = words[1];

        if (primary_object == child_object)
            break; // Защита от зацикливания

        // Проверяем, есть ли уже дочерний объект
        bool exists = false;
        for (auto it : objects[primary_object]->children_objects) {
            if (it->getter_name() == child_object) {
                exists = true;
                duplicate[child_object] = false;
                break;
            }
        }
        if (exists)
            continue;

        // Создаём новый дочерний объект
        auto *primary_object_ptr =
            new Application(objects[primary_object], child_object);
        objects[child_object] = primary_object_ptr;
    }
}

int Application::exec_app() {
    cout << this->getter_name() << endl;
    vector<Base *> current_level = {this};

    while (!current_level.empty()) {
        bool check = false;
        vector<Base *> next_level;
        bool first = true;

        for (auto obj : current_level) {
            //
            if (duplicate.find(obj->getter_name()) != duplicate.end()) {
                check = true;
                for (auto sub : obj->children_objects) {
                    next_level.push_back(sub);
                }
                continue;
            } else {
                if (!obj->children_objects.empty()) {
                    if (!first)
                        cout << endl;
                    first = false;

                    cout << obj->getter_name();
                    for (auto sub : obj->children_objects) {
                        if (obj->getter_name() == sub->getter_name())
                            break;

                        if (duplicate.find(sub->getter_name()) !=
                            duplicate.end()) {
                            if (duplicate[sub->getter_name()])
                                break;

                            duplicate[sub->getter_name()] = true;
                        }

                        cout << "  " << sub->getter_name();
                        next_level.push_back(sub);
                    }
                }
            }
        }

        current_level = next_level;
        if (check) {
            continue;
        }
        if (!current_level.empty())
            cout << endl;
    }

    return 0;
}
