#include "Application.cpp"
#include "Application.h"
#include "Base.cpp"
#include "Base.h"

int main() {
    Application ob_cl_application(nullptr); // создание корневого объекта
    ob_cl_application.build_tree_objects(); // конструирование системы,
    return ob_cl_application.exec_app(); // запуск системы
}