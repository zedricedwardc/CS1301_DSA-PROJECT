#include <iostream>
#include <string>
#include <list>


using namespace std;

struct Menu {
    list<string> games;
    list<string> favoriteGames;

    void printGames() const {
        cout << "Available games:" << endl;
        int i = 1;
        for (const auto& game : games) {
            cout << i << ". " << game << endl;
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
                cout << i << ". " << game << endl;
                i++;
            }
        }
        cout << endl;
    }

    void addFavoriteGame(int gameChoice) {
        auto it = games.begin();
        advance(it, gameChoice - 1);
        favoriteGames.push_back(*it);
        cout << "Game added to favorites." << endl;
    }

    void removeFavoriteGame(int removeChoice) {
        auto it = favoriteGames.begin();
        advance(it, removeChoice - 1);
        favoriteGames.erase(it);
        cout << "Favorite game removed." << endl;
    }
};

int main() 
{
    int gameNumber;
    Menu menu;
    menu.games = {
        "WordGame",
        "Game 2",
        "Game 3",
        "Game 4",
        "Game 5",
        "Game 6",
        "Game 7",
        "Game 8",
        "Game 9",
        "Game 10"
    };

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Games" << endl;
        cout << "2. Favorite Games" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            menu.printGames();
            cout << "Whatgame do you want to play?:";
            cin >> gameNumber;
            switch (gameNumber)
            {
            case 1:  
                break;
            }

            break;
        case 2:
            int tempChoice;
            do{
            menu.printFavoriteGames();
            cout << "\n\t[1]Choose game to play.\n\t[2]add a game to favorites\n\t[3]remove a game to favorites\n\t[4]Exit\n\tChoose:";
            cin >> tempChoice;
            switch (tempChoice)
            {
                case 1: 
                    int tempfavchoice;
                    do 
                    {
                        menu.printFavoriteGames();
                        cout << "\n\t[1]Choose game to play.[2]Exit\n\tChoose:";
                        cin >> tempfavchoice;
                        switch (tempfavchoice)
                        {
                            case 1:
                                break;

                            case 2:
                                cout << "Exiting back to Main Menu....";
                                system("pause");
                                system("cls");
                                break;
                            default:
                                cout << "Invalid input try again!!\n";
                                break;
                        }
                    } while (tempfavchoice != 1 || tempfavchoice != 2);
                   

                    break;
                case 2: 
                    int gameChoice;
                    do
                    {
                        menu.printGames();
                        cout << "Enter the game number to add to favorites (0 to cancel): ";
                        cin >> gameChoice;

                        if (gameChoice > 0 && gameChoice <= menu.games.size()) {
                            menu.addFavoriteGame(gameChoice);
                        }
                        else if (gameChoice != 0) {
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
                            menu.removeFavoriteGame(removeChoice);
                        }
                        else if (removeChoice != 0) {
                            cout << "Invalid favorite game number." << endl;
                        }
                    } while (removeChoice != 0);
                    break;
                }
                case 4:
                    return main();
                    break;
                default:
                    cout << "invalid choice returning to main menu";
                    system("pause");
                    break;
            }
            } while (tempChoice != 0);
            break;
        case 3:
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    }
}