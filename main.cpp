#include <iostream>
#include "std_lib_facilities.h"
#include "hangman_func.h"

/* ---------------------------------------------- HANGMAN GAME SOLO ---------------------------------------------- */

int main()
{
    bool won = false, lost = false;
    int tries = 0;
    const int MAX_TRIES = 5;
    constexpr char HIDING_CHAR = '*';
    std::string user_letter_guess;
    vector <size_t> occurrence_pos;
    vector <string> wrong_guesses;


    std::string picked_word = word_picker(); //Randomly picks a word and assigns it to variable picked_word
    std::string concealed_word = word_concealer(picked_word, HIDING_CHAR); //Returns a string of * which equals length of picked_word

    std::cout << picked_word << "\n\n";

// ~~~~~~~~~~~~~~~~~~~~~~~~~ If user has neither won nor lost, then loops ~~~~~~~~~~~~~~~~~~~~~~~~~ //

    while(!won && !lost) //If player has won, condition is false, same goes if he has lost
    {
        std::cout << concealed_word << "\n\n";

        std::cout << "Pick a letter: ";
        std::cin >> user_letter_guess;
        std::cout << "\n";

        occurrence_pos = occurrence_finder(picked_word, user_letter_guess);

        if (occurrence_pos.empty()) //Tests if occurrences of user's guessed letter have been found
        {
            wrong_guesses.push_back(user_letter_guess);
            print_wrong_guesses(wrong_guesses);
            tries++;
        }

        else
            letter_revealer(occurrence_pos, concealed_word, user_letter_guess);

// ~~~~~~~~~~~~~~~~~~~~~~~~~ Tests whether the user has won or lost ~~~~~~~~~~~~~~~~~~~~~~~~~ //

        switch(tries)
        {
            case MAX_TRIES:
                lost = true;
                break;

            default:
                won = win_checker(concealed_word, HIDING_CHAR);
                break;
        }
    }

// ~~~~~~~~~~~~~~~~~~~~~~~~~ If player has either won or lost, loop ends ~~~~~~~~~~~~~~~~~~~~~~~~~ //

    if(won)
        std::cout << "YOU WON!" << "\n\n" << "The hidden word is indeed: " << picked_word << " !" << "\n";

    else
        std::cout << "YOU LOST!" << "\n\n" << "The hidden word was: " << picked_word << " !" << "\n";

    return 0;
}

/* ---------------------------------------------------------------------------------------------------------------- */

//std::cout << picked_word << "\n\n";