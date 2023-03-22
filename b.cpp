#include <windows.h>
#include <iostream>
#include <stdio.h>

using namespace std;

HWND consoleWindow = GetConsoleWindow();
HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoXY(int pX, int pY)
{
    SetConsoleCursorPosition(consoleOutput, COORD{(short)pX, (short)pY});
}

void printRectangle(int left, int top, int width, int height)
{
    gotoXY(left, top);
    putchar(218);
    for (int i = 0; i < width; i++)
        putchar(196);
    putchar(191);

    int i = 0;
    for (; i < height; i++)
    {
        gotoXY(left, top + i + 1);
        putchar(179);
        gotoXY(left + width + 1, top + i + 1);
        putchar(179);
    }

    gotoXY(left, top + i);
    putchar(192);
    for (i = 0; i < width; i++)
        putchar(196);
    putchar(217);
}

void SetWindowSize(SHORT width, SHORT height)
{
    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(consoleWindow, 1, &WindowSize);
}

int main()
{
    // Get the console handle
    HWND console = GetConsoleWindow();
    // MoveWindow(window_handle, x, y, width, height, redraw_window);
    MoveWindow(console, 200, 200, 800, 600, TRUE);
    // printRectangle(30, 10, 30, 5);
    // SetWindowSize(72, 26);
    // gotoXY(0, 2);
    // cout << "Rectangle" << endl;
    system("pause");
    return 0;
}