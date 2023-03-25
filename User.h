#ifndef __USER_H__
#define _USER_H__

#include "Main.h"

struct Players {
    char name[50];
    int point;
    int time;
};

bool verify(string email);

#endif // __USER_H__