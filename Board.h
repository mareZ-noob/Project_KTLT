#ifndef __BOARD_H__
#define _BOARD_H__

#include "Main.h"
#include "Setup.h"
#include "User.h"
#include "CHeck.h"

void createBox();
void deallocate(Board **board, int _row);
Board **randomize(Board **&board, int _row, int _col);
Board **createBoard(Board **&board, int _row, int _col);
void renderBoard(Board **&board, int _row, int _col);

#endif // __BOARD_H__