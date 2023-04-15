#include "Game.h"

void gameLoop(Board **&board, int _row, int _col, Players &p, int &life, Settings &sett, int &gameStatus, Point &curPos, int &couple, Point select[2])
{
	Point pCheck1, pCheck2;
	// win
	if (checkGameWin(board, _row, _col))
		gameStatus = 0;
	// shuffle when no valid moves
	else if (!moveSuggestion(board, _row, _col, pCheck1, pCheck2))
	{
		board[curPos.x][curPos.y].status = 0;
		moveCursor(26, 1);
		consoleColor(BLACK, LIGHT_RED);
		printf("The board will be shuffled again because there are no valid moves!");
		Sleep(2000);
		consoleColor(BLACK, WHITE);
		moveCursor(26, 1);

		printf("                                                                  ");
		randomize(board, _row, _col);

		bool valid = false;
		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j < _col; j++)
			{
				if (board[i][j].status != 2 && board[i][j].status != 1)
				{
					valid = true;
					curPos.x = i;
					curPos.y = j;
					break;
				}
			}
			if (valid)
				break;
		}
		if (valid)
			board[curPos.x][curPos.y].status = 1;
		else
			board[curPos.x][curPos.y].status = 2;
	}
	else
	{
		int _ch = _getch();

		if (_ch == ESC_KEY)
		{
			gameStatus = 2;
			clearScreen();
		}
		else if (_ch == KEY_w || _ch == KEY_W)
		{ // up
			board[curPos.x][curPos.y].status = 0;
			bool check = false;
			for (int j = curPos.y; j < curPos.y + 1; j++)
			{
				for (int i = curPos.x - 1; i >= 0; i--)
				{
					if (board[i][j].status != 2 && board[i][j].status != 1)
					{
						check = true;
						curPos.x = i;
						curPos.y = j;
						break;
					}
				}
			}
			if (!check)
			{
				for (int j = curPos.y - 1; j >= 0; j--)
				{
					for (int i = _row - 1; i >= 0; i--)
					{
						if (board[i][j].status != 2 && board[i][j].status != 1)
						{
							check = true;
							curPos.x = i;
							curPos.y = j;
							break;
						}
					}
					if (check)
						break;
				}
			}
			if (!check)
			{
				for (int j = _col - 1; j >= curPos.y; j--)
				{
					for (int i = _row - 1; i >= 0; i--)
					{
						if (board[i][j].status != 2 && board[i][j].status != 1)
						{
							check = true;
							curPos.x = i;
							curPos.y = j;
							break;
						}
					}
					if (check)
						break;
				}
			}
			if (sett.music)
				PlaySound(TEXT(MOVE_SOUND), NULL, SND_ASYNC);
			board[curPos.x][curPos.y].status = 1;
		}
		else if (_ch == KEY_s || _ch == KEY_S)
		{ // down
			board[curPos.x][curPos.y].status = 0;
			bool check = false;
			for (int j = curPos.y; j < curPos.y + 1; j++)
			{
				for (int i = curPos.x + 1; i < _row; i++)
				{
					if (board[i][j].status != 2 && board[i][j].status != 1)
					{
						check = true;
						curPos.x = i;
						curPos.y = j;
						break;
					}
				}
			}
			if (!check)
			{
				for (int j = curPos.y + 1; j < _col; j++)
				{
					for (int i = 0; i < _row; i++)
					{
						if (board[i][j].status != 2 && board[i][j].status != 1)
						{
							check = true;
							curPos.x = i;
							curPos.y = j;
							break;
						}
					}
					if (check)
						break;
				}
			}
			if (!check)
			{
				for (int j = 0; j <= curPos.y; j++)
				{
					for (int i = 0; i < _row; i++)
					{
						if (board[i][j].status != 2 && board[i][j].status != 1)
						{
							check = true;
							curPos.x = i;
							curPos.y = j;
							break;
						}
					}
					if (check)
						break;
				}
			}
			if (sett.music)
				PlaySound(TEXT(MOVE_SOUND), NULL, SND_ASYNC);
			board[curPos.x][curPos.y].status = 1;
		}
		else if (_ch == KEY_a || _ch == KEY_A)
		{ // left
			board[curPos.x][curPos.y].status = 0;
			bool check = false;

			for (int i = curPos.x; i < curPos.x + 1; i++)
			{
				for (int j = curPos.y - 1; j >= 0; j--)
				{
					if (board[i][j].status != 2 && board[i][j].status != 1)
					{
						check = true;
						curPos.x = i;
						curPos.y = j;
						break;
					}
				}
			}

			if (!check)
			{
				for (int i = curPos.x - 1; i >= 0; i--)
				{
					for (int j = _col - 1; j >= 0; j--)
					{
						if (board[i][j].status != 2 && board[i][j].status != 1)
						{
							check = true;
							curPos.x = i;
							curPos.y = j;
							break;
						}
					}
					if (check)
						break;
				}
			}
			if (!check)
			{
				for (int i = _row - 1; i >= curPos.x; i--)
				{
					for (int j = _col - 1; j >= 0; j--)
					{
						if (board[i][j].status != 2 && board[i][j].status != 1)
						{
							check = true;
							curPos.x = i;
							curPos.y = j;
							break;
						}
					}
					if (check)
						break;
				}
			}
			if (sett.music)
				PlaySound(TEXT(MOVE_SOUND), NULL, SND_ASYNC);
			board[curPos.x][curPos.y].status = 1;
		}
		else if (_ch == KEY_d || _ch == KEY_D)
		{ // right
			board[curPos.x][curPos.y].status = 0;
			bool check = false;

			for (int i = curPos.x; i < curPos.x + 1; i++)
			{
				for (int j = curPos.y + 1; j < _col; j++)
				{
					if (board[i][j].status != 2 && board[i][j].status != 1)
					{
						check = true;
						curPos.x = i;
						curPos.y = j;
						break;
					}
				}
			}

			if (!check)
			{
				for (int i = curPos.x + 1; i < _row; i++)
				{
					for (int j = 0; j < _col; j++)
					{
						if (board[i][j].status != 2 && board[i][j].status != 1)
						{
							check = true;
							curPos.x = i;
							curPos.y = j;
							break;
						}
					}
					if (check)
						break;
				}
			}
			if (!check)
			{
				for (int i = 0; i <= curPos.x; i++)
				{
					for (int j = 0; j < _col; j++)
					{
						if (board[i][j].status != 2 && board[i][j].status != 1)
						{
							check = true;
							curPos.x = i;
							curPos.y = j;
							break;
						}
					}
					if (check)
						break;
				}
			}
			if (sett.music)
				PlaySound(TEXT(MOVE_SOUND), NULL, SND_ASYNC);
			board[curPos.x][curPos.y].status = 1;
		}
		else if (_ch == KEY_h || _ch == KEY_H)
		{ // hint
			Point p1, p2;
			if (sett.music)
				PlaySound(TEXT(MOVE_SOUND), NULL, SND_ASYNC);

			if (moveSuggestion(board, _row, _col, p1, p2))
			{
				suggestMatch(board, p1.x, p1.y);
				suggestMatch(board, p2.x, p2.y);
				Sleep(500);
				consoleColor(BLACK, WHITE);
			}
			// refresh point
			moveCursor(90, 22);
			printf("              ");
			p.point -= 5;
			moveCursor(90, 22);
			if (p.point > 1)
				printf("%d points", p.point);
			else
				printf("%d point", p.point);
		}
		else if (_ch == KEY_r || _ch == KEY_R)
		{ // random board
			board[curPos.x][curPos.y].status = 0;
			randomize(board, _row, _col);

			// refresh point
			// moveCursor(90, 22);
			// printf("              ");
			// p.point -= 10;
			// moveCursor(90, 22);
			// if (p.point > 1)
			// 	printf("%d points", p.point);
			// else
			// 	printf("%d point", p.point);
			bool valid = false;
			for (int i = 0; i < _row; i++)
			{
				for (int j = 0; j < _col; j++)
				{
					if (board[i][j].status != 2 && board[i][j].status != 1)
					{
						valid = true;
						curPos.x = i;
						curPos.y = j;
						break;
					}
				}
				if (valid)
					break;
			}
			if (valid)
				board[curPos.x][curPos.y].status = 1;
			else
				board[curPos.x][curPos.y].status = 2;

			if (sett.music)
				PlaySound(TEXT(MOVE_SOUND), NULL, SND_ASYNC);
		}
		else if (_ch == KEY_m || _ch == KEY_M)
		{ // mute/unmute
			if (sett.music)
			{
				sett.music = 0;
				moveCursor(89, 9);
				printf("Off  ");
			}
			else
			{
				sett.music = 1;
				moveCursor(89, 9);
				printf("On   ");
			}
			if (sett.music)
				PlaySound(TEXT(MOVE_SOUND), NULL, SND_ASYNC);
		}
		else if (_ch == ENTER_KEY)
		{
			if (couple == 2)
			{
				select[0].x = curPos.x;
				select[0].y = curPos.y;
				couple--;
				if (sett.music)
					PlaySound(TEXT(MOVE_SOUND), NULL, SND_ASYNC);
			}
			else if (couple == 1)
			{
				select[1].x = curPos.x;
				select[1].y = curPos.y;
				if (sett.music)
					PlaySound(TEXT(MOVE_SOUND), NULL, SND_ASYNC);
				// refresh point
				moveCursor(90, 22);
				printf("              ");

				// refresh matching type
				moveCursor(97, 20);
				printf("              ");

				if (check_All(board, _row, _col, select[0].x, select[0].y, select[1].x, select[1].y))
				{
					if (check_I(board, select[0].x, select[0].y, select[1].x, select[1].y))
					{
						moveCursor(97, 20);
						printf("I Matching");
					}
					else if (check_L(board, select[0].x, select[0].y, select[1].x, select[1].y))
					{
						moveCursor(97, 20);
						printf("L Matching");
					}
					else if (check_Z(board, select[0].x, select[0].y, select[1].x, select[1].y))
					{
						moveCursor(97, 20);
						printf("Z Matching");
					}
					else
					{
						moveCursor(97, 20);
						printf("U Matching");
					}
					trueMatch(board, select[0].x, select[0].y);
					trueMatch(board, select[1].x, select[1].y);

					if (sett.music)
						PlaySound(TEXT(CORRECT_SOUND), NULL, SND_ASYNC);

					p.point += 20;
					moveCursor(90, 22);
					if (p.point > 1)
						printf("%d points", p.point);
					else
						printf("%d point", p.point);

					Sleep(1000);
					board[select[0].x][select[0].y].status = 2;
					board[select[1].x][select[1].y].status = 2;

					if (sett.gameMode == 1)
						randomize(board, _row, _col);
					else if (sett.gameMode == 2)
						retreatBoard(board, _row, _col);
				}
				else
				{
					wrongMatch(board, select[0].x, select[0].y);
					wrongMatch(board, select[1].x, select[1].y);

					if (sett.music)
						PlaySound(TEXT(SIU_SOUND), NULL, SND_ASYNC);

					board[select[0].x][select[0].y].status = 0;
					board[select[1].x][select[1].y].status = 0;
					p.point -= 5;

					moveCursor(90, 22);
					if (p.point > 1)
						printf("%d points", p.point);
					else
						printf("%d point", p.point);

					moveCursor(97, 20);
					printf("Wrong Matching");

					moveCursor(90, 18);
					printf("%d", --life);
					Sleep(1000);

					if (sett.gameMode == 1)
						randomize(board, _row, _col);
					else if (sett.gameMode == 2)
						retreatBoard(board, _row, _col);
				}
				couple = 2;
			}
			bool valid = false;
			for (int i = 0; i < _row; i++)
			{
				for (int j = 0; j < _col; j++)
				{
					if (board[i][j].status != 2 && board[i][j].status != 1)
					{
						valid = true;
						curPos.x = i;
						curPos.y = j;
						break;
					}
				}
				if (valid)
					break;
			}
			if (valid)
				board[curPos.x][curPos.y].status = 1;
			else
				board[curPos.x][curPos.y].status = 2;
		}
	}
}

// display information in game
void playerInformation()
{
	// display name, music on screen
	showCursor(0);
	TextColor(LIGHT_WHITE);
	drawRectangle(80, 3, 36, 8);
	button(80, 3, 37, 2, LIGHT_RED, LIGHT_WHITE, BLACK, "        PLAYER'S INFORMATION");
	moveCursor(80, 5);
	cout << char(195);
	moveCursor(117, 5);
	cout << char(180);

	TextColor(CYAN);
	moveCursor(82, 7);
	printf("Player's name:");
	moveCursor(82, 9);
	printf("Music:");

	// display lives, type of match, scores on screen
	TextColor(LIGHT_WHITE);
	drawRectangle(80, 14, 36, 10);
	button(80, 14, 37, 2, LIGHT_RED, LIGHT_WHITE, BLACK, "            GAME STATUS");
	moveCursor(80, 16);
	cout << char(195);
	moveCursor(117, 16);
	cout << char(180);

	TextColor(CYAN);
	moveCursor(82, 18);
	printf("Lives:");
	moveCursor(82, 20);
	printf("Type of match:");
	moveCursor(82, 22);
	printf("Scores:");

	// key sign guide
	button(80, 26, 11, 2, MAGENTA, LIGHT_WHITE, BLACK, " H : Hint");
	button(102, 26, 13, 2, LIGHT_GREEN, LIGHT_WHITE, BLACK, " R : Random");
	button(80, 29, 20, 2, LIGHT_YELLOW, LIGHT_WHITE, BLACK, " M : Mute / Unmute");
	button(102, 29, 13, 2, LIGHT_RED, LIGHT_WHITE, BLACK, " ESC : EXIT");
}

void normalForm(Players &p)
{
	showCursor(1);
	TextColor(CYAN);
	drawRectangle(28, 12, 57, 4);
	button(54, 13, 31, 2, LIGHT_WHITE, CYAN, BLACK, " ");
	TextColor(LIGHT_YELLOW);
	moveCursor(30, 14);
	printf("Enter your name/handle:");
	TextColor(LIGHT_WHITE);
	moveCursor(56, 14);
	cin.getline(p.name, 20);
	p.point = 0;
	p.time = 0;
}

void normalGame(Players &p, int choice)
{
	clearScreen();
	drawBorder();
	Board _size;
	Settings sett;
	sett.music = 1;
	if (choice == 1)
	{
		_size.row = _size.col = 4;
		sett.gameMode = 0;
	}
	else if (choice == 2)
	{
		_size.row = _size.col = 8;
		sett.gameMode = 1;
	}
	else if (choice == 3)
	{
		_size.row = _size.col = 10;
		sett.gameMode = 2;
	}

	normalForm(p);
	clearScreen();

	drawBorder();
	playerInformation();

	Board **board = new Board *[_size.row * _size.col + 1];
	board = createBoard(board, _size.row, _size.col);
	Point curPos, select[2];
	curPos.x = curPos.y = 0;
	board[curPos.x][curPos.y].status = 1;

	int life = 5;
	int couple = 2;
	int gameStatus = 1;
	bool win = false;
	/*
	 gameStatus = 0 -> end game
	 gameStatus = 1 -> in game
	 gameStatus = 2 -> escape
	*/

	moveCursor(97, 7);
	printf("%s", p.name);
	moveCursor(89, 9);
	printf("On   ");
	moveCursor(90, 18);
	printf("%d", life);
	moveCursor(90, 22);
	printf("%d point", p.point);
	moveCursor(97, 20);
	printf("No Matching");

	clock_t time_req;
	time_req = clock();
	while ((gameStatus & 1) && life)
	{
		renderBoard(board, _size.row, _size.col);
		gameLoop(board, _size.row, _size.col, p, life, sett, gameStatus, curPos, couple, select);
		if (checkGameWin(board, _size.row, _size.col))
		{
			win = true;
			gameStatus = 0;
		}
	}
	time_req = clock() - time_req;
	p.time = time_req / CLOCKS_PER_SEC;
	pushRecord(p);
	clearScreen();
	moveCursor(10, 0);
	if (gameStatus == 2)
	{
		clearScreen();
		createScreen();
		moveCursor(50,13);
		cout << "Your name: " << p.name << endl;
		moveCursor(50,14);
		cout << "Your scores: " << p.point << endl;
		moveCursor(50,15);
		cout << "Lifes remain: " << life << endl;
		moveCursor(50,16);
		cout << "Total time: " << p.time;
		Sleep(3000);
		clearScreen();
		return printLeaderboard();
	}
	else if (!win)
	{
		if (sett.music)
			PlaySound(TEXT(LOSE_SOUND), NULL, SND_ASYNC);
		clearScreen();
		createScreen();
		moveCursor(50,13);
		cout << "Your name: " << p.name << endl;
		moveCursor(50,14);
		cout << "Your scores: " << p.point << endl;
		moveCursor(50,15);
		cout << "Lifes remain: " << life << endl;
		moveCursor(50,16);
		cout << "Total time: " << p.time;
		Sleep(3000);
		clearScreen();
		read_file_at_pos("ascii_art\\youlose.txt", LIGHT_RED, BLACK, 18, 10);
	}
	else if (win)
	{
		if (sett.music)
			PlaySound(TEXT(GLORY_SOUND), NULL, SND_ASYNC);
		clearScreen();
		createScreen();
		moveCursor(50,13);
		cout << "Your name: " << p.name << endl;
		moveCursor(50,14);
		cout << "Your scores: " << p.point << endl;
		moveCursor(50,15);
		cout << "Lifes remain: " << life << endl;
		moveCursor(50,16);
		cout << "Total time: " << p.time;
		Sleep(3000);
		clearScreen();
		read_file_at_pos("ascii_art\\youwin.txt", LIGHT_GREEN, BLACK, 22, 10);
	}
	showCursor(1);
	TextColor(LIGHT_WHITE);
	moveCursor(40, 19);
	printf("Do you want to play again?(Y/N)");

	moveCursor(72, 19);
	char c;
	cin >> c;
	showCursor(0);
	if (c == 'y' || c == 'Y')
	{
		cin.ignore();
		return normalGame(p, choice);
	}
	else if (c == 'n' || c == 'N')
	{
		cin.ignore();
		printLeaderboard();
	}

	deallocate(board, _size.row);
}

// display custom board
void customForm(Board &_size, Players &p, Settings &sett)
{
	TextColor(CYAN);
	drawRectangle(30, 10, 60, 14);
	button(30, 10, 61, 2, LIGHT_RED, CYAN, BLACK, " Customize your game:");
	moveCursor(30, 12);
	cout << char(195);
	moveCursor(91, 12);
	cout << char(180);

	button(58, 14, 31, 2, LIGHT_WHITE, CYAN, BLACK, " "); // name
	button(46, 18, 4, 2, LIGHT_WHITE, CYAN, BLACK, " ");  // rows
	button(71, 18, 4, 2, LIGHT_WHITE, CYAN, BLACK, " ");  // columns
	button(85, 21, 4, 2, LIGHT_WHITE, CYAN, BLACK, " ");  // shuffle(Y/N)

	TextColor(LIGHT_YELLOW);
	moveCursor(32, 15);
	printf("- Enter your name/handle: ");
	moveCursor(32, 19);
	printf("- Enter rows:");
	moveCursor(54, 19);
	printf("- Enter columns:");
	moveCursor(32, 22);
	printf("- Do you want to shuffle board after each move?(Y/N):");
	TextColor(RED);
	moveCursor(20, 30);
	printf("*NOTE: Please enter at least one even number in rows/columns to play game!");
	moveCursor(34, 32);
	printf("Rows & Columns must be positive integers from 1 to 10");

	showCursor(1);
	moveCursor(60, 15);
	TextColor(LIGHT_WHITE);
	cin.getline(p.name, 20);
	p.point = 0;
	p.time = 0;
	moveCursor(48, 19);
	cin >> _size.row;
	moveCursor(73, 19);
	cin >> _size.col;
	while (((_size.row * _size.col) & 1) || (_size.col <= 0) || (_size.row <= 0) || (_size.col > 10) || (_size.row > 10))
	{
		moveCursor(43, 27);
		TextColor(LIGHT_RED);
		printf("Please enter rows & columns again!");
		Sleep(2000);
		moveCursor(43, 27);
		printf("                                  ");

		TextColor(LIGHT_WHITE);
		moveCursor(48, 19);
		printf("  ");
		moveCursor(73, 19);
		printf("  ");

		moveCursor(48, 19);
		cin >> _size.row;
		moveCursor(73, 19);
		cin >> _size.col;
	}
	cin.ignore();
	moveCursor(87, 22);
	char mode;
	cin >> mode;
	if (mode == 'y' || mode == 'Y')
		sett.gameMode = 1;
	else if (mode == 'n' || mode == 'N')
		sett.gameMode = 0;
	sett.music = 1;
}

void customGame(Players &p)
{
	clearScreen();
	drawBorder();
	Board _size;
	Settings sett;
	customForm(_size, p, sett);
	clearScreen();

	drawBorder();
	playerInformation();

	Board **board = new Board *[_size.row * _size.col + 1];
	board = createBoard(board, _size.row, _size.col);
	Point curPos, select[2];
	curPos.x = curPos.y = 0;
	board[curPos.x][curPos.y].status = 1;

	int life = 5;
	int couple = 2;
	int gameStatus = 1;
	bool win = false;
	/*
	 gameStatus = 0 -> end game
	 gameStatus = 1 -> in game
	 gameStatus = 2 -> escape
	*/

	moveCursor(97, 7);
	printf("%s", p.name);
	moveCursor(89, 9);
	printf("On   ");
	moveCursor(90, 18);
	printf("%d", life);
	moveCursor(90, 22);
	printf("%d point", p.point);
	moveCursor(97, 20);
	printf("No Matching");

	clock_t time_req;
	time_req = clock();
	while ((gameStatus & 1) && life)
	{
		renderBoard(board, _size.row, _size.col);
		gameLoop(board, _size.row, _size.col, p, life, sett, gameStatus, curPos, couple, select);
		if (checkGameWin(board, _size.row, _size.col))
		{
			win = true;
			gameStatus = 0;
		}
	}
	time_req = clock() - time_req;
	p.time = time_req / CLOCKS_PER_SEC;
	pushRecord(p);

	clearScreen();
	if (gameStatus == 2)
	{
		clearScreen();
		createScreen();
		moveCursor(50,13);
		cout << "Your name: " << p.name << endl;
		moveCursor(50,14);
		cout << "Your scores: " << p.point << endl;
		moveCursor(50,15);
		cout << "Lifes remain: " << life << endl;
		moveCursor(50,16);
		cout << "Total time: " << p.time;
		Sleep(3000);
		clearScreen();
		return printLeaderboard();
	}
	else if (!win)
	{
		if (sett.music)
			PlaySound(TEXT(LOSE_SOUND), NULL, SND_ASYNC);
		clearScreen();
		createScreen();
		moveCursor(50,13);
		cout << "Your name: " << p.name << endl;
		moveCursor(50,14);
		cout << "Your scores: " << p.point << endl;
		moveCursor(50,15);
		cout << "Lifes remain: " << life << endl;
		moveCursor(50,16);
		cout << "Total time: " << p.time;
		Sleep(3000);
		clearScreen();
		read_file_at_pos("ascii_art\\youlose.txt", LIGHT_RED, BLACK, 18, 10);
	}
	else if (win)
	{
		if (sett.music)
			PlaySound(TEXT(GLORY_SOUND), NULL, SND_ASYNC);
		clearScreen();
		createScreen();
		moveCursor(50,13);
		cout << "Your name: " << p.name << endl;
		moveCursor(50,14);
		cout << "Your scores: " << p.point << endl;
		moveCursor(50,15);
		cout << "Lifes remain: " << life << endl;
		moveCursor(50,16);
		cout << "Total time: " << p.time;
		Sleep(3000);
		clearScreen();
		read_file_at_pos("ascii_art\\youwin.txt", LIGHT_GREEN, BLACK, 22, 10);
	}
	showCursor(1);
	TextColor(LIGHT_WHITE);
	moveCursor(40, 19);
	printf("Do you want to play again?(Y/N)");

	moveCursor(72, 19);
	char c;
	cin >> c;
	showCursor(0);
	if (c == 'y' || c == 'Y')
	{
		cin.ignore();
		return customGame(p);
	}
	else if (c == 'n' || c == 'N')
	{
		cin.ignore();
		printLeaderboard();
	}

	deallocate(board, _size.row);
}