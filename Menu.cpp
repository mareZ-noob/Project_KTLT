#include "Menu.h"

void quit()
{
    clearScreen();
    consoleColor(BLACK, CYAN);
    art("ascii_art\\goodbye.txt");
    consoleColor(BLACK, WHITE);
    Sleep(2000);
    clearScreen();
    exit(1);
}

void login(string &email)
{
    drawRectangle(30, 10, 40, 15);
    // putchar(218);
    // for (int i = 0; i < 43; i++) {
    //     putchar(196);
    // }
    // putchar(191);

    // moveCursor(12, 30);
    // putchar(218);
    // for (int i = 0; i < 43; i++) {
    //     putchar(196);
    // }
    // putchar(191);

    // moveCursor(11, 30);
    // putchar(179);
    // moveCursor(11, 74);
    // cout << "|" << endl;

    // moveCursor(18, 30);
    // cout << "+-------------------------------------------+" << endl;
    // moveCursor(20, 30);
    // cout << "+-------------------------------------------+" << endl;
    // moveCursor(18, 30);
    // cout << "|" << endl;
    // moveCursor(19, 74);
    // cout << "|" << endl;

    // for (int i = 1; i < 6; i++)
    // {
    //     moveCursor(12 + i, 30);
    //     cout << "                                           " << endl;
    // }

    // moveCursor(2, 47);
    // cout << "Login form" << endl;
    // moveCursor(14, 32);
    // cout << "Email: " << endl;
    // moveCursor(16, 32);
    // cout << "Please using \"@clc.fitus.edu.vn\" to login";
    // moveCursor(19, 49);
    // cout << "Enter" << endl;

    // moveCursor(14, 39);
    getline(cin, email);
}

void menuSelection() {
    clearScreen();
    consoleTitle(); 
    showCursor(0);
    disableMouseInput();
    PlaySound(TEXT(POKEMON_SOUND), NULL, SND_ASYNC);
}

void gameSelection() {

}
// figlet -f big "Login successful"
void menu(int choice)
{
    while (choice != 2)
    {   
        consoleTitle(); 
        consoleColor(LIGHT_WHITE, LIGHT_BLUE);
        clearScreen();
        PlaySound(TEXT(POKEMON_SOUND), NULL, SND_ASYNC);
        cout << "1. Login" << endl;
        cout << "2. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice)
        {
        case 1:
        {
            clearScreen();
            string email;
            login(email);
            if (verify(email))
            {
                clearScreen();
                cout << "Login successful!" << endl;
                Sleep(1000);
            }
            else
            {
                clearScreen();
                cout << "Invalid email!" << endl;
            }
            break;
        }
        case 2:
            quit();
            break;
        default:
            cout << "Please type again!" << endl;
        }
        Sleep(1000);
        clearScreen();
    }
}