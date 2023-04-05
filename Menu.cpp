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

void login(string &email)
{
    login_icon(41, 3);

    TextColor(OCEAN);
    drawRectangle(40, 18, 40, 10);
    button(40, 18, 41, 2, LIGHT_YELLOW, OCEAN, BLACK, " Enter your email to continue");
    moveCursor(40, 20);
    cout << char(195);
    moveCursor(81, 20);
    cout << char(180);

    moveCursor(42, 22);
    TextColor(LIGHT_YELLOW); cout << "Email: ";
    moveCursor(48, 22);
    button(48, 21, 30, 2, LIGHT_WHITE, OCEAN, BLACK, " "); 
    moveCursor(43, 24);
    TextColor(LIGHT_GREEN);
    cout << "(Using \"@clc.fitus.edu.vn\" to login)";
    moveCursor(49, 26);
    TextColor(LIGHT_YELLOW);
    cout << "Press ENTER to continue";

    moveCursor(49, 22);
    TextColor(LIGHT_WHITE);
    showCursor(1);
    getline(cin, email);

    if (verify(email))
    {
        clearScreen();
        MenuLogin();
    }
    else
    {
        TextColor(RED);
        moveCursor(51, 30);
        cout << "INVALID EMAIL ADDRESS!";
        moveCursor(47, 31);
        cout << "Please enter your email again";
        return login(email);
    }
}

void selectionMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text)
{
    int Color = textColor;

    if (selection == 1)
    {
        textColor = RED;
        button(x, y, w, h, textColor, buttonColor, backgroundColor, "     > LOGIN <");
    }
    else
    {
        button(x, y, w, h, Color, buttonColor, backgroundColor, "       LOGIN");
    }

    if (selection == 2)
    {
        textColor = RED;
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
        textColor = RED;
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
        textColor = RED;
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
        textColor = RED;
        button(x, y, w, h, textColor, buttonColor, backgroundColor, "   > PLAY GAME <");
    }
    else
    {
        textColor = Color;
        button(x, y, w, h, Color, buttonColor, backgroundColor, "     PLAY GAME");
    }

    if (selection == 2)
    {
        textColor = RED;
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
        textColor = RED;
        button(x, y + 4, w, h, textColor, buttonColor, backgroundColor, "     > BACK <");
        moveCursor(x, y + 4);
        cout << char(195);
        moveCursor(x + w, y + 4);
        cout << char(180);
    }
    else
    {
        textColor = Color;
        button(x, y + 4, w, h, Color, buttonColor, backgroundColor, "       BACK");
        moveCursor(x, y + 4);
        cout << char(195);
        moveCursor(x + w, y + 4);
        cout << char(180);
    }
}

void printMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text) // main menu
{
    drawBorder();
    art_at_pos("ascii_art\\pikachu.txt", LIGHT_YELLOW, backgroundColor, 21, 1);
    pokemon_ball(4, 15);
    pikachu_small(70, 12);
    selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
}

void printMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text) // menu when users press "LOGIN"
{
    drawBorder();
    pikachu_ava(3, 3);
    charmander_ava(70, 1);
    bulbasaur_ava(85, 15);
    clefairy_ava(20, 23);
    selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
}

void MainMenuBack()
{
     int x = 50;
    int y = 24;
    int w = 20;
    int h = 2;
    int textColor = CYAN;
    int buttonColor = OCEAN;
    int backgroundColor = BLACK;
    string email;
    string text;
    showCursor(0);
    int selection = 1; 
    printMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

    while (true)
    {
        char c = _getch(); 

        if (c == KEY_w || c == KEY_W)
        { // move up
            selection--;
            if (selection == 0) {
                selection = 4;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == KEY_s || c == KEY_S)
        { // move down
            selection++;
            if (selection == 5) {
                selection = 1;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == ENTER_KEY || c == '\n')
        { // pressed enter
            switch (selection)
            {
            case 1:
                createScreen();
                login(email);
                break;
            case 2:
                createScreen();
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
                break;
            case 3:
                createScreen();
                art_at_pos("ascii_art\\credit.txt", CYAN, backgroundColor, 36, 3);
                
                read_file_at_pos("ascii_art\\content.txt", WHITE, backgroundColor, 5, 13);
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
                break;
            case 4:
                clearScreen();
                drawBorder();
                quit();
                exit(1);
                break;
            }
        }
    }
    system("pause");
}

void MenuLoginBack()
{
    int x = 50;
    int y = 15;
    int w = 20;
    int h = 2;
    int textColor = CYAN;
    int buttonColor = OCEAN;
    int backgroundColor = BLACK;
    string text;
    showCursor(0);
    int selection = 1; // start with the first button selected
    printMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

    while (true)
    {
        char c = _getch(); 

        if (c == KEY_w || c == KEY_W)
        { // move up
            selection--;
            if (selection == 0) {
                selection = 4;
            }
            selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == KEY_s || c == KEY_S)
        { // move down
            selection++;
            if (selection == 5) {
                selection = 1;
            }
            selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == ENTER_KEY || c == '\n')
        { // pressed enter
            switch (selection)
            {
            case 1:
                createScreen();
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
                break;
            case 2:
                createScreen();
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
                break;
            case 3:
                clearScreen();
                drawBorder();
                MainMenuBack();
                Sleep(5000);
                break;
            }
        }
    }
    system("pause");
}

void MenuLogin()
{
    int x = 50;
    int y = 15;
    int w = 20;
    int h = 2;
    int textColor = CYAN;
    int buttonColor = OCEAN;
    int backgroundColor = BLACK;
    string text;
    showCursor(0);
    int selection = 1; // start with the first button selected
    printMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

    while (true)
    {
        char c = _getch(); 

        if (c == KEY_w || c == KEY_W)
        { // move up
            selection--;
            if (selection == 0) {
                selection = 4;
            }
            selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == KEY_s || c == KEY_S)
        { // move down
            selection++;
            if (selection == 5) {
                selection = 1;
            }
            selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == ENTER_KEY || c == '\n')
        { // pressed enter
            switch (selection)
            {
            case 1:
                createScreen();
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
                break;
            case 2:
                createScreen();
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
                break;
            case 3:
                clearScreen();
                drawBorder();
                MainMenuBack();
                Sleep(5000);
                break;
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
    int buttonColor = OCEAN;
    int backgroundColor = BLACK;
    string email;
    string text;
    showCursor(0);
    int selection = 1; 
    printMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

    while (true)
    {
        char c = _getch(); 

        if (c == KEY_w || c == KEY_W)
        { // move up
            selection--;
            if (selection == 0) {
                selection = 4;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == KEY_s || c == KEY_S)
        { // move down
            selection++;
            if (selection == 5) {
                selection = 1;
            }
            selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
        }
        else if (c == ENTER_KEY || c == '\n')
        { // pressed enter
            switch (selection)
            {
            case 1:
                createScreen();
                login(email);
                break;
            case 2:
                createScreen();
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
                break;
            case 3:
                createScreen();
                art_at_pos("ascii_art\\credit.txt", LIGHT_GREEN, backgroundColor, 36, 2);
                read_file_at_pos("ascii_art\\content.txt", WHITE, backgroundColor, 4, 12);
                TextColor(LIGHT_GREEN);
                drawRectangle(5, 10, 108, 20);
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
                break;
            case 4:
                clearScreen();
                drawBorder();
                quit();
                exit(1);
                break;
            }
        }
    }
    system("pause");
}
