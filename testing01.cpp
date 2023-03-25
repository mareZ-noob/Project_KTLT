#include <windows.h>
#include "Main.h"
#include <bits/stdc++.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void consoleColor(int background, int text)
{
	SetConsoleTextAttribute(console, background * 16 + text);
}

void showCursor(bool visible)
{
    CONSOLE_CURSOR_INFO lpCursor;

    lpCursor.dwSize = 200;
    lpCursor.bVisible = visible;
    SetConsoleCursorInfo(console, &lpCursor);
}

void moveCursor(int posX, int posY)
{
	COORD CursorPosition;
	CursorPosition.X = posX;
	CursorPosition.Y = posY;
	SetConsoleCursorPosition(console, CursorPosition);
}

void drawRectangle(int left, int top, int width, int height)
{
	int i;
	moveCursor(left, top);
	putchar(218);
	for (i = 0; i < width; i++)
	{
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
	for (i = 0; i < width; i++)
	{
		putchar(196);
	}
	putchar(217);
}

void login(string &email)
{
	showCursor(0);
	consoleColor(LIGHT_WHITE, BLACK);
	system("cls");
	int left = 30, top = 10, width = 42, height = 13;
	drawRectangle(left, top, width, height);

	moveCursor(left + 1, top + 1);
	consoleColor(LIGHT_WHITE, LIGHT_BLUE);
	cout << "Login into Pikachu's Game" << endl;

	consoleColor(LIGHT_WHITE, BLACK);
	for (int i = left + 1; i < left + width + 1; i++)
	{
		moveCursor(i, top + 2);
		putchar(196);
	}

	moveCursor(left + 1, top + 5);
	cout << "Email: " << endl;
	moveCursor(left + 1, top + 7);
	cout << "Please using \"@clc.fitus.edu.vn\" to login";

	for (int i = left + 1; i < left + width + 1; i++)
	{
		moveCursor(i, top + 11);
		putchar(196);
	}
	moveCursor(49, top + 12);
	consoleColor(WHITE, BLACK);
	cout << "Enter" << endl;

	consoleColor(LIGHT_WHITE, BLACK);
	moveCursor(left + 8, top + 5);
	getline(cin, email);
}

int main()
{
	string email;
	login(email);
	system("pause");
	return 0;
}