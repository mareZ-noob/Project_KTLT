#ifndef __GRAPHIC_H__
#define _GRAPHIC_H__

#include "Main.h"
#include "Setup.h"

void art(string fileName, int pX, int pY);
void art_at_pos(string fileName, int textColor, int backgroundColor, int x, int y);//Draw art at position (x, y);
void read_file_at_pos(string fileName, int textColor, int backgroundColor, int x, int y);

#endif // __GRAPHIC_H__
