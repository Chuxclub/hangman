//
// Created by crex on 12/08/18.
//
#ifndef HANGMAN_HANGMAN_FUNC_H
#define HANGMAN_HANGMAN_FUNC_H

#include <iostream>
#include "std_lib_facilities.h"

string word_picker();
//Return random picked word

string word_concealer(string const& picked, char HIDING_CHAR);
//Conceals random picked word with a hiding character
//Returns a string of hiding characters equalling length of picked_word

vector <size_t> occurrence_finder(string const& picked, string const& guess);
//Compares user char with chars in picked word
//Returns a vector with the positions of chars in string

string letter_revealer (vector <size_t> const& occurrence, string &concealed, string const& guess);
//Reveals found letters: takes positions from occurrence_finder then replaces concealed chars in given pos
//By user_letter_guess

void print_wrong_guesses(vector <string> const& wrong_guesses);
//Prints all wrong guesses already done by user

bool win_checker(string const& concealed, char HIDING_CHAR);
//Checks any remaining *, if there is any *, returns false, if not returns true

#endif //HANGMAN_HANGMAN_FUNC_H
