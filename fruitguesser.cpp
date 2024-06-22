#include <iostream>     // Includes the standard input-output stream library
#include <vector>       // Includes the vector library for using the vector container
#include <ctime>        // Includes the ctime library for using time-related functions
#include <cstdlib>      // Includes the cstdlib library for using random number generation
#include <string>       // Includes the string library for using the string class

// Function to select a random word from a list of words
std::string selectRandomWord(const std::vector<std::string>& words) {
    // Returns a random word from the vector of words
    return words[std::rand() % words.size()];
}

// Function to display the current state of the guessed word
void displayWord(const std::string& word, const std::vector<bool>& guessed) {
    // Loop through each character in the word
    for (size_t i = 0; i < word.size(); ++i) {
        // If the character has been guessed, display the character
        if (guessed[i]) {
            std::cout << word[i] << ' ';
        } else {
            // If the character has not been guessed, display an underscore
            std::cout << "_ ";
        }
    }
    // Print a new line after displaying the word
    std::cout << std::endl;
}

// Function to check if the entire word has been guessed
bool isWordGuessed(const std::vector<bool>& guessed) {
    // Loop through each boolean value in the guessed vector
    for (bool letterGuessed : guessed) {
        // If any character has not been guessed, return false
        if (!letterGuessed) {
            return false;
        }
    }
    // If all characters have been guessed, return true
    return true;
}

int main() {
    // Seed the random number generator with the current time
    std::srand(std::time(nullptr));

    // List of legitimate words
    std::vector<std::string> words = {
        "apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew",
        "kiwi", "lemon", "mango", "nectarine", "orange", "papaya", "quince", "raspberry",
        "strawberry", "tangerine", "ugli", "vanilla", "watermelon", "xigua", "yam",
        "zucchini", "apricot", "blueberry", "cantaloupe", "dragonfruit", "elderberry",
        "feijoa", "gooseberry", "huckleberry", "jackfruit", "kumquat", "lime", "mulberry",
        "olive", "peach", "pineapple", "plum", "pomegranate", "rhubarb", "starfruit",
        "tomato", "ugni", "voavanga", "walnut", "yangmei", "zinfandel", "blackberry",
        "cranberry", "durian", "grapefruit", "lychee", "mandarin", "passionfruit", "persimmon"
    };

    // Select a random word from the list
    std::string selectedWord = selectRandomWord(words);
    // Vector to keep track of which letters have been guessed
    std::vector<bool> guessed(selectedWord.size(), false);
    // Variable to keep track of the number of wrong guesses
    int wrongGuesses = 0;
    // Constant for the maximum number of wrong guesses allowed
    const int maxWrongGuesses = 6;
    // Vector to store the letters that have been guessed incorrectly
    std::vector<char> wrongLetters;

    // Welcome message
    std::cout << "Welcome to Fruit Guesser!\n";

    // Main game loop, continues until the word is guessed or the max wrong guesses is reached
    while (wrongGuesses < maxWrongGuesses && !isWordGuessed(guessed)) {
        // Display the current state of the guessed word
        displayWord(selectedWord, guessed);
        // Display the number of wrong guesses and the wrong letters guessed so far
        std::cout << "Wrong guesses (" << wrongGuesses << "/" << maxWrongGuesses << "): ";
        for (char letter : wrongLetters) {
            std::cout << letter << ' ';
        }
        std::cout << std::endl;

        // Prompt the user to enter a letter
        std::cout << "Enter a letter: ";
        char guess;
        std::cin >> guess;

        // Variable to check if the guessed letter is in the word
        bool found = false;
        // Loop through each character in the selected word
        for (size_t i = 0; i < selectedWord.size(); ++i) {
            // If the guessed letter is found in the word, update the guessed vector
            if (selectedWord[i] == guess) {
                guessed[i] = true;
                found = true;
            }
        }

        // If the guessed letter was not found, increment the wrong guess counter and add to wrongLetters
        if (!found) {
            wrongGuesses++;
            wrongLetters.push_back(guess);
        }
    }

    // Check if the word was guessed successfully
    if (isWordGuessed(guessed)) {
        std::cout << "Congratulations! You guessed the word: " << selectedWord << std::endl;
    } else {
        // If not, display the game over message and the correct word
        std::cout << "Game Over! The word was: " << selectedWord << std::endl;
    }

    return 0;
}