// C++ program for the coloring the
// background and text with
// different color
#include <iostream>
#include <stdio.h>

// Header file to change color of
// text and background
#include <windows.h>
using namespace std;

// #define

// Driver Code
int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // you can loop k higher to see more color choices
    // for (int k = 0; k < 256; k++)
    // {
    //     // pick the colorattribute k you want
    //     SetConsoleTextAttribute(hConsole, k);
    //     cout << k << " I want to be nice today!" << endl;
    // }

    for (int i = 0; i < 256; i++)
    {
        cout << i << ": ";
        putchar(i);
        cout << endl;
        cout << endl;
    }

    system("pause");
    return 0;
}
