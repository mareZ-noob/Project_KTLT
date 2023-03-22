#include "Graphic.h"
#include "Setup.h"

void art(string fileName)
{
    ifstream file;
    file.open(fileName);
    string line;
    int i = 12;
    while (getline(file, line))
    {
        moveCursor(i++, 30);
        cout << line << endl;
    }
    file.close();
}
