//
// Created by crex on 13/08/18.
//

#ifndef HANGMAN_HANGMAN_WORD_H
#define HANGMAN_HANGMAN_WORD_H

#include <iostream>
#include "std_lib_facilities.h"


class hangman_word
{

private:

    string picked_word;
    string concealed_word;
    vector <size_t> occurrence_pos;
    const char HIDING_CHAR = '*';

public:

    void pick();
    //Returns random picked word

    void conceal();
    //Returns a string of hiding characters equalling length of picked_word
    //Thus mimics "conceal"

    void find_occurrences(string const& guess);
    //Compares user char with chars in picked word
    //Returns a vector with the positions of chars in string

    void reveal(string const& guess);
    //Reveals found letters: takes positions from find_occurrences then replaces chars in concealed_word with given pos
    //by user_letter_guess

    void clear_occurrences();
    //Clears occurrence_pos to avoid remembering former positions and hence doing wrong replacements after loops

    bool check();
    //Checks if there's any remaining '*' in concealed_word, if there's no '*' returns true

    string get_picked();
    //Returns string picked_word

    string get_concealed();
    //Returns string concealed_word

    vector <size_t> occurrences();
    //Returns occurrence_pos
};

#endif //HANGMAN_HANGMAN_WORD_H
