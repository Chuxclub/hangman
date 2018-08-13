#include <iostream>
#include "std_lib_facilities.h"
#include "hangman_func.h"
#include "hangman_word.h"

/* ---------------------------------------------- HANGMAN GAME SOLO ---------------------------------------------- */

int main()
{
    bool won = false, lost = false;
    int tries = 0;
    const int MAX_TRIES = 5;
    std::string user_guess;
    vector <string> wrong_guesses;
    hangman_word word;

    word.pick();
    word.conceal(); //Returns a string of * which equals length of picked_word

    std::cout << word.get_picked() << "\n\n";

// ~~~~~~~~~~~~~~~~~~~~~~~~~ If user has neither won nor lost, then loops ~~~~~~~~~~~~~~~~~~~~~~~~~ //

    while(!won && !lost) //If player has won, condition is false, same goes if he has lost
    {
        std::cout << word.get_concealed() << "\n\n";

        std::cout << "Pick a letter: ";
        std::cin >> user_guess;
        std::cout << "\n";

        word.find_occurrences(user_guess);

        if (word.occurrences().empty()) //Tests if occurrences of user's guessed letter have been found
        {
            wrong_guesses.push_back(user_guess);
            print_wrong_guesses(wrong_guesses);
            tries++;
        }

        else
        {
            word.reveal(user_guess);
            word.clear_occurrences();
        }


// ~~~~~~~~~~~~~~~~~~~~~~~~~ Tests whether the user has won or lost ~~~~~~~~~~~~~~~~~~~~~~~~~ //

        switch(tries)
        {
            case MAX_TRIES:
                lost = true;
                break;

            default:
                won = word.check();
                break;
        }
    }


// ~~~~~~~~~~~~~~~~~~~~~~~~~ If player has either won or lost, loop ends ~~~~~~~~~~~~~~~~~~~~~~~~~ //

    if(won)
        std::cout << "YOU WON!" << "\n\n" << "The hidden word is indeed: " << word.get_picked() << " !" << "\n";

    else
        std::cout << "YOU LOST!" << "\n\n" << "The hidden word was: " << word.get_picked() << " !" << "\n";

    return 0;
}

/* ---------------------------------------------------------------------------------------------------------------- */


//std::cout << picked_word << "\n\n";

/* if (user_letter_guess.length() > 1)
        {
            while (user_letter_guess.length() > 1)
            {
                std::cerr << "Input just one letter!";
                std::cout << "Pick a letter: ";
                std::cin >> user_letter_guess;
            }

        } */