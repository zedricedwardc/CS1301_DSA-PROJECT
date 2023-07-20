#include <iostream>
#include <string>
#include <list>
#include <conio.h>
#include <cstdlib>
#include <algorithm> 

#include "word_game.h"
#include "FlappyBird.h"
#include "dino_run.h"
#include "MathsGame.h"
#include "GuessNumberGame.h"

using namespace std;

struct Menu {
    list<string> games;
    static list<string> favoriteGames;

    void DinoGame()
    {
        setcursor(0, 0);

        do {
            system("cls");
            gotoxy(10, 5); cout << " -------------------------- ";
            gotoxy(10, 6); cout << " |        DINO RUN        | ";
            gotoxy(10, 7); cout << " -------------------------- ";
            gotoxy(10, 9); cout << "1. Start Game";
            gotoxy(10, 10); cout << "2. Instructions";
            gotoxy(10, 11); cout << "3. Quit";
            gotoxy(10, 13); cout << "Select option: ";
            char op;
            cin >> op;

            if (op == '1') play();
            else if (op == '2') instructions();
            else if (op == '3') break;

        } while (1);
    }

    void printGames() const {
        cout << "Available games:" << endl;
        int i = 1;
        for (const auto& game : games) {
            cout << "\t" << i << ". " << game << endl;
            i++;
        }
        cout << endl;
    }

    void printFavoriteGames() const {
        if (favoriteGames.empty()) {
            cout << "No favorite games added." << endl;
        }
        else {
            cout << "Favorite games:" << endl;
            int i = 1;
            for (const auto& game : favoriteGames) {
                cout << "\t"<<i << ". " << game << endl;
                i++;
            }
        }
        cout << endl;
    }

    void addFavoriteGame(int gameChoice)
    {
        auto it = games.begin();
        advance(it, gameChoice - 1);
        const string& gameToAdd = *it;

        // Check if the game is already in the favorite list
        if (find(favoriteGames.begin(), favoriteGames.end(), gameToAdd) != favoriteGames.end()) {
            cout << "Game is already in favorites." << endl;
        }
        else {
            favoriteGames.push_back(gameToAdd);
            cout << "Game added to favorites.\nAdd another Game?\n" << endl;
        }
    }

    void removeFavoriteGame(int removeChoice) {
        auto it = favoriteGames.begin();
        advance(it, removeChoice - 1);
        favoriteGames.erase(it);
        cout << "Favorite game removed." << endl << "Delete more game to favorites?\n";
    }

    void playSelectedGame(const string& gameName) {
        if (gameName == "WordGame") {
            WordGame::playGame();
        }
        else if (gameName == "Flappy Bird") {
            FlappyBird flappyBird;
            flappyBird.Menu();
        }
        else if (gameName == "Dino Game") {
            DinoGame();
        }
        else if (gameName == "Maths Game")
        {
            MathsGame MathsGame;
            MathsGame.displayMainMenu();
        }
        else if (true)
        {
            GuessNumberGame GuessNumber;
            GuessNumber.play();
        }
    }
};

list<string> Menu::favoriteGames;

int main() 
{
    int gameNumber;
    Menu menu;
    menu.games = {
        "WordGame",
        "Flappy Bird",
        "Dino Game",
        "Maths Game",
        "Guess Number"
        };

    while (true) {
        system("cls");
        cout << "Main menu:" << endl;
        cout << "\t[1] Games" << endl;
        cout << "\t[2] Favorite Games" << endl;
        cout << "\t[3] Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            do {
                system("cls");
                menu.printGames();
                cout << "What game do you want to play?(0 to cancel): ";
                cin >> gameNumber;
                if (gameNumber > 0 && gameNumber <= menu.games.size() && gameNumber < 6) {
                    system("cls");
                    auto it = menu.games.begin();
                    advance(it, gameNumber - 1);
                    menu.playSelectedGame(*it); // Play the selected game
                }
                else if (gameNumber == 0)
                {
                    return main();
                }
                else {
                    cout << "Invalid game number." << endl;
                }
                
            } while (gameNumber > 5);
            break;

        case 2:
            int tempChoice;
            do{
                system("cls");
            menu.printFavoriteGames();
            cout << "\n\t[1]Choose game to play.\n\t[2]Add a game to favorites\n\t[3]Remove a game to favorites\n\t[4]Exit\n\tChoose: ";
            cin >> tempChoice;
            system("cls");
            switch (tempChoice)
            {
                case 1: 
                    do
                    {
                        menu.printFavoriteGames();
                        cout << "What game do you want to play?(0 to cancel): ";
                        cin >> gameNumber;
                        if (gameNumber > 0 && gameNumber <= menu.games.size()) {
                            system("cls");
                            auto it = menu.favoriteGames.begin();
                            advance(it, gameNumber - 1);
                            menu.playSelectedGame(*it); // Play the selected game
                            system("cls");
                        }
                        else {
                            system("cls");
                            cout << "Invalid game number." << endl;
                            system("pause");
                        }
                       
                    } while (gameNumber <0);
                   

                    break;
                case 2: 
                    int gameChoice;
                    do
                    {   
                        menu.printGames();
                        cout << "Enter the game number to add to favorites (0 to cancel): ";
                        cin >> gameChoice;

                        if (gameChoice > 0 && gameChoice <= menu.games.size()) {
                            system("cls");
                            menu.addFavoriteGame(gameChoice);

                        }
                        else if (gameChoice != 0) {
                            system("cls");
                            cout << "Invalid game number." << endl;
                        }
                    } while (gameChoice != 0);
                    break;
                case 3:
                {   
                    int removeChoice;
                    do
                    {
                        menu.printFavoriteGames();
                        
                        cout << "Enter the favorite game number to remove (0 to cancel): ";
                        cin >> removeChoice;

                        if (removeChoice > 0 && removeChoice <= menu.favoriteGames.size()) {
                            system("cls");
                            menu.removeFavoriteGame(removeChoice);
                        }
                        else if (removeChoice != 0) {
                            system("cls");
                            cout << "Invalid favorite game number." << endl;
                        }
                    } while (removeChoice != 0);
                    break;
                }
                case 4:
                    system("cls");
                    return main();
                    break;
                default:
                    system("cls");
                    cout << "Invalid choice returning to main menu";
                    system("pause");
                    break;
            }
            } while (tempChoice != 0);
            break;
        case 3:system("cls");
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:system("cls");
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}