#ifndef __CHECK_H__
#define _CHECK_H__

#include "Main.h"

struct Point
{
    int x, y;
};

struct Board
{
	int row, col;
	char ch = ' ';
	int status;
	/*
	status = 0 -> unchoose
	status = 1 -> choose
	status = 2 -> box which deleted
	status = 4 -> suggest move
	*/
	void drawBox(Board **&board);
	void showBackground();
};

bool checkLineX(Board **board, int y1, int y2, int x);
bool checkLineY(Board **board, int x1, int x2, int y);
bool check_I(Board **board, int x1, int y1, int x2, int y2);
bool check_L(Board **board, int x1, int y1, int x2, int y2);
bool checkRectX(Board **board, int x1, int y1, int x2, int y2);
bool checkRectY(Board **board, int x1, int y1, int x2, int y2);
bool check_Z(Board **board, int x1, int y1, int x2, int y2);
bool check_U(Board **board, int _row, int _col, int x1, int y1, int x2, int y2);
bool check_All(Board **board, int _row, int _col, int x1, int y1, int x2, int y2);
bool checkGameWin(Board **board, int _row, int _col);

#endif // __CHECK_H__