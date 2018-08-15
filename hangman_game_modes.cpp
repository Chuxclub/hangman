//
// Created by crex on 14/08/18.
//

#include "std_lib_facilities.h"
#include "hangman_func.h"
#include "hangman_word.h"
#include "hangman_textures.h"
#include "hangman_game_modes.h"
#include "TSS.h"

void solo()
{
    bool player_continues;
    const int MAX_TRIES = 5;

    do
    {
        bool won = false, lost = false;
        int tries = 0;
        std::string user_guess;
        vector <string> wrong_guesses;
        hangman_word word;

        word.pick();
        word.conceal();

        std::cout << "\n\n\t\t\t\t  ";
        MinorTitle("SOLO MODE", "green");

// ~~~~~~~~~~~~~~~~~~~~~~~~~ If user has neither won nor lost, then loops ~~~~~~~~~~~~~~~~~~~~~~~~~ //

        while(!won && !lost) //If player has won, condition is false, same goes if he has lost
        {
            TriesTitle(MAX_TRIES - tries);
            std::cout << "\n\n";
            HangmanDraw(tries);

            std::cout << "\n\n\t" << "Hidden word: " << word.get_concealed() << "\n\n";

            std::cout << "\t" << "Pick a letter: ";
            std::cin >> user_guess;

            if(user_guess == "exit")
                break;
            else
                TestValidity(user_guess);

            word.find_occurrences(user_guess);

            if (word.occurrences().empty()) //Tests if occurrences of user's guessed letter have been found
            {
                wrong_guesses.push_back(user_guess);
                std::cout << "\t";
                PrintWrongGuesses(wrong_guesses);
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
            std::cout << "\n\t";
            SubTitleSeparator(21, "YOU SAVED HANGMAN", "green");
            std::cout << "\n";

            HangmanSaved();

            std::cout << "\n\t" << "The hidden word is indeed: " << word.get_picked() << " !" << "\n";
            std::cout << "\n\t";
            SubSeparator(62);

            player_continues = NewGame();

            std::cout << "\n\t\t\t\t ";
            MinorTitle("SOLO ENDS", "green");
            std::cout << "\n\n";
        }


        else
        {
            std::cout << "\n\t";
            SubTitleSeparator(21, "HANGMAN IS DEAD", "red");
            std::cout << "\n\n";

            HangmanDead();

            std::cout << "\n\t" << "The hidden word was: " << word.get_picked() << " !" << "\n";
            std::cout << "\n\t";
            SubSeparator(60);

            player_continues = NewGame();

            std::cout << "\n\t\t\t\t  ";
            MinorTitle("SOLO ENDS", "green");
            std::cout << "\n\n";
        }

    } while(player_continues);

    std::cout << "\n";
}


