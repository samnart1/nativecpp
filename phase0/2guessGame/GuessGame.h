#ifndef GUESS_GAME_H
#define GUESS_GAME_H

class Guess_Game {
private:
    int secretNumber;
    int attempts;
    int maxAttempts;
    int minRange;
    int maxRange;

    void generateSecretNumber();
    void giveFeedback(int guess);
    int getValidGuess();
    void displayWelcome();

public:
    Guess_Game(int min = 1, int max = 100, int maxTries = 7);
    bool playGame();
    bool playAgain();
};

#endif