#ifndef GUESSNUMBERGAME_H
#define GUESSNUMBERGAME_H

class GuessNumberGame {
private:
    int secretNumber;
    int tries;

public:
    GuessNumberGame();
    void play();
};

#endif