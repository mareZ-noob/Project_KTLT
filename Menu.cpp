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
    drawRectangle(30, 10, 40, 15);

    moveCursor(35, 11);
    cout << "Login form" << endl;
    moveCursor(14, 32);
    cout << "Email: " << endl;
    moveCursor(16, 32);
    cout << "Please using \"@clc.fitus.edu.vn\" to login";
    moveCursor(19, 49);
    cout << "Enter" << endl;

    moveCursor(14, 39);
    getline(cin, email);
}

void menuSelection()
{
    clearScreen();
    consoleTitle();
    showCursor(0);
    disableMouseInput();
    PlaySound(TEXT(POKEMON_SOUND), NULL, SND_ASYNC);
}

void gameSelection()
{
}
// figlet -f big "Login successful"
void menu(int choice)
{
    while (choice != 2)
    {
        consoleTitle();
        // consoleColor(LIGHT_WHITE, LIGHT_BLUE);
        // clearScreen();
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
            // clearScreen();
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



//Update login function
void login(string& email)
{
	TextColor(0);
	drawRectangle(40, 8, 40, 10);

	button(40, 8, 41, 2, 4, 0, 7, " Enter your email to continue");
	cout << endl;
	moveCursor(42, 12);
	TextColor(4);
	cout << "Email: ";
	moveCursor(48, 12);
	button(48, 11, 30, 2, 0, 0, 7, " ");//Enter your email
	cout << endl;
	moveCursor(43, 15);
	TextColor(4);
	cout << "(Using \"@clc.fitus.edu.vn\" to login)";

	moveCursor(49, 12);
	TextColor(0);
	getline(cin, email);
	if (verify(email))
	{
		while (true)
		{
			char c = _getch(); // wait for a key to be pressed
			if (c == '\r' || c == '\n')
			{
				system("cls");
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


//print buttons on Main Menu
void selectionMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text) {
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
		moveCursor(x, y + 2); cout << char(195);
		moveCursor(x + w, y + 2); cout << char(180);
	}
	else
	{
		button(x, y + 2, w, h, Color, buttonColor, backgroundColor, "       ABOUT");
		moveCursor(x, y + 2); cout << char(195);
		moveCursor(x + w, y + 2); cout << char(180);
	}

	if (selection == 3)
	{
		textColor = 4;
		button(x, y + 4, w, h, textColor, buttonColor, backgroundColor, "    > CREDITS <");
		moveCursor(x, y + 4); cout << char(195);
		moveCursor(x + w, y + 4); cout << char(180);
	}
	else
	{
		button(x, y + 4, w, h, Color, buttonColor, backgroundColor, "      CREDITS");
		moveCursor(x, y + 4); cout << char(195);
		moveCursor(x + w, y + 4); cout << char(180);
	}

	if (selection == 4)
	{
		textColor = 4;
		button(x, y + 6, w, h, textColor, buttonColor, backgroundColor, "     > EXIT <");
		moveCursor(x, y + 6); cout << char(195);
		moveCursor(x + w, y + 6); cout << char(180);
	}
	else
	{
		button(x, y + 6, w, h, Color, buttonColor, backgroundColor, "       EXIT");
		moveCursor(x, y + 6); cout << char(195);
		moveCursor(x + w, y + 6); cout << char(180);
	}
}

//print buttons on Login Menu
void selectionMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text) {
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
		moveCursor(x, y + 2); cout << char(195);
		moveCursor(x + w, y + 2); cout << char(180);
	}
	else
	{
		textColor = Color;
		button(x, y + 2, w, h, Color, buttonColor, backgroundColor, "    HIGH SCORES");
		moveCursor(x, y + 2); cout << char(195);
		moveCursor(x + w, y + 2); cout << char(180);
	}

	if (selection == 3)
	{
		textColor = 4;
		button(x, y + 4, w, h, textColor, buttonColor, backgroundColor, "  > FORGET EMAIL <");
		moveCursor(x, y + 4); cout << char(195);
		moveCursor(x + w, y + 4); cout << char(180);
	}
	else
	{
		textColor = Color;
		button(x, y + 4, w, h, Color, buttonColor, backgroundColor, "    FORGET EMAIL");
		moveCursor(x, y + 4); cout << char(195);
		moveCursor(x + w, y + 4); cout << char(180);
	}

	if (selection == 4)
	{
		textColor = 4;
		button(x, y + 6, w, h, textColor, buttonColor, backgroundColor, "     > BACK <");
		moveCursor(x, y + 6); cout << char(195);
		moveCursor(x + w, y + 6); cout << char(180);
	}
	else
	{
		textColor = Color;
		button(x, y + 6, w, h, Color, buttonColor, backgroundColor, "       BACK");
		moveCursor(x, y + 6); cout << char(195);
		moveCursor(x + w, y + 6); cout << char(180);
	}
}

//print Main Menu
void printMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text) //main menu
{
	system("color 70");
	art_at_pos("pikachu.txt", 0, backgroundColor, 27, 5);
	selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
}

//print Login Menu
void printMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text) //menu when users press "LOGIN"
{
	selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
}

//Print back to Main Menu when press "BACK"
int MainMenuBack() {
	int x = 50; int y = 17;//Toa do cua menu tren cua so Console
	int w = 20;
	int h = 2;
	int textColor = 0;
	int buttonColor = 22;
	int backgroundColor = 7;//system("color");
	string email;
	string text;
	ShowCur(0);
	int selection = 1; // start with the first button selected
	printMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

	while (true)
	{
		char c = _getch(); // wait for a key to be pressed

		if ((c == 'w' or c == 72 or c == 'W') && selection > 1)
		{ // move selection up
			selection--;
			selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
		}
		else if ((c == 's' or c == 80 or c == 'S') && selection < 4)
		{ // move selection down
			selection++;
			selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);;
		}
		else if (c == '\r' || c == '\n')
		{ // user pressed enter, so execute the selected option
			switch (selection)
			{
			case 1:
				system("cls");
				//cout << "You selected LOGIN";
				//Sleep(5000);
				login(email);
				break;
			case 2:
				system("cls");
				cout << "You selected About\n";
				Sleep(5000);
				//break;
			case 3:
				system("cls");
				cout << "You selected Settings\n";
				Sleep(5000);
				break;
			case 4:
				system("cls");
				art("goodbye.txt");
				//Sleep(5000);
				exit(1);
			}
		}
	}
	system("pause");
}

//LOGIN MENU PROGRESSION
void MenuLogin()
{
	int x = 50; int y = 10;//Toa do cua menu tren cua so Console
	int w = 20;
	int h = 2;
	int textColor = 0;
	int buttonColor = 22;
	int backgroundColor = 7;
	string text;
	ShowCur(0);
	int selection = 1; // start with the first button selected
	printMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

	while (true)
	{
		char c = _getch(); // wait for a key to be pressed

		if ((c == 'w' or c == 72 or c == 'W') && selection > 1)
		{ // move selection up
			selection--;
			selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
		}
		else if ((c == 's' or c == 80 or c == 'S') && selection < 4)
		{ // move selection down
			selection++;
			selectionMenuLogin(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
		}
		else if (c == '\r' || c == '\n')
		{ // user pressed enter, so execute the selected option
			switch (selection)
			{
			case 1:
				system("cls");
				cout << "You selected PLAY GAME";
				Sleep(5000);
				break;
			case 2:
				system("cls");
				printLeaderboard();
				break;
			case 3:
				system("cls");
				cout << "You selected Settings\n";
				Sleep(5000);
				break;
			case 4:
				system("cls");
				MainMenuBack();
				Sleep(5000);
			}
		}
	}
	system("pause");
}

//MAIN MENU PROGRESSION
void MainMenu() {
	int x = 50; int y = 17;//Toa do cua menu tren cua so Console
	int w = 20;
	int h = 2;
	int textColor = 0;
	int buttonColor = 22;
	int backgroundColor = 7;//system("color");
	string email;
	string text;
	ShowCur(0);
	int selection = 1; // start with the first button selected
	printMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);

	while (true)
	{
		char c = _getch(); // wait for a key to be pressed

		if ((c == 'w' or c == 72 or c == 'W') && selection > 1)
		{ // move selection up
			selection--;
			selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
		}
		else if ((c == 's' or c == 80 or c == 'S') && selection < 4)
		{ // move selection down
			selection++;
			selectionMenu(selection, x, y, w, h, textColor, buttonColor, backgroundColor, text);
		}
		else if (c == '\r' || c == '\n')
		{ // user pressed enter, so execute the selected option
			switch (selection)
			{
			case 1:
				system("cls");
				//cout << "You selected LOGIN";
				//Sleep(5000);
				login(email);
				break;
			case 2:
				system("cls");
				cout << "You selected About\n";
				Sleep(5000);
				//break;
			case 3:
				system("cls");
				cout << "You selected Settings\n";
				Sleep(5000);
				break;
			case 4:
				system("cls");
				art("goodbye.txt");
				exit(1);
			}
		}
	}
	system("pause");
}
