#include "Menu.h"

void quit()
{
    clearScreen();
    consoleColor(BLACK, CYAN);
    clearScreen();
    art("ascii_art\\goodbye.txt", 30, 13);
    consoleColor(BLACK, WHITE);
    Sleep(4000);
    clearScreen();
    exit(1);
}
// PlaySound(TEXT(POKEMON_SOUND), NULL, SND_ASYNC);

void login(string &email)
{
    TextColor(7);
    drawRectangle(40, 8, 40, 10);

    button(40, 8, 41, 2, 4, 7, 0, " Enter your email to continue");
    cout << endl;
    moveCursor(42, 12);
    TextColor(4);
    cout << "Email: ";
    moveCursor(48, 12);
    button(48, 11, 30, 2, 7, 7, 0, " "); 
    cout << endl;
    moveCursor(43, 15);
    TextColor(4);
    cout << "(Using \"@clc.fitus.edu.vn\" to login)";

    moveCursor(49, 12);
    showCursor(0);
    TextColor(7);
    getline(cin, email);
    if (verify(email))
    {
        while (true)
        {
            char c = _getch(); 
            if (c == '\r' || c == '\n')
            {
                clearScreen();
                MenuLogin();
            }
        }
    }
    else
    {
        moveCursor(47, 20);
        TextColor(4);
        cout << "Please enter your email again!";
        return login(email);
    }
}

void selectionMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text)
{
    int Color = textColor;

    if (selection == 1)
    {
        textColor = 4;
        button(x, y, w, h, textColor, buttonColor, backgroundColor, "     > LOGIN <");
    }
    else
    {
        button(x, y, w, h, Color, buttonColor, backgroundColor, "       LOGIN");
    }

    if (selection == 2)
    {
        textColor = 4;
        button(x, y + 2, w, h, textColor, buttonColor, backgroundColor, "     > ABOUT <\n");
        moveCursor(x, y + 2);
        cout << char(195);
        moveCursor(x + w, y + 2);
        cout << char(180);
    }
    else
    {
        button(x, y + 2, w, h, Color, buttonColor, backgroundColor, "       ABOUT");
        moveCursor(x, y + 2);
        cout << char(195);
        moveCursor(x + w, y + 2);
        cout << char(180);
    }

    if (selection == 3)
    {
        textColor = 4;
        button(x, y + 4, w, h, textColor, buttonColor, backgroundColor, "    > CREDITS <");
        moveCursor(x, y + 4);
        cout << char(195);
        moveCursor(x + w, y + 4);
        cout << char(180);
    }
    else
    {
        button(x, y + 4, w, h, Color, buttonColor, backgroundColor, "      CREDITS");
        moveCursor(x, y + 4);
        cout << char(195);
        moveCursor(x + w, y + 4);
        cout << char(180);
    }

    if (selection == 4)
    {
        textColor = 4;
        button(x, y + 6, w, h, textColor, buttonColor, backgroundColor, "     > EXIT <");
        moveCursor(x, y + 6);
        cout << char(195);
        moveCursor(x + w, y + 6);
        cout << char(180);
    }
    else
    {
        button(x, y + 6, w, h, Color, buttonColor, backgroundColor, "       EXIT");
        moveCursor(x, y + 6);
        cout << char(195);
        moveCursor(x + w, y + 6);
        cout << char(180);
    }
}

void selectionMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text)
{
    int Color = textColor;

    if (selection == 1)
    {
        textColor = 4;
        button(x, y, w, h, textColor, buttonColor, backgroundColor, "   > PLAY GAME <");
    }
    else
    {
        textColor = Color;
        button(x, y, w, h, Color, buttonColor, backgroundColor, "     PLAY GAME");
    }

    if (selection == 2)
    {
        textColor = 4;
        button(x, y + 2, w, h, textColor, buttonColor, backgroundColor, "  > HIGH SCORES <");
        moveCursor(x, y + 2);
        cout << char(195);
        moveCursor(x + w, y + 2);
        cout << char(180);
    }
    else
    {
        textColor = Color;
        button(x, y + 2, w, h, Color, buttonColor, backgroundColor, "    HIGH SCORES");
        moveCursor(x, y + 2);
        cout << char(195);
        moveCursor(x + w, y + 2);
        cout << char(180);
    }

    if (selection == 3)
    {
        textColor = 4;
        button(x, y + 4, w, h, textColor, buttonColor, backgroundColor, "  > FORGET EMAIL <");
        moveCursor(x, y + 4);
        cout << char(195);
        moveCursor(x + w, y + 4);
        cout << char(180);
    }
    else
    {
        textColor = Color;
        button(x, y + 4, w, h, Color, buttonColor, backgroundColor, "    FORGET EMAIL");
        moveCursor(x, y + 4);
        cout << char(195);
        moveCursor(x + w, y + 4);
        cout << char(180);
    }

    if (selection == 4)
    {
        textColor = 4;
        button(x, y + 6, w, h, textColor, buttonColor, backgroundColor, "     > BACK <");
        moveCursor(x, y + 6);
        cout << char(195);
        moveCursor(x + w, y + 6);
        cout << char(180);
    }
    else
    {
        textColor = Color;
        button(x, y + 6, w, h, Color, buttonColor, backgroundColor, "       BACK");
        moveCursor(x, y + 6);
        cout << char(195);
        moveCursor(x + w, y + 6);
        cout << char(180);
    }
}

void printMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text) // main menu
{
    //system("color 70");
    art_at_pos("ascii_art\\pikachu.txt", 15, backgroundColor, 27, 5);
    selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
}

void printMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text) // menu when users press "LOGIN"
{
    selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
}

int MainMenuBack()
{
    int x = 50;
    int y = 17;
    int w = 20;
    int h = 2;
    int textColor = 7;
    int buttonColor = 22;
    int backgroundColor = 0;
    string email;
    string text;
    disableCursor(0);
    int selection = 1;
    printMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

    while (true)
    {
        char c = _getch();

        if (c == 'w' or c == 'W')
        { // move up
            selection--;
            if (selection == 0) {
                selection = 4;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == 's' or c == 'S')
        { // move down
            selection++;
            if (selection == 5) {
                selection = 1;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
            ;
        }
        else if (c == '\r' || c == '\n')
        { // pressed enter
            switch (selection)
            {
            case 1:
                clearScreen();
                login(email);
                break;
            case 2:
                clearScreen();
                cout << "You selected About\n";
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == 27)
                        {
                            clearScreen();
                            MainMenuBack();
                            break;
                        }
                    }
                }
            case 3:
                clearScreen();
                art_at_pos("ascii_art\\credit.txt", 15, backgroundColor, 32, 5);
                read_file_at_pos("ascii_art\\content.txt", 15, backgroundColor, 35, 13);
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == 27)
                        {
                            clearScreen();
                            MainMenuBack();
                            break;
                        }
                    }
                }
            case 4:
                clearScreen();
                quit();
                exit(1);
            }
        }
    }
    system("pause");
}

void MenuLogin()
{
    int x = 50;
    int y = 10;
    int w = 20;
    int h = 2;
    int textColor = 7;
    int buttonColor = 22;
    int backgroundColor = 0;
    string text;
    disableCursor(0);
    int selection = 1; // start with the first button selected
    printMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

    while (true)
    {
        char c = _getch(); 

        if (c == 'w' or c == 'W')
        { // move up
            selection--;
            if (selection == 0) {
                selection = 4;
            }
            selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == 's' or c == 'S')
        { // move down
            selection++;
            if (selection == 5) {
                selection = 1;
            }
            selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == '\r' || c == '\n')
        { // pressed enter
            switch (selection)
            {
            case 1:
                clearScreen();
                cout << "You selected PLAY GAME";
                Sleep(5000);
                break;
            case 2:
                clearScreen();
                printLeaderboard();
                break;
            case 3:
                clearScreen();
                cout << "You selected Settings\n";
                Sleep(5000);
                break;
            case 4:
                clearScreen();
                MainMenuBack();
                Sleep(5000);
            }
        }
    }
    system("pause");
}

void MainMenu()
{
    int x = 50;
    int y = 17;
    int w = 20;
    int h = 2;
    int textColor = 7;
    int buttonColor = 22;
    int backgroundColor = 0;
    string email;
    string text;
    disableCursor(0);
    int selection = 1; // start with the first button selected
    printMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

    while (true)
    {
        char c = _getch(); 

        if ((c == 'w' or c == 'W'))
        { // move up
            selection--;
            if (selection == 0) {
                selection = 4;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if ((c == 's' or c == 'S'))
        { // move down
            selection++;
            if (selection == 5) {
                selection = 1;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == '\r' || c == '\n')
        { // pressed enter
            switch (selection)
            {
            case 1:
                clearScreen();
                login(email);
                break;
            case 2:
                clearScreen();
                cout << "You selected About\n";
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == 27)
                        {
                            clearScreen();
                            MainMenuBack();
                            break;
                        }
                    }
                }
            case 3:
                clearScreen();
                art_at_pos("ascii_art\\credit.txt", 15, backgroundColor, 32, 5);
                read_file_at_pos("ascii_art\\content.txt", 15, backgroundColor, 35, 13);
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == 27)
                        {
                            clearScreen();
                            MainMenuBack();
                            break;
                        }
                    }
                }
            case 4:
                clearScreen();
                quit();
                exit(1);
            }
        }
    }
    system("pause");
}
