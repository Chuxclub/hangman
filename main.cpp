#include <iostream>
#include "std_lib_facilities.h"
#include "hangman_func.h"
#include "hangman_word.h"
#include "termcolor.hpp"

/* ---------------------------------------------- HANGMAN GAME SOLO ---------------------------------------------- */

int main()
{
    while(true)
    {
        std::cout << "\n" << "* ==================== ";
        std::cout << termcolor::cyan << "WELCOME TO HANGMAN GAME!" << termcolor::reset;
        std::cout << " ==================== *";

        bool won = false, lost = false;
        char again_choice;
        int tries = 0;
        const int MAX_TRIES = 5;
        std::string user_guess;
        vector <string> wrong_guesses;
        hangman_word word;

        word.pick();
        word.conceal();

// ~~~~~~~~~~~~~~~~~~~~~~~~~ If user has neither won nor lost, then loops ~~~~~~~~~~~~~~~~~~~~~~~~~ //

        while(!won && !lost) //If player has won, condition is false, same goes if he has lost
        {
            if (MAX_TRIES - tries > 1)
            {
                std::cout << "\n\n\t" <<"<----------------------- ";
                std::cout << termcolor::grey << MAX_TRIES - tries << " tries left" << termcolor::reset;
                std::cout << " ----------------------->";
            }

            else
            {
                std::cout << "\n\n\t" <<"<----------------------- ";
                std::cout << termcolor::grey << MAX_TRIES - tries << " try left" << termcolor::reset;
                std::cout << " ----------------------->";
            }


            std::cout << "\n\n\t" << "Hidden word: " << word.get_concealed() << "\n\n";

            std::cout << "\t" << "Pick a letter: ";
            std::cin >> user_guess;
            test_validity(user_guess);

            word.find_occurrences(user_guess);

            if (word.occurrences().empty()) //Tests if occurrences of user's guessed letter have been found
            {
                wrong_guesses.push_back(user_guess);
                std::cout << "\t";
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
        {
            std::cout << "\n\t" << "<----------------------- ";
            std::cout << termcolor::green << "YOU WON!" << termcolor::reset;
            std::cout << " ----------------------->" << "\n";
            std::cout << "\n\t" << "The hidden word is indeed: " << word.get_picked() << " !" << "\n";

            std::cout << "\n\t" << "<-------------------------------------------------------->";
            std::cout << "\n\n\t" << termcolor::green << "Want a new game?" << termcolor::reset;
            std::cout << " Any key for yes, 'n' for exit: ";
            std::cin >> again_choice;


            if (again_choice == 'n')
            {
                std::cout << "\n" << "* ================================================================== *" << "\n";
                break;
            }

            else
                std::cout << "\n\n";
        }


        else
        {
            std::cout << "\n\t" << "<----------------------- ";
            std::cout << termcolor::red << "YOU LOST!" << termcolor::reset;
            std::cout << " ----------------------->" << "\n";
            std::cout << "\n\t" << "The hidden word was: " << word.get_picked() << " !" << "\n";

            std::cout << "\n\t" << "<--------------------------------------------------------->";
            std::cout << "\n\n\t" << termcolor::green << "Want a new game?" << termcolor::reset;
            std::cout << " Any key for yes, 'n' for exit: ";
            std::cin >> again_choice;

            if (again_choice == 'n')
            {
                std::cout << "\n" << "* ================================================================== *" << "\n";
                break;
            }

            else
                std::cout << "\n\n";
        }
    }

    return 0;
}

/* ---------------------------------------------------------------------------------------------------------------- */