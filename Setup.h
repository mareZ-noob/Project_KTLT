#ifndef __SETUP_H__
#define __SETUP_H__

#include "Main.h"

void SetWindowSize(int width, int height);
void SetScreenBufferSize(SHORT width, SHORT height);
void DisableResizeWindow();
void DisableCtrButton(bool Close, bool Min, bool Max);
void ShowScrollbar(BOOL Show);

void showCursor(bool visible);
void moveCursor(int posX, int posY);
void disableMouseInput();

void consoleTitle();
void consoleColor(int background, int text);
void clearScreen();
void drawRectangle(int left, int top, int width, int height);
void initConsole();

void TextColor(WORD color);
void button(int x, int y, int w, int h, int color, int buttonColor, int backgroundColor, string text);
void art_at_pos(string fileName, int textColor, int backgroundColor, int x, int y); // draw art at position (x, y);
void drawBorder();
void drawBackButton();
void createScreen();
void box(double x, double y, double w, double h, int textColor, int buttonColor, int color, char chr);

#endif // __SETUP_H__