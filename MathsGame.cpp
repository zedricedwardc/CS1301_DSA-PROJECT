#include "MathsGame.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

MathsGame::MathsGame() {
    srand(static_cast<unsigned>(time(nullptr)));
    level = 0;
    limit = 0;
    totalNo = 5;
    operation = '+';
}

void MathsGame::generateRandomQuestion(float& q1, float& q2, char& operation) {
    q1 = rand() % limit;
    q2 = rand() % limit;
    int tmpOp = rand() % 3;
    switch (tmpOp) {
    case 0:
        operation = '+';
        break;
    case 1:
        operation = '-';
        break;
    case 2:
        operation = '*';
        break;
    }
}

float MathsGame::calculateCorrectAnswer(float q1, float q2, char operation) {
    switch (operation) {
    case '+':
        return q1 + q2;
    case '-':
        return q1 - q2;
    case '*':
        return q1 * q2;
    default:
        return 0;
    }
}

void MathsGame::displayMainMenu() {
    char option;
    do {
        system("cls");
        cout << "-----------------------------------" << endl;
        cout << "           MATHS GAME              " << endl;
        cout << "-----------------------------------" << endl << endl;
        cout << "1. Play" << endl;
        cout << "2. Instructions" << endl;
        cout << "3. Exit" << endl << endl;
        cout << "Choose Option (1-3):";
        cin >> option;

        switch (option) {
        case '1':
            play();
            break;
        case '2':
            instructions();
            break;
        }
    } while (option != '3');
}

void MathsGame::play() {
    char option;
    system("cls");
    cout << "-----------------------------------" << endl;
    cout << "           MATHS GAME              " << endl;
    cout << "-----------------------------------" << endl << endl;
    cout << "1. Level 1" << endl;
    cout << "2. Level 2" << endl;
    cout << "3. Level 3" << endl;
    cout << "4. Back to Menu" << endl << endl;
    cout << "Choose Option (1-4):";
    cin >> option;

    switch (option) {
    case '1':
        level = 1;
        limit = 10;
        break;
    case '2':
        level = 2;
        limit = 20;
        break;
    case '3':
        level = 3;
        limit = 100;
        break;
    case '4':
        return;
    }

    float q1, q2, ans, correctAns;
    int correctNo = 0;

    for (int i = 0; i < totalNo; i++) {
        generateRandomQuestion(q1, q2, operation);

        cout << "(" << (i + 1) << "). ";
        cout << q1 << " " << operation << " " << q2 << " = ";
        cin >> ans;

        correctAns = calculateCorrectAnswer(q1, q2, operation);

        if (correctAns == ans) {
            correctNo++;
            cout << "Correct." << endl << endl;
        }
        else {
            cout << "Wrong" << endl;
            cout << q1 << " " << operation << " " << q2 << " = " << correctAns << endl << endl;
        }
    }

    cout << "Total: " << totalNo << endl;
    cout << "Correct: " << correctNo << endl << endl;

    cout << "Press any key to continue..." << endl;
    cin.ignore();
    cin.get();
}

void MathsGame::instructions() {
    system("cls");
    cout << "-----------------------------------" << endl;
    cout << "          Instructions             " << endl;
    cout << "-----------------------------------" << endl << endl;
    cout << "1. This game contains basic arithmetic problems" << endl;
    cout << "2. Each correct answer will yield 1 Point" << endl;
    cout << "3. Total questions will be 5 " << endl;
    cout << "4. To win, you need 3 or more correct answers" << endl;
    cout << endl;

    cout << "Press any key to continue..." << endl;
    cin.ignore();
    cin.get();
}