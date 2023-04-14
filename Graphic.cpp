#include "Graphic.h"

void art_at_pos(string fileName, int textColor, int backgroundColor, int x, int y)
{
    ifstream file;
    file.open(fileName);
    string line;
    while (getline(file, line))
    {
        moveCursor(x, y++);
        consoleColor(backgroundColor, textColor);
        TextColor(textColor);
        cout << line << endl;
    }
    file.close();
}

void read_file_at_pos(string fileName, int textColor, int backgroundColor, int x, int y)
{
    ifstream file;
    file.open(fileName);
    string text;
    while (getline(file, text))
    {
        moveCursor(x, y++);
        consoleColor(backgroundColor, textColor);
        TextColor(textColor);
        cout << text << endl;
    }
    file.close();
}

void pokemon_ball(int x, int y)
{
    ifstream file("ascii_art\\pokemonball.txt");
    int backgroundColor = BLACK;
    if (file.is_open())
    {
        char c;
        int posX = x, posY = y;
        while (file.get(c))
        {
            if (c == '7')
            {
                consoleColor(backgroundColor, LIGHT_RED);
                moveCursor(posX, posY);
                TextColor(RED);
                cout << c;
                posX++;
            }
            else if (c == 'J')
            {
                consoleColor(backgroundColor, LIGHT_WHITE);
                moveCursor(posX, posY);
                TextColor(LIGHT_WHITE);
                cout << c;
                posX++;
            }
            else if (c == '\n')
            {
                posY++;
                posX = x;
            }
            else
            {
                consoleColor(backgroundColor, GRAY);
                moveCursor(posX, posY);
                TextColor(GRAY);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}

void pikachu_small(int x, int y)
{
    ifstream file("ascii_art\\pikachu_small.txt");
    int backgroundColor = BLACK;
    if (file.is_open())
    {
        char c;
        int posX = x, posY = y;
        while (file.get(c))
        {
            if (c == 'B')
            {
                consoleColor(backgroundColor, LIGHT_YELLOW);
                moveCursor(posX, posY);
                TextColor(LIGHT_YELLOW);
                cout << c;
                posX++;
            }
            else if (c == '5')
            {
                consoleColor(backgroundColor, BLACK);
                moveCursor(posX, posY);
                TextColor(BLACK);
                cout << c;
                posX++;
            }
            else if (c == '8')
            {
                consoleColor(backgroundColor, GRAY);
                moveCursor(posX, posY);
                TextColor(GRAY);
                cout << c;
                posX++;
            }
            else if (c == '7')
            {
                consoleColor(backgroundColor, LIGHT_RED);
                moveCursor(posX, posY);
                TextColor(LIGHT_RED);
                cout << c;
                posX++;
            }
            else if (c == 'P')
            {
                consoleColor(backgroundColor, LIGHT_WHITE);
                moveCursor(posX, posY);
                TextColor(LIGHT_WHITE);
                cout << c;
                posX++;
            }
            else if (c == '\n')
            {
                posY++;
                posX = x;
            }
            else
            {
                consoleColor(backgroundColor, BLACK);
                moveCursor(posX, posY);
                TextColor(BLACK);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}

void login_icon(int x, int y)
{
    ifstream file("ascii_art\\login_icon.txt");
    int backgroundColor = BLACK;
    if (file.is_open())
    {
        char c;
        int posX = x, posY = y;
        while (file.get(c))
        {
            if (c == '@')
            {
                consoleColor(backgroundColor, LIGHT_YELLOW);
                moveCursor(posX, posY);
                TextColor(LIGHT_WHITE);
                cout << c;
                posX++;
            }
            else if (c == 'J')
            {
                consoleColor(backgroundColor, GRAY);
                moveCursor(posX, posY);
                TextColor(GRAY);
                cout << c;
                posX++;
            }
            else if (c == '\n')
            {
                posY++;
                posX = x;
            }
            else
            {
                consoleColor(backgroundColor, LIGHT_WHITE);
                moveCursor(posX, posY);
                TextColor(BLACK);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}

void pikachu_ava(int x, int y)
{
    ifstream file("ascii_art\\pikachu_ava.txt");
    int backgroundColor = BLACK;
    if (file.is_open())
    {
        char c;
        int posX = x, posY = y;
        while (file.get(c))
        {
            if (c == 'B' || c == 'G')
            {
                consoleColor(backgroundColor, LIGHT_YELLOW);
                moveCursor(posX, posY);
                TextColor(LIGHT_YELLOW);
                cout << c;
                posX++;
            }
            else if (c == 'J')
            {
                consoleColor(backgroundColor, LIGHT_RED);
                moveCursor(posX, posY);
                TextColor(LIGHT_RED);
                cout << c;
                posX++;
            }
            else if (c == 'P')
            {
                consoleColor(backgroundColor, LIGHT_WHITE);
                moveCursor(posX, posY);
                TextColor(LIGHT_WHITE);
                cout << c;
                posX++;
            }
            else if (c == 'F')
            {
                consoleColor(backgroundColor, GRAY);
                moveCursor(posX, posY);
                TextColor(GRAY);
                cout << c;
                posX++;
            }
            else if (c == '\n')
            {
                posY++;
                posX = x;
            }
            else
            {
                consoleColor(backgroundColor, BLACK);
                moveCursor(posX, posY);
                TextColor(BLACK);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}

void charmander_ava(int x, int y)
{
    ifstream file("ascii_art\\charmander_ava.txt");
    int backgroundColor = BLACK;
    if (file.is_open())
    {
        char c;
        int posX = x, posY = y;
        while (file.get(c))
        {
            if (c == '5')
            {
                consoleColor(backgroundColor, YELLOW);
                moveCursor(posX, posY);
                TextColor(YELLOW);
                cout << c;
                posX++;
            }
            else if (c == 'J')
            {
                consoleColor(backgroundColor, LIGHT_RED);
                moveCursor(posX, posY);
                TextColor(LIGHT_RED);
                cout << c;
                posX++;
            }
            else if (c == 'Y')
            {
                consoleColor(backgroundColor, GREEN);
                moveCursor(posX, posY);
                TextColor(GREEN);
                cout << c;
                posX++;
            }
            else if (c == '!')
            {
                consoleColor(backgroundColor, LIGHT_WHITE);
                moveCursor(posX, posY);
                TextColor(LIGHT_WHITE);
                cout << c;
                posX++;
            }
            else if (c == '\n')
            {
                posY++;
                posX = x;
            }
            else
            {
                consoleColor(backgroundColor, BLACK);
                moveCursor(posX, posY);
                TextColor(BLACK);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}

void bulbasaur_ava(int x, int y)
{
    ifstream file("ascii_art\\bulbasaur_ava.txt");
    int backgroundColor = BLACK;
    if (file.is_open())
    {
        char c;
        int posX = x, posY = y;
        while (file.get(c))
        {
            if (c == 'G')
            {
                consoleColor(backgroundColor, CYAN);
                moveCursor(posX, posY);
                TextColor(CYAN);
                cout << c;
                posX++;
            }
            else if (c == '5')
            {
                consoleColor(backgroundColor, GREEN);
                moveCursor(posX, posY);
                TextColor(GREEN);
                cout << c;
                posX++;
            }
            else if (c == '@')
            {
                consoleColor(backgroundColor, LIGHT_WHITE);
                moveCursor(posX, posY);
                TextColor(LIGHT_WHITE);
                cout << c;
                posX++;
            }
            else if (c == 'J' || c == 'Q')
            {
                consoleColor(backgroundColor, LIGHT_RED);
                moveCursor(posX, posY);
                TextColor(LIGHT_RED);
                cout << c;
                posX++;
            }
            else if (c == 'S')
            {
                consoleColor(backgroundColor, GRAY);
                moveCursor(posX, posY);
                TextColor(GRAY);
                cout << c;
                posX++;
            }
            else if (c == '\n')
            {
                posY++;
                posX = x;
            }
            else
            {
                consoleColor(backgroundColor, BLACK);
                moveCursor(posX, posY);
                TextColor(BLACK);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}

void clefairy_ava(int x, int y)
{
    ifstream file("ascii_art\\clefairy_ava.txt");
    int backgroundColor = BLACK;
    if (file.is_open())
    {
        char c;
        int posX = x, posY = y;
        while (file.get(c))
        {
            if (c == 'B')
            {
                consoleColor(backgroundColor, MAGENTA);
                moveCursor(posX, posY);
                TextColor(MAGENTA);
                cout << c;
                posX++;
            }
            else if (c == 'P')
            {
                consoleColor(backgroundColor, LIGHT_WHITE);
                moveCursor(posX, posY);
                TextColor(LIGHT_WHITE);
                cout << c;
                posX++;
            }
            else if (c == 'J')
            {
                consoleColor(backgroundColor, LIGHT_RED);
                moveCursor(posX, posY);
                TextColor(LIGHT_RED);
                cout << c;
                posX++;
            }
            else if (c == '\n')
            {
                posY++;
                posX = x;
            }
            else
            {
                consoleColor(backgroundColor, BLACK);
                moveCursor(posX, posY);
                TextColor(BLACK);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}

void pikachu_bye(int x, int y)
{
    ifstream file("ascii_art\\pikachu_bye.txt");
    int backgroundColor = BLACK;
    if (file.is_open())
    {
        char c;
        int posX = x, posY = y;
        while (file.get(c))
        {
            if (c == 'B' || c == 'G')
            {
                consoleColor(backgroundColor, LIGHT_YELLOW);
                moveCursor(posX, posY);
                TextColor(LIGHT_YELLOW);
                cout << c;
                posX++;
            }
            else if (c == 'J')
            {
                consoleColor(backgroundColor, LIGHT_RED);
                moveCursor(posX, posY);
                TextColor(LIGHT_RED);
                cout << c;
                posX++;
            }
            else if (c == 'W')
            {
                consoleColor(backgroundColor, OCEAN);
                moveCursor(posX, posY);
                TextColor(OCEAN);
                cout << c;
                posX++;
            }
            else if (c == 'R')
            {
                consoleColor(backgroundColor, GRAY);
                moveCursor(posX, posY);
                TextColor(GRAY);
                cout << c;
                posX++;
            }
            else if (c == '\n')
            {
                posY++;
                posX = x;
            }
            else
            {
                consoleColor(backgroundColor, LIGHT_WHITE);
                moveCursor(posX, posY);
                TextColor(LIGHT_WHITE);
                cout << c;
                posX++;
            }
        }
        file.close();
    }
}