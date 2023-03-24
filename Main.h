#ifndef __MAIN_H__
#define __MAIN_H__

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <algorithm>
#include <random>
#include <chrono>
#include <ctime>
#include <mmsystem.h>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <string.h>
#pragma comment(lib, "Winmm.lib")

using std::cin;
using std::flush;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

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
#define KEY_W 'w'
#define KEY_S 's'
#define KEY_A 'a'
#define KEY_D 'd'
#define KEY_H 'h'

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER_KEY 13
#define ESC_KEY 27

// SOUNDS
#define SIU_SOUND "sounds\\siu.wav"
#define POKEMON_SOUND "sounds\\pokemon.wav"

#endif // __MAIN_H__