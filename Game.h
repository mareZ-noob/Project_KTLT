#ifndef __GAME_H__
#define _GAME_H__

#include "Board.h"

// game loop
void gameLoop(Board **&board, int _row, int _col, Players &p, int &life, Settings &sett, int &gameStatus, Point &curPos, int &couple, Point select[2]);
void playerInformation();

// normal mode
void normalForm(Players &p);
void normalGame(Players &p, int choice);

// custom mode
void customForm(Board &_size, Players &p, Settings &sett);
void customGame(Players &p);

#endif // __GAME_H__