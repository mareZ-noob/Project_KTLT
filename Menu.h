#ifndef __MENU_H__
#define __MENU_H__

#include "Graphic.h"
#include "Game.h"

void quit();
void login(string &email);
void HowToPlay();

// start menu
void selectionMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
void printMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
void MainMenu();

// menu when login successful
void selectionMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
void printMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
void LoginMenu();

// menu when play
void selectionPlayGame(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
void printPlayGame(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor);
void GamePlayMenu();

#endif // __MENU_H__