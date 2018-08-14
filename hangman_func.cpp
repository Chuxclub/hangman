//
// Created by crex on 12/08/18.
//

#include <iostream>
#include "std_lib_facilities.h"
#include "hangman_func.h"
#include "termcolor.hpp"
#include "textures.h"

void print_wrong_guesses(vector <string> const& wrong_guesses)
{
    std::cout << termcolor::yellow << "Wrong letters: " << termcolor::reset;

    for (int i = 0; i < wrong_guesses.size(); i++)
    {
        if(i == wrong_guesses.size() - 1)
            std::cout << wrong_guesses[i] << ".";

        else
            std::cout << wrong_guesses[i] << ", ";
    }

    std::cout << "\n\n";
}

string test_validity(string &guess)
{
    constexpr int GUESS_MAX_SIZE = 1, A_ASCII_CODE = 97, Z_ASCII_CODE = 122;
    //Won't work in many other languages though...
    //Foreign characters like 'é' trigger guess.length() > 1 instead of the other test
    //Design seems lame

    while (guess.length() > GUESS_MAX_SIZE || !(guess.front() >= A_ASCII_CODE && guess.front() <= Z_ASCII_CODE))
    {
        if (guess.length() > 1)
        {
            std::cout << termcolor::red << "\t" << "Input just one letter!" << termcolor::reset << "\n\n";
            std::cout << "\t" << "Pick a letter: ";
            std::cin >> guess;
        }

        else if (!(guess.front() >= 97 && guess.front() <= 122))
        {
            std::cout << termcolor::red << "\t"<< "Input a letter!" << termcolor::reset << "\n\n";
            std::cout << "\t" << "Pick a letter: ";
            std::cin >> guess;
        }
    }

    return guess;
}

bool new_game()
{
    char choice;
    bool output = false, wrong_input;

    do
    {
        std::cout << "\n\n\t" << termcolor::green << "Want a new game?" << termcolor::reset;
        std::cout << " Press 'y' for yes, 'n' for no: ";
        std::cin >> choice;

        switch(choice)
        {
            case 'y':
                std::cout << "\n\n";
                wrong_input = false;
                output = true;
                break;
            case 'n':
                main_separator();
                wrong_input = false;
                output = false;
                break;
            default:
                std::cout << termcolor::red << "\t" << "Wrong input!" << termcolor::reset;
                wrong_input = true;
                break;
        }

    } while (wrong_input);


    return output;
}

