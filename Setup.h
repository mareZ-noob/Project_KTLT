#ifndef __SETUP_H__
#define __SETUP_H__

#include "Main.h"

void SetWindowSize(int width, int height);
void SetScreenBufferSize(SHORT width, SHORT height);
void DisableResizeWindow();
void DisableCtrButton(bool Close, bool Min, bool Max);
void ShowScrollbar(BOOL Show);

void DisableSelection();
void showCursor(bool visible);
void moveCursor(int posX, int posY);
void disableMouseInput();

void consoleTitle();
void consoleColor(int background, int text);
void clearScreen();
void drawRectangle(int left, int top, int width, int height);
void initConsole();

//DINH DUY TRIET
void TextColor(WORD color);
void BackgroundColor(int background, int text);//Bỏ đi
void ShowCur(bool CursorVisibility);//Bỏ đi
void button(int x, int y, int w, int h, int textColor, int buttonColor, int backgroundColor, string text);

#endif // __SETUP_H__

