#include <iostream>
#include <windows.h>
#include <stdio.h>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void moveCursor(int posX, int posY)
{
    COORD CursorPosition;
    CursorPosition.X = posX;
    CursorPosition.Y = posY;
    SetConsoleCursorPosition(console, CursorPosition);
}

void move(SHORT posX, SHORT posY)
{
    COORD CursorPosition;
    CursorPosition.X = posX;
    CursorPosition.Y = posY;
    SetConsoleCursorPosition(console, CursorPosition);
}

void drawRectangle(int left, int top, int width, int height)
{
    moveCursor(left, top);
    putchar(218);
    int i;
    for (i = 0; i < width; i++){
        putchar(196);
    }
    putchar(191);

    for (i = 0; i < height; i++)
    {
        moveCursor(left, top + i + 1);
        putchar(179);
        moveCursor(left + width + 1, top + i + 1);
        putchar(179);
    }

    moveCursor(left, top + i);
    putchar(192);
    for (i = 0; i < width; i++) {
        putchar(196);
    }
    putchar(217);
}

int main()
{

    drawRectangle(35, 10, 30, 15);
    // moveCursor(35, 10);
    // putchar(218);
    // putchar(196);
    // moveCursor(35, 11);
    // putchar(179);
    // moveCursor(35, 12);
    // putchar(192);

    system("pause");
    return 0;
}