#include "Setup.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
HWND hWnd = GetConsoleWindow();

void SetWindowSize(int width, int height)
{
    // Get the console handle
    HWND hConsole = GetConsoleWindow();
    // MoveWindow(window_handle, x, y, width, height, redraw_window);
    MoveWindow(hConsole, 280, 50, width, height, TRUE);
}

void SetScreenBufferSize(SHORT width, SHORT height)
{
    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;

    SetConsoleScreenBufferSize(console, NewSize);
}

void DisableResizeWindow()
{
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}

void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HMENU hMenu = GetSystemMenu(hWnd, false);

    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}

void ShowScrollbar(BOOL Show)
{
    ShowScrollBar(hWnd, SB_BOTH, Show);
}

void DisableSelection()
{
    SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}

void showCursor(bool visible)
{
	CONSOLE_CURSOR_INFO cursor = { 1, visible };
	SetConsoleCursorInfo(console, &cursor);
}

void moveCursor(int posX, int posY)
{
    COORD CursorPosition;
    CursorPosition.X = posX;
    CursorPosition.Y = posY;
    SetConsoleCursorPosition(console, CursorPosition);
}

void disableMouseInput()
{
    DWORD prev_mode;
    GetConsoleMode(hStdin, &prev_mode);
    SetConsoleMode(hStdin, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

void consoleTitle()
{
    SetConsoleTitleW(L"          🐹 𝒫𝒾𝓀𝒶𝒸𝒽𝓊 🐹");
}

void consoleColor(int background, int text)
{
    SetConsoleTextAttribute(console, background * 16 + text);
}

void clearScreen()
{
    HANDLE hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;
    COORD homeCoords = {0, 0};

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE)
        return;

    // Get the number of cells in the current buffer
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi))
        return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire buffer with spaces
    if (!FillConsoleOutputCharacter(
            hStdOut,
            (TCHAR)' ',
            cellCount,
            homeCoords,
            &count))
        return;

    // Fill the entire buffer with the current colors and attributes
    if (!FillConsoleOutputAttribute(
            hStdOut,
            csbi.wAttributes,
            cellCount,
            homeCoords,
            &count))
        return;

    // Move the cursor home
    SetConsoleCursorPosition(hStdOut, homeCoords);
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

void initConsole()
{
    SetWindowSize(1000, 750);
    consoleTitle();
    disableMouseInput();
    showCursor(0);
    ShowScrollbar(0);
    DisableSelection();
    DisableCtrButton(1, 1, 1);
}

void TextColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void button(int x, int y, int w, int h, int textColor, int buttonColor, int color, string text)
{
	consoleColor(color, textColor);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			moveCursor(ix, iy); cout << " ";
		}
	}
    
	moveCursor(x + 1, y + 1);
	TextColor(textColor);
	cout << text;

	consoleColor(color, textColor);
	TextColor(buttonColor);
	if (h <= 1 || w <= 1)
		return;
	for (int ix = x; ix <= x + w; ix++)
	{
		moveCursor(ix, y);
		cout << char(196);
		moveCursor(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		moveCursor(x, iy);
		cout << char(179);
		moveCursor(x + w, iy);
		cout << char(179);
	}
	moveCursor(x, y); cout << char(218);
	moveCursor(x + w, y); cout << char(191);
	moveCursor(x, y + h); cout << char(192);
	moveCursor(x + w, y + h); cout << char(217);
}

void drawBorder()
{
    drawRectangle(0, 0, 118, 34);
}
