#include "Board.h"

char s[3][6];
void createBox()
{
	s[0][0] = char(218);
	s[0][1] = s[0][2] = s[0][3] = char(196);
	s[0][4] = char(191);
	s[1][0] = char(179);
	s[1][1] = s[1][2] = s[1][3] = ' ';
	s[1][4] = char(179);
	s[2][0] = char(192);
	s[2][1] = s[2][2] = s[2][3] = char(196);
	s[2][4] = char(217);
}

void Board::drawBox(Board **&board)
{
	createBox();
	int posX = col + 1;
	int posY = row + 1;

	if (board[row][col].status == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			consoleColor(BLACK, YELLOW);
			moveCursor(posX * 6, posY * 3 + i - 1);
			cout << s[i];
		}
		consoleColor(BLACK, WHITE);
		moveCursor(posX * 6 + 2, posY * 3);
		printf("%c", board[row][col].ch);
		consoleColor(BLACK, WHITE);
	}
	else if (board[row][col].status == 1)
	{
		for (int i = 0; i < 3; i++)
		{
			consoleColor(BLACK, YELLOW);
			moveCursor(posX * 6, posY * 3 + i - 1);
			cout << s[i];
		}
		consoleColor(WHITE, BLUE);
		moveCursor(posX * 6 + 1, posY * 3);
		printf("   ");
		moveCursor(posX * 6 + 2, posY * 3);
		printf("%c", board[row][col].ch);
		consoleColor(BLACK, WHITE);
	}
	else if (board[row][col].status == 2)
	{
		for (int i = 0; i < 3; i++)
		{
			moveCursor(posX * 6, posY * 3 + i - 1);
			printf("     ");
		}
	}
	else if (board[row][col].status == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			consoleColor(BLACK, YELLOW);
			moveCursor(posX * 6, posY * 3 + i - 1);
			cout << s[i];
		}
		consoleColor(CYAN, RED);
		moveCursor(posX * 6 + 1, posY * 3);
		printf("   ");
		moveCursor(posX * 6 + 2, posY * 3);
		printf("%c", board[row][col].ch);
		consoleColor(BLACK, WHITE);
	}
}

void deallocate(Board **board, int _row)
{
	for (int i = 0; i < _row; i++)
	{
		delete[] board[i];
	}
	delete[] board;
	board = nullptr;
}

Board **randomize(Board **&board, int _row, int _col)
{
	srand(time(0));
	// 1D from vector
	vector<Board> vec;
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			vec.push_back(board[i][j]);
		}
	}

	// Random
	random_shuffle(vec.begin(), vec.end());

	// Push again
	int index = 0;
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			board[i][j] = vec[index++];
		}
	}
	return board;
}

Board **createBoard(Board **&board, int _row, int _col)
{
	board = new Board *[_row];
	for (int i = 0; i < _row; i++)
	{
		board[i] = new Board[_col];
		for (int j = 0; j < _col; j++)
		{
			board[i][j].row = i;
			board[i][j].col = j;
		}
	}

	// make the chars even
	if (_col & 1) // _col is odd
	{
		for (int i = 0; i <= _row / 2; i++)
		{
			for (int j = 0; j < _col; j++)
			{
				board[i][j].ch = 65 + rand() % 26;
				board[_row - i - 1][_col - j - 1].ch = board[i][j].ch;
			}
		}
	}
	else // _col is even
	{
		for (int i = 0; i < _row; i++)
		{
			for (int j = 0; j <= _col / 2; j++)
			{
				board[i][j].ch = 65 + rand() % 26;
				board[i][_col - j - 1].ch = board[i][j].ch;
			}
		}
	}
	randomize(board, _row, _col);
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			board[i][j].status = 0;
		}
	}
	return board;
}

void renderBoard(Board **&board, int _row, int _col)
{
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			board[i][j].drawBox(board);
		}
	}
}
