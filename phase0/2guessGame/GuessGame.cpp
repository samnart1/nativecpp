#include "GuessGame.h"

#include <iostream>
#include <random>
#include <limits>

using namespace std;

Guess_Game::Guess_Game(int min, int max, int maxTries) 
    : minRange(min), maxRange(max), maxAttempts(maxTries), attempts(0) {
    generateSecretNumber();
}

void Guess_Game::generateSecretNumber() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(minRange, maxRange);
    secretNumber = dis(gen);
}

void Guess_Game::displayWelcome() {
    cout << "\n=== Welcome to the Number Guessing Game! ===\n";
    cout << "I'm thinking of a number between " << minRange << " and " << maxRange << "\n";
    cout << "You have " << maxAttempts << " attemps to guess it!\n";
    cout << "Let's see if you can find it!\n\n";
}

int Guess_Game::getValidGuess() {
    int guess;
    while (true) {
        cout << "Enter your guess ( " << minRange << " - " << maxRange << " ): "; 

        if (cin >> guess) {
            if (guess >= minRange && guess <= maxRange) {
                return guess;
            } else {
                cout << "Please enter a number between " << minRange << " and " << maxRange << "\n";
            }
        } else {
            cout << "Invalid input! Please enter a valid number between " << minRange << " and " << maxRange << '\n'; 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void Guess_Game::giveFeedback(int guess) {}