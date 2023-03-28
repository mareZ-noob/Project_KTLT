#ifndef __MENU_H__
#define __MENU_H__

#include "Main.h"
#include "Setup.h"
#include "User.h"
#include "Graphic.h"

void menuSelection();
void menu(int choice);
void quit();
void login(string &email);

//DINH DUY TRIET
void selectionMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text);
void selectionMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text);
void printMenu(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text);
void printMenuLogin(int selection, int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text);
int MainMenuBack();
void MenuLogin();
void MainMenu();
void login1(string& email);

#endif // __MENU_H__
