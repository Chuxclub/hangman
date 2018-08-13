//
// Created by crex on 12/08/18.
//

#include <iostream>
#include "std_lib_facilities.h"
#include "hangman_func.h"

void print_wrong_guesses(vector <string> const& wrong_guesses)
{
    std::cout << "Wrong letters: " ;

    for (string const& x : wrong_guesses)
        std::cout << x << ", ";

    std::cout << "\n\n";
}

