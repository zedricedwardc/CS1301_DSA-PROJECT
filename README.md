# PROJECT GAMEBOY


## Introduction

**This repository contains a console-based game menu program that allows users to select and play various text-based games.** The program presents a main menu with options to access the list of available games, favorite games, and an option to exit the program. Users can play different games, add games to their favorites, and remove games from their favorites.

## Dependencies

**The program relies on the following standard C++ libraries:**

- `iostream`: Provides basic input/output functionality.
- `string`: For working with strings.
- `list`: For managing lists of games and favorite games.
- `conio.h`: For console input/output functions (`getch()` used here).
- `cstdlib`: For standard C library functions like `system()`.
- `algorithm`: For various algorithms like `find()`.

## Code Structure

**The program is structured around the `Menu` struct, which represents the main menu and contains methods to handle different menu options.** The `Menu` struct has the following key components:

1. `list<string> games`: A list of available games stored as strings.
2. `static list<string> favoriteGames`: A static list of favorite games, shared across all instances of the `Menu` struct.

## Usage

Upon running the program, users are presented with a main menu containing the following options:

1. **[Games Available](#games-available):** View and play available games.
2. **[Favorite Games](#favorite-games):** View, add, or remove favorite games.
3. **[Exiting the Program](#exiting-the-program):** Exit the program.

**The user can navigate through these options by entering the corresponding number and pressing Enter.**

## Games Available

The "Games Available" menu option displays a list of available games to the user. The user can choose a game from the list to play. The following games are available:

1. **WordGame:** A word guessing game.
2. **Flappy Bird:** A simple text-based version of the Flappy Bird game.
3. **Dino Game:** A basic text-based Dino Run game.
4. **Maths Game:** A math-based game.
5. **Guess Number:** A number guessing game.

## Favorite Games

The "Favorite Games" menu option allows the user to manage their favorite games. The user can:

1. **[Choose game to play](#games-available):** Play a game from their favorite games list.
2. **[Add a game to favorites](#games-available):** Add a game from the available games to their favorite games list.
3. **[Remove a game from favorites](#games-available):** Remove a game from their favorite games list.

**The user can navigate through these options by entering the corresponding number and pressing Enter.**

## Exiting the Program

The "Exiting the Program" menu option allows the user to exit the program. When chosen, the program displays a farewell message and terminates gracefully.
