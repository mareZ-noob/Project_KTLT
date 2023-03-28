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

//Draw art at position (x, y) (Do mấy hôm trước chưa update hàm art nên t làm vậy)
void art_at_pos(string fileName, int textColor, int backgroundColor, int x, int y)
{
	ifstream file;
	file.open(fileName);
	string line;
	while (getline(file, line))
	{
		moveCursor(x, y++);
		BackgroundColor(backgroundColor, textColor);
		TextColor(textColor);
		cout << line << endl;
	}
	file.close();
}
