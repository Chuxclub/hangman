#include <iostream>
#include "std_lib_facilities.h"

string word_picker();
//Return random picked word

string word_concealer(string const& picked);
//Conceals random picked word

vector <size_t> occurrence_finder(string const& picked, string const& guess);
//Compares user char with chars in picked word
//Returns a vector with the positions of chars in string


/* ---------------------------------------------- HANGMAN GAME SOLO ---------------------------------------------- */

int main()
{
    bool won = false, lost = false;
    int tries = 0;
    const int MAX_TRIES = 5;

    string user_letter_guess;
    string picked_word = word_picker();
    string concealed_word = word_concealer(picked_word);

    vector <size_t> occurrence_pos;
    vector <string> wrong_guesses;


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
            tries++;

            std::cout << "Wrong letters: " ;

            for (string const& x : wrong_guesses)
                std::cout << x << ", ";

            std::cout << "\n\n";
        }

        else
        {
            for(size_t x : occurrence_pos)
                concealed_word.replace(x, 1, user_letter_guess); //Reveals found letters
        }

// ~~~~~~~~~~~~~~~~~~~~~~~~~ Tests whether the user has won or lost ~~~~~~~~~~~~~~~~~~~~~~~~~ //

        switch(tries)
        {
            case MAX_TRIES:
                lost = true;
                break;

            default:

                for (char x : concealed_word)
                {
                    if(x == '*')
                    {
                        won = false;
                        break;
                    }

                    won = true;
                }

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


string word_picker()
{
    vector<string> dictionary;
    fstream file("/home/crex/CLionProjects/hangman/words_alpha.txt"); //Warning! Works only on this environment!
    std::string words;

    while(file >> words)
    {
        dictionary.push_back(words);
    }

    srand((unsigned int) time(nullptr));
    constexpr int TOTAL_OF_WORDS = 370099;
    int x = rand()%TOTAL_OF_WORDS;
    std::string picked_word = dictionary[x];

    return picked_word;
}


string word_concealer(string const& picked)
{
    std::string concealed_word;

    for(int i = 0; i < picked.length(); i++)
        concealed_word.push_back('*'); //Temporary solution to not bother with blank spaces

    return concealed_word;
}

vector <size_t> occurrence_finder(string const& picked, string const& guess)
{
    size_t found = picked.find(guess);
    vector <size_t> founds_vec;

    while(found != std::string::npos)
    {
        founds_vec.push_back(found);
        found = picked.find(guess, found + 1);
    }

    return founds_vec;
}

//std::cout << picked_word << "\n\n";