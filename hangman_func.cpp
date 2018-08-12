//
// Created by crex on 12/08/18.
//

#include <iostream>
#include "std_lib_facilities.h"
#include "hangman_func.h"


string word_picker()
{
    vector<string> dictionary;
    fstream file("words_alpha.txt"); //Warning! Works only on this environment!
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


string word_concealer(string const& picked, char HIDING_CHAR)
{
    std::string concealed_word;

    for(int i = 0; i < picked.length(); i++)
        concealed_word.push_back(HIDING_CHAR); //Temporary solution to not bother with blank spaces

    return concealed_word;
}

vector <size_t> occurrence_finder(string const& picked, string const& guess)
{
    std::size_t found = picked.find(guess);
    vector <size_t> founds_vec;

    while(found != std::string::npos)
    {
        founds_vec.push_back(found);
        found = picked.find(guess, found + 1);
    }

    return founds_vec;
}

void print_wrong_guesses(vector <string> const& wrong_guesses)
{
    std::cout << "Wrong letters: " ;

    for (string const& x : wrong_guesses)
        std::cout << x << ", ";

    std::cout << "\n\n";
}

string letter_revealer (vector <size_t> const& occurrence, string &concealed, string const& guess)
{
    for(size_t x : occurrence)
        concealed.replace(x, 1, guess);

    return concealed;
}

bool win_checker(string const& concealed, char HIDING_CHAR)
{
    for (char x : concealed)
    {
        if(x == HIDING_CHAR)
            return false;
    }

    return true;
}

