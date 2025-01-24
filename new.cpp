#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <typeinfo>
#include <map>
#include <windows.h>
#include <wingdi.h>
#include <cstdlib>
using namespace std;

int main() {
    HWND k = GetConsoleWindow();
    HDC l = GetDC(k);
    for (int i; i <500; i++) {
        HDC m = CreateCompatibleDC(l);
        SetPixel(l, i, 110, RGB(0, 255, 255));
        cout << i << endl;
    }
}