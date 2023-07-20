#include "dino_run.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define dinoPos 2
#define hurdlePos 74

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int dinoY;
int speed = 40;
int gameover = 0;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcursor(bool visible, DWORD size) {
    if (size == 0) {
        size = 20;
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void init() {
    system("cls");
    gameover = 0;
    gotoxy(3, 2); std::cout << "SCORE : ";
    for (int i = 0; i < 79; i++) {
        gotoxy(1 + i, 1); std::cout << "ß";
        gotoxy(1 + i, 25); std::cout << "ß";
    }
}

void moveDino(int jump) {
    static int foot = 0;

    if (jump == 0)
        dinoY = 0;
    else if (jump == 2)
        dinoY--;
    else
        dinoY++;

    gotoxy(dinoPos, 15 - dinoY); std::cout << "                 ";
    gotoxy(dinoPos, 16 - dinoY); std::cout << "         ÜÛßÛÛÛÛÜ";
    gotoxy(dinoPos, 17 - dinoY); std::cout << "         ÛÛÛÛÛÛÛÛ";
    gotoxy(dinoPos, 18 - dinoY); std::cout << "         ÛÛÛÛÛßßß";
    gotoxy(dinoPos, 19 - dinoY); std::cout << " Û      ÜÛÛÛÛßßß ";
    gotoxy(dinoPos, 20 - dinoY); std::cout << " ÛÛÜ  ÜÛÛÛÛÛÛÜÜÜ ";
    gotoxy(dinoPos, 21 - dinoY); std::cout << " ßÛÛÛÛÛÛÛÛÛÛÛ  ß ";
    gotoxy(dinoPos, 22 - dinoY); std::cout << "   ßÛÛÛÛÛÛÛß     ";
    gotoxy(dinoPos, 23 - dinoY);

    if (jump == 1 || jump == 2) {
        std::cout << "    ÛÛß ßÛ       ";
        gotoxy(2, 24 - dinoY);
        std::cout << "    ÛÜ   ÛÜ      ";
    }
    else if (foot == 0) {
        std::cout << "    ßÛÛß  ßßß    ";
        gotoxy(2, 24 - dinoY);
        std::cout << "      ÛÜ         ";
        foot = !foot;
    }
    else if (foot == 1) {
        std::cout << "     ßÛÜ ßÛ      ";
        gotoxy(2, 24 - dinoY);
        std::cout << "          ÛÜ     ";
        foot = !foot;
    }

    gotoxy(2, 25 - dinoY);
    if (jump == 0) {
        std::cout << "ßßßßßßßßßßßßßßßßß";
    }
    else {
        std::cout << "                ";
    }
    Sleep(speed);
}

void drawHurdle() {
    static int plantX = 0;
    static int score = 0;
    if (plantX == 56 && dinoY < 4) {
        score = 0;
        speed = 40;
        gotoxy(36, 8); std::cout << "Game Over";
        _getch();
        gameover = 1;
    }

    gotoxy(hurdlePos - plantX, 20); std::cout << "| | ";
    gotoxy(hurdlePos - plantX, 21); std::cout << "| | ";
    gotoxy(hurdlePos - plantX, 22); std::cout << "|_| ";
    gotoxy(hurdlePos - plantX, 23); std::cout << " |  ";
    gotoxy(hurdlePos - plantX, 24); std::cout << " |  ";

    plantX++;

    if (plantX == 73) {
        plantX = 0;
        score++;
        gotoxy(11, 2); std::cout << "     ";
        gotoxy(11, 2); std::cout << score;
        if (speed > 20)
            speed--;
    }
}

void play() {
    system("cls");
    char ch;
    int i;
    init();
    while (true) {
        while (!_kbhit()) {
            if (gameover == 1) {
                return;
            }
            moveDino();
            drawHurdle();
        }
        ch = _getch();
        if (ch == 32) {
            i = 0;
            while (i < 12) {
                moveDino(1);
                drawHurdle();
                i++;
            }
            while (i > 0) {
                moveDino(2);
                drawHurdle();
                i--;
            }
        }
        else if (ch == 'p' || ch == 'P')
            _getch();
        else if (ch == 27)
            break;
    }
}

void instructions() {
    system("cls");
    std::cout << "Instructions";
    std::cout << "\n----------------";
    std::cout << "\n1. Avoid hurdles by jumping";
    std::cout << "\n2. Press 'Spacebar' to jump ";
    std::cout << "\n3. Press 'p' to pause game ";
    std::cout << "\n4. Press 'Escape' to exit from game";
    std::cout << "\n\nPress any key to go back to menu";
    _getch();
}