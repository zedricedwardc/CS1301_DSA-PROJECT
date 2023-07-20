#include "GuessNumberGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

GuessNumberGame::GuessNumberGame() {
    srand(static_cast<unsigned int>(time(0)));
    secretNumber = rand() % 100 + 1;
    tries = 0;
}

void GuessNumberGame::play() {
    int guess;
    cout << "\tWelcome to Guess My Number\n\n";

    do {
        cout << "Enter a guess: ";
        cin >> guess;
        ++tries;
        if (guess > secretNumber) {
            cout << "Too high!\n\n";
        }
        else if (guess < secretNumber) {
            cout << "Too low!\n\n";
        }
        else {
            cout << "\nThat's it! You got it in " << tries << " guesses!\n\n";
            system("pause");

        }
    } while (guess != secretNumber);
}