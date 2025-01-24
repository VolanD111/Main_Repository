#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <stdio.h>


using namespace std;

int main() {
    int y = 0;
    int x = 0;
    int xs = 0;
    int ys = 0;

    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);

    x = desktop.right / 2;
    y = desktop.bottom / 2 - 2;

    xs = desktop.right / 2 - 2;
    ys = desktop.bottom / 2;

    HPEN pen = CreatePen(PS_SOLID, 8, RGB(255, 0, 0));

    HDC dot = ::GetDC(0);

    for (;;) {
        SelectObject(dot, pen);
        MoveToEx(dot, x, y, NULL);
        LineTo(dot, x, y + 4);
        Sleep(10);
    }
}
