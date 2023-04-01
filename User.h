#ifndef __USER_H__
#define _USER_H__

#include "Main.h"
#include "Graphic.h"

struct Players
{
    char name[20];
    int point;
    int time;
};

bool verify(string email);
bool comparePlayers(const Players &p1, const Players &p2);
long long unsigned int fileSize(string file);
void pushRecord(Players p);
void printLeaderboard();

#endif // __USER_H__