#ifndef __CHECK_H__
#define _CHECK_H__

#include "Main.h"

// check 1 line
bool checkLineX(Board **board, int y1, int y2, int x);
bool checkLineY(Board **board, int x1, int x2, int y);
bool check_I(Board **board, int x1, int y1, int x2, int y2);

// check 2 lines
bool check_L(Board **board, int x1, int y1, int x2, int y2);

// check 3 lines
bool checkRectX(Board **board, int x1, int y1, int x2, int y2);
bool checkRectY(Board **board, int x1, int y1, int x2, int y2);
bool check_Z(Board **board, int x1, int y1, int x2, int y2);

bool checkMoreLineX(Board **board, int _row, int _col, int x1, int y1, int x2, int y2);
bool checkMoreLineY(Board **board, int _row, int _col, int x1, int y1, int x2, int y2);
bool check_U(Board **board, int _row, int _col, int x1, int y1, int x2, int y2);

// summary
bool check_All(Board **board, int _row, int _col, int x1, int y1, int x2, int y2);
bool checkGameWin(Board **board, int _row, int _col);
bool moveSuggestion(Board **board, int _row, int _col, Point &p1, Point &p2);

#endif // __CHECK_H__