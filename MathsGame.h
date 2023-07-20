#ifndef MATHSGAME_H
#define MATHSGAME_H

class MathsGame {
private:
    int level;
    int limit;
    int totalNo;
    char operation;

    void generateRandomQuestion(float& q1, float& q2, char& operation);
    float calculateCorrectAnswer(float q1, float q2, char operation);

public:
    MathsGame();

    void displayMainMenu();
    void play();
    void instructions();
};

#endif