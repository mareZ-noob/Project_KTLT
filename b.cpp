#include <iostream>
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h> // for _getch() function

using namespace std;

int getConsoleInput()
{
    int c = _getch();
    if (c == 0 || c == 224)
    {
        switch (_getch())
        {
        case 72:
            return 2;
            break;
        case 75:
            return 3;
            break;
        case 77:
            return 4;
            break;
        case 80:
            return 5;
            break;
        default:
            return 0;
            break;
        }
    }
    else
    {
        if (c == 27) // esc
            return 1;
        else if (c == 87 || c == 119) // W, w
            return 2;
        else if (c == 65 || c == 97) // A, a
            return 3;
        else if (c == 68 || c == 100) // D, d
            return 4;
        else if (c == 83 || c == 115) // S, s
            return 5;
        else if (c == 13) // Enter
            return 6;
        else if (c == 72 || c == 104) // H, h
            return 7;
        else
            return 0; // nút khác
    }
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

// function to print the menu options
void printMenu(int selection)
{
    clearScreen();
    cout << "Main Menu\n\n";
    if (selection == 1)
    {
        cout << "> Login <\n";
    }
    else
    {
        cout << "  Login\n";
    }
    if (selection == 2)
    {
        cout << "> About <\n";
    }
    else
    {
        cout << "  About\n";
    }
    if (selection == 3)
    {
        cout << "> Exit <\n";
    }
    else
    {
        cout << "  Exit\n";
    }
}

int main()
{
    int selection = 1; // start with the first button selected
    printMenu(selection);

    while (true)
    {
        int c = getConsoleInput(); // wait for a key to be pressed
        if ((c == 2) && selection > 1)
        { // move selection up
            selection--;
        }
        else if ((c == 5) && selection < 3)
        { // move selection down
            selection++;
        }
        else if (c == 7)
        { // user pressed enter, so execute the selected option
            switch (selection)
            {
            case 1:
                clearScreen();
                cout << "You selected Login\n";
                Sleep(5000);
                break;
            case 2:
                cout << "You selected About\n";
                break;
            case 3:
                cout << "Goodbye!\n";
                return 0;
            }
        }
        printMenu(selection); // print the updated menu
    }
    system("pause");
    return 0;
}
