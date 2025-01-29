#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

void first()
{
    double h, r, R, l, V, S, f;
    f = 1 / 3.;
    cout << "Введите h ";
    cin >> h;
    cout << "Введите r ";
    cin >> r;
    cout << "Введите R ";
    cin >> R;
    if (h <= 0 && r <= 0 && R <= 0)
    {
        cout << "Высота, радиусы должны быть больше 0" << endl;
    }
    else if (R == r)
    {
        cout << "Радиусы не могут быть одинаковыми" << endl;
    }
    else {
        l = sqrt(pow((R - r), 2) + pow(h, 2));
        V = f * M_PI * h * (pow(R, 2) + R * r + pow(r, 2));
        S = M_PI * (pow(R, 2) + l * (R + r) + pow(r, 2));
        cout << "V == " << V << endl;
        cout << "S == " << S << endl;
    }
}

void second(){
    double x, a;
    cout << "Введите x ";
    cin >> x;
    cout << "Введите a ";
    cin >> a;
    if (fabs(x) < 1 && x != 0)
    {
        cout << "w == " << a * log(fabs(x)) << endl;
    }
    else if ((a - pow(x, 2)) < 0 | x == 0)
    {
        cout << "Невозможно вычислить" << endl;
    }
    else {
        cout << "w == " << sqrt(a - pow(x, 2)) << endl;
    }
}

void third(){
    double x, y, b;
    cout << "Введите x ";
    cin >> x;
    cout << "Введите y ";
    cin >> y;
    cout << "Введите b ";
    cin >> b;
    if (b - x >= 0 && b - y > 0)
    {
        cout << "z == " << log(b - y) * sqrt(b - x) << endl;
    }
    else
    {
        cout << "Невозможно вычислить";
    }
}

void fourth(){
    int a;
    cout << "Введите a ";
    cin >> a;
    if (a > 0)
    {
      for (int i {0}; i < 10; i++)
    {
        cout << a + i << endl;
    }  
    }
    else
    {
        cout << "Число должно быть натуральным";
    }
}

void fifth(){
    for (float x {-4}; x <= 4; x+=0.5)
    {
        if (x - 1 != 0)
        {
            cout << x << "\t" << (pow(x, 2) - 2 * x + 2) / (x - 1) << endl;
        }
        else
        {
            cout << "При x == " << x << " невозможно вычислить значение функции" << endl;
        }
    }
}

int main(){
    //first();
    //second();
    third();
    //fourth();
    //fifth();
}