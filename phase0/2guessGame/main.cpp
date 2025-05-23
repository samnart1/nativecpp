#include <iostream>
#include "GuessGame.h"

using namespace std;

int main() {

    cout << "C++ Number Guessing Game!" << endl;

    Guess_Game game;

    do {
        game.playGame();
    } while (game.playAgain());

    return 0;
}