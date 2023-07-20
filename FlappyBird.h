#ifndef FLAPPYBIRD_H
#define FLAPPYBIRD_H

#include<iostream>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
#include <time.h>

#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70
#define MENU_WIDTH 20
#define GAP_SIZE 7
#define PIPE_DIF 45

class FlappyBird {
private:
    HANDLE console;
    COORD CursorPosition;
    int pipePos[3];
    int gapPos[3];
    int pipeFlag[3];
    char bird[2][6] = { { '/','-','-','o','\\',' ' },
                        { '|','_','_','_',' ','>' } };
    int birdPos;
    int score;

    void gotoxy(int x, int y);
    void setcursor(bool visible, DWORD size);
    void drawBorder();
    void genPipe(int ind);
    void drawPipe(int ind);
    void erasePipe(int ind);
    void drawBird();
    void eraseBird();
    int collision();
    void debug();
    void gameover();
    void updateScore();
    void instructions();
   

public:
    FlappyBird();
    void play();
    void Menu();
};

#endif
