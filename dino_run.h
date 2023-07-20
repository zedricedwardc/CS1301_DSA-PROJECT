#ifndef DINO_RUN_H
#define DINO_RUN_H

#include <windows.h>

void gotoxy(int x, int y);
void setcursor(bool visible, DWORD size);
void init();
void moveDino(int jump = 0);
void drawHurdle();
void play();
void instructions();

#endif