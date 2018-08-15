//
// Created by crex on 12/08/18.
//
#ifndef HANGMAN_HANGMAN_FUNC_H
#define HANGMAN_HANGMAN_FUNC_H

#include <iostream>
#include "std_lib_facilities.h"

void PrintWrongGuesses(vector <string> const& wrong_guesses);
//Prints all wrong guesses already done by user

string TestValidity(string &guess);
//Tests if user_input is valid, meaning two conditions: 1 character, character is a small letter

bool NewGame();

#endif //HANGMAN_HANGMAN_FUNC_H
