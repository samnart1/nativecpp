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
        cout << "Enter your guess ( " << minRange << " - " << maxRange << " ): \n"; 

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

void Guess_Game::giveFeedback(int guess) {
    int difference = abs(guess - secretNumber);

    if (guess == secretNumber) {
        return;
    } else if (guess < secretNumber) {
        cout << "Too low\n";
    } else {
        cout << "Too high\n";
    }

    if (difference <= 5) {
        cout << "You're very close! \n";
    } else if (difference <= 17) {
        cout << "Getting warmer! \n";
    } else {
        cout << "Still far away ...\n";
    }
}

bool Guess_Game::playGame() {
    displayWelcome();

    while (attempts < maxAttempts) {
        cout << "\nAttemps: " << attempts << "/" << maxAttempts << '\n' << endl;
        attempts++;
        
        int guess = getValidGuess();
        
        if (guess == secretNumber) {
            cout << "\nCongratulations! You guessed it!\n";
            cout << "The number was " << secretNumber << '\n';
            cout << "You solved it in " << attempts << " attemp(s)!" << '\n';
            
            if (attempts <= 3) {
                cout << "Excellent! You're a guessing master!\n";
            } else if (attempts <= 5) {
                cout << "Good work! Well done!\n";
            } else {
                cout << "Good work! You made it!\n";
            }
            return true;
        } else {
            giveFeedback(guess);

            int remaining = maxAttempts - attempts;
            if (remaining > 0) {
                cout << "Attempts remaining: " << remaining << '\n';
            }
        }
    }

    cout << "\nGame Over! You've used all " << maxAttempts << " attempts\n";
    cout << "The secret number was: " << secretNumber << '\n';
    cout << "Better luck next time!\n";
    return false;
}

bool Guess_Game::playAgain() {
    char choice;
    while (true) {
        cout << "\nWould you like to play again? (y/n): \n";
        cin >> choice;
        choice = tolower(choice);

        if (choice == 'y') {
            attempts = 0;
            generateSecretNumber();
            return true;
        } else if (choice == 'n') {
            return false;
        } else {
            cout << "Please enter 'y' for yes or 'n' for no.\n";
        }
    }
}