#include "Menu.h"

void quit()
{
    clearScreen();
    consoleColor(BLACK, CYAN);
    clearScreen();
    art("ascii_art\\goodbye.txt", 30, 13);
    consoleColor(BLACK, WHITE);
    Sleep(5000);
    clearScreen();
    exit(1);
}
// PlaySound(TEXT(POKEMON_SOUND), NULL, SND_ASYNC);

void login(string &email)
{
    TextColor(CYAN);
    drawRectangle(40, 8, 40, 10);

    button(40, 8, 41, 2, LIGHT_YELLOW, CYAN, BLACK, " Enter your email to continue");
    moveCursor(42, 12);
    TextColor(LIGHT_YELLOW);
    cout << "Email: ";
    moveCursor(48, 12);
    button(48, 11, 30, 2, LIGHT_WHITE, CYAN, BLACK, " "); 
    moveCursor(43, 14);
    TextColor(LIGHT_GREEN);
    cout << "(Using \"@clc.fitus.edu.vn\" to login)";
    moveCursor(49, 16);
    TextColor(LIGHT_YELLOW);
    cout << "Press ENTER to continue";

    moveCursor(49, 12);
    TextColor(LIGHT_WHITE);
    showCursor(1);
    getline(cin, email);
    if (verify(email))
    {
        while (true)
        {
            char c = _getch(); 
            if (c == ENTER_KEY || c == '\n')
            {
                clearScreen();
                MenuLogin();
            }
        }
    }
    else
    {
        TextColor(LIGHT_RED);
        moveCursor(51, 20);
        cout << "INVALID EMAIL ADDRESS!";
        moveCursor(47, 21);
        cout << "Please enter your email again";
        return login(email);
    }
}

void selectionMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text)
{
    int Color = textColor;

    if (selection == 1)
    {
        textColor = LIGHT_RED;
        button(x, y, w, h, textColor, buttonColor, backgroundColor, "     > LOGIN <");
    }
    else
    {
        button(x, y, w, h, Color, buttonColor, backgroundColor, "       LOGIN");
    }

    if (selection == 2)
    {
        textColor = LIGHT_RED;
        button(x, y + 2, w, h, textColor, buttonColor, backgroundColor, "  > HOW TO PLAY <");
        moveCursor(x, y + 2);
        cout << char(195);
        moveCursor(x + w, y + 2);
        cout << char(180);
    }
    else
    {
        button(x, y + 2, w, h, Color, buttonColor, backgroundColor, "    HOW TO PLAY");
        moveCursor(x, y + 2);
        cout << char(195);
        moveCursor(x + w, y + 2);
        cout << char(180);
    }

    if (selection == 3)
    {
        textColor = LIGHT_RED;
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
        textColor = LIGHT_RED;
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
        textColor = LIGHT_RED;
        button(x, y, w, h, textColor, buttonColor, backgroundColor, "   > PLAY GAME <");
    }
    else
    {
        textColor = Color;
        button(x, y, w, h, Color, buttonColor, backgroundColor, "     PLAY GAME");
    }

    if (selection == 2)
    {
        textColor = LIGHT_RED;
        button(x, y + 2, w, h, textColor, buttonColor, backgroundColor, "  > LEADERBOARD <");
        moveCursor(x, y + 2);
        cout << char(195);
        moveCursor(x + w, y + 2);
        cout << char(180);
    }
    else
    {
        textColor = Color;
        button(x, y + 2, w, h, Color, buttonColor, backgroundColor, "    LEADERBOARD");
        moveCursor(x, y + 2);
        cout << char(195);
        moveCursor(x + w, y + 2);
        cout << char(180);
    }

    if (selection == 3)
    {
        textColor = LIGHT_RED;
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
        textColor = LIGHT_RED;
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
    drawBorder();
    art_at_pos("ascii_art\\pikachu.txt", LIGHT_YELLOW, backgroundColor, 27, 1);
    pokemon_ball("ascii_art\\pokemonball.txt", BLACK, 4, 14);
    pikachu_small("ascii_art\\pikachu_small.txt", BLACK, 70, 11);
    selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
}

void printMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text) // menu when users press "LOGIN"
{
    drawBorder();
    selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
}

int MainMenuBack()
{
    int x = 50;
    int y = 24;
    int w = 20;
    int h = 2;
    int textColor = CYAN;
    int buttonColor = PURPLE;
    int backgroundColor = BLACK;
    string email;
    string text;
    showCursor(0);
    int selection = 1;
    printMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

    while (true)
    {
        char c = _getch();

        if (c == KEY_w or c == KEY_W)
        { // move up
            selection--;
            if (selection == 0) {
                selection = 4;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == KEY_s or c == KEY_S)
        { // move down
            selection++;
            if (selection == 5) {
                selection = 1;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == ENTER_KEY or c == '\n')
        { // pressed enter
            switch (selection)
            {
            case 1:
                clearScreen();
                drawBorder();
                login(email);
                break;
            case 2:
                clearScreen();
                drawBorder();
                moveCursor(2, 33);
                TextColor(LIGHT_WHITE);
                cout << "<< Press Esc to back";
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == ESC_KEY)
                        {
                            clearScreen();
                            MainMenuBack();
                            break;
                        }
                    }
                }
            case 3:
                clearScreen();
                drawBorder();
                moveCursor(2, 33);
                TextColor(LIGHT_WHITE);
                cout << "<< Press Esc to back";
                art_at_pos("ascii_art\\credit.txt", LIGHT_GREEN, backgroundColor, 36, 5);
                read_file_at_pos("ascii_art\\content.txt", CYAN, backgroundColor, 35, 13);
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == ESC_KEY)
                        {
                            clearScreen();
                            MainMenuBack();
                            break;
                        }
                    }
                }
            case 4:
                clearScreen();
                drawBorder();
                quit();
                exit(1);
            }
        }
    }
    system("pause");
}

void MenuLoginBack()
{
    int x = 50;
    int y = 10;
    int w = 20;
    int h = 2;
    int textColor = CYAN;
    int buttonColor = PURPLE;
    int backgroundColor = BLACK;
    string text;
    showCursor(0);
    int selection = 1; // start with the first button selected
    printMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

    while (true)
    {
        char c = _getch();

        if (c == KEY_w or c == KEY_W)
        { // move up
            selection--;
            if (selection == 0) {
                selection = 4;
            }
            selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == KEY_s or c == KEY_S)
        { // move down
            selection++;
            if (selection == 5) {
                selection = 1;
            }
            selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == ENTER_KEY or c == '\n')
        { // pressed enter
            switch (selection)
            {
            case 1:
                clearScreen();
                drawBorder();
                
                moveCursor(2, 33);
                TextColor(LIGHT_WHITE);
                cout << "<< Press Esc to back";
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == ESC_KEY)
                        {
                            clearScreen();
                            MenuLoginBack();
                            break;
                        }
                    }
                }
            case 2:
                clearScreen();
                drawBorder();
                moveCursor(2, 33);
                TextColor(LIGHT_WHITE);
                cout << "<< Press Esc to back";
                printLeaderboard();
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == ESC_KEY)
                        {
                            clearScreen();
                            MenuLoginBack();
                            break;
                        }
                    }
                }
            case 3:
                clearScreen();
                drawBorder();
                moveCursor(2, 33);
                TextColor(LIGHT_WHITE);
                cout << "<< Press Esc to back";
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == ESC_KEY)
                        {
                            clearScreen();
                            MenuLoginBack();
                            break;
                        }
                    }
                }
            case 4:
                clearScreen();
                drawBorder();
                MainMenuBack();
                Sleep(5000);
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
    int textColor = CYAN;
    int buttonColor = PURPLE;
    int backgroundColor = BLACK;
    string text;
    showCursor(0);
    int selection = 1; // start with the first button selected
    printMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

    while (true)
    {
        char c = _getch(); 

        if (c == KEY_w or c == KEY_W)
        { // move up
            selection--;
            if (selection == 0) {
                selection = 4;
            }
            selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == KEY_s or c == KEY_S)
        { // move down
            selection++;
            if (selection == 5) {
                selection = 1;
            }
            selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == ENTER_KEY or c == '\n')
        { // pressed enter
            switch (selection)
            {
            case 1:
                clearScreen();
                drawBorder();
                
                moveCursor(2, 33);
                TextColor(LIGHT_WHITE);
                cout << "<< Press Esc to back";
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == ESC_KEY)
                        {
                            clearScreen();
                            MenuLoginBack();
                            break;
                        }
                    }
                }
            case 2:
                clearScreen();
                drawBorder();
                moveCursor(2, 33);
                TextColor(LIGHT_WHITE);
                cout << "<< Press Esc to back";
                printLeaderboard();
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == ESC_KEY)
                        {
                            clearScreen();
                            MenuLoginBack();
                            break;
                        }
                    }
                }
            case 3:
                clearScreen();
                drawBorder();
                moveCursor(2, 33);
                TextColor(LIGHT_WHITE);
                cout << "<< Press Esc to back";
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == ESC_KEY)
                        {
                            clearScreen();
                            MenuLoginBack();
                            break;
                        }
                    }
                }
            case 4:
                clearScreen();
                drawBorder();
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
    int y = 24;
    int w = 20;
    int h = 2;
    int textColor = CYAN;
    int buttonColor = PURPLE;
    int backgroundColor = BLACK;
    string email;
    string text;
    showCursor(0);
    int selection = 1; 
    printMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

    while (true)
    {
        char c = _getch(); 

        if (c == KEY_w or c == KEY_W)
        { // move up
            selection--;
            if (selection == 0) {
                selection = 4;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == KEY_s or c == KEY_S)
        { // move down
            selection++;
            if (selection == 5) {
                selection = 1;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == ENTER_KEY or c == '\n')
        { // pressed enter
            switch (selection)
            {
            case 1:
                clearScreen();
                drawBorder();
                login(email);
                break;
            case 2:
                clearScreen();
                drawBorder();
                moveCursor(2, 33);
                TextColor(LIGHT_WHITE);
                cout << "<< Press Esc to back";
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == ESC_KEY)
                        {
                            clearScreen();
                            MainMenuBack();
                            break;
                        }
                    }
                }
            case 3:
               clearScreen();
                drawBorder();
                moveCursor(2, 33);
                TextColor(LIGHT_WHITE);
                cout << "<< Press Esc to back";
                art_at_pos("ascii_art\\credit.txt", LIGHT_GREEN, backgroundColor, 36, 5);
                read_file_at_pos("ascii_art\\content.txt", CYAN, backgroundColor, 35, 13);
                while (true)
                {
                    if (kbhit())
                    {
                        char key = _getch();
                        if (key == ESC_KEY)
                        {
                            clearScreen();
                            MainMenuBack();
                            break;
                        }
                    }
                }
            case 4:
                clearScreen();
                drawBorder();
                quit();
                exit(1);
            }
        }
    }
    system("pause");
}
