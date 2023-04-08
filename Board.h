#ifndef __BOARD_H__
#define _BOARD_H__

#include "User.h"
#include "Check.h"

// initial board
void createBox();
void deallocate(Board **board, int _row);
Board **randomize(Board **&board, int _row, int _col);
Board **createBoard(Board **&board, int _row, int _col);
void renderBoard(Board **&board, int _row, int _col);

// effects when matching
void trueMatch(Board **board, int _row, int _col);
void wrongMatch(Board **board, int _row, int _col);
void suggestMatch(Board **board, int _row, int _col);
Board **retreatBoard(Board **&board, int _row, int _col);

#endif // __BOARD_H__