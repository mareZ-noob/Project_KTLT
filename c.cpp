#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

// declare a global mutex lock
std::mutex console_mutex;

HWND consoleWindow = GetConsoleWindow();
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void moveCursor(int posX, int posY)
{
    COORD CursorPosition;
    CursorPosition.X = posX;
    CursorPosition.Y = posY;
    SetConsoleCursorPosition(console, CursorPosition);
}

void clockTime() {
    int elapsed_seconds = 0;

    while (true)
    {
        // Wait for 1 second
        Sleep(1000);
        // std::this_thread::sleep_for(std::chrono::seconds(1));

        // Update elapsed time
        elapsed_seconds++;

        // Convert elapsed time to minutes and seconds
        int minutes = elapsed_seconds / 60;
        int seconds = elapsed_seconds % 60;

        // format 00:00
        moveCursor(40,0);
        printf("%02d:%02d", minutes, seconds);
        // std::cout << std::setfill('0') << std::setw(2) << minutes << ":"
        //           << std::setfill('0') << std::setw(2) << seconds << '\r';
    }
}

// function to print the menu options
void printMenu(int selection)
{
    system("cls"); // clear the console
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

    std::thread clock_thread(clockTime);
    while (true)
    {
        char c = _getch(); // wait for a key to be pressed

        if ((c == 'w' or c == 72) && selection > 1)
        { // move selection up
            selection--;
        }
        else if ((c == 's' or c == 80) && selection < 3)
        { // move selection down
            selection++;
        }
        else if (c == '\r' || c == '\n')
        { // user pressed enter, so execute the selected option
            switch (selection)
            {
            case 1:
                system("cls");
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
