#include "Graphic.h"

void art(string fileName, int pX, int pY)
{
    ifstream file;
    file.open(fileName);
    string line;
    // pY = 13;
    while (getline(file, line))
    {
        moveCursor(pX, pY++);
        cout << line << endl;
    }
    file.close();
}

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
