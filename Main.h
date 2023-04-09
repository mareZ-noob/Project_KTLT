#ifndef __MAIN_H__
#define __MAIN_H__

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include <time.h>
#include <mmsystem.h>
#include <fstream>
#include <string>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::sort;
using std::swap;
using std::max;
using std::min;

// COLORS
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define OCEAN 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define CYAN 11
#define LIGHT_RED 12
#define MAGENTA 13
#define LIGHT_YELLOW 14
#define LIGHT_WHITE 15

// KEY CHARS
#define KEY_W 'W'
#define KEY_S 'S'
#define KEY_A 'A'
#define KEY_D 'D'
#define KEY_H 'H'
#define KEY_R 'R'
#define KEY_M 'M'

#define KEY_w 'w'
#define KEY_s 's'
#define KEY_a 'a'
#define KEY_d 'd'
#define KEY_h 'h'
#define KEY_r 'r'
#define KEY_m 'm'

#define TAB_KEY 9
#define ENTER_KEY 13
#define ESC_KEY 27

// SOUNDS
#define SIU_SOUND "sounds\\siu.wav"
#define POKEMON_SOUND "sounds\\pokemon.wav"
#define GLORY_SOUND "sounds\\glory_mu.wav"

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
	*/
	void drawBox(Board **&board);
};

struct Settings {
	int gameMode;
	/*
	gameMode = 1 -> random board
	gameMode = 2 -> retreat board
	*/
	int music;
};

struct Players
{
    char name[20];
    int point;
    int time;
};

#endif // __MAIN_H__