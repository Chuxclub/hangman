//
// Created by crex on 13/08/18.
//

#include <iostream>
#include "std_lib_facilities.h"
#include "hangman_word.h"

void hangman_word::pick()
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
    picked_word = dictionary[x];
}

void hangman_word::conceal()
{
    for (int i = 0; i < picked_word.length(); i++)
        concealed_word.push_back(HIDING_CHAR); //Temporary solution to not bother with blank spaces
}

void hangman_word::find_occurrences(string const& guess)
{
    std::size_t found = picked_word.find(guess);

    while(found != std::string::npos)
    {
        occurrence_pos.push_back(found);
        found = picked_word.find(guess, found + 1);
    }
}

void hangman_word::reveal(string const& guess)
{
    for(size_t x : occurrence_pos)
        concealed_word.replace(x, 1, guess);
}

void hangman_word::clear_occurrences()
{
    occurrence_pos.clear();
}

bool hangman_word::check()
{
    for (char x : concealed_word)
    {
        if(x == HIDING_CHAR)
            return false;
    }

    return true;
}

string hangman_word::get_picked()
{
    return picked_word;
}

string  hangman_word::get_concealed()
{
    return concealed_word;
}

vector <size_t> hangman_word::occurrences()
{
    return occurrence_pos;
}

