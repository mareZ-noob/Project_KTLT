#include "Graphic.h"
#include "Setup.h"

void art(string fileName)
{
    ifstream file;
    file.open(fileName);
    string line;
    int i = 13;
    while (getline(file, line))
    {
        moveCursor(30, i++);
        cout << line << endl;
    }
    file.close();
}
