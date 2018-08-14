//
// Created by crex on 14/08/18.
//

#ifndef HANGMAN_TEXTURES_H
#define HANGMAN_TEXTURES_H

#include <iostream>
#include "std_lib_facilities.h"
#include "termcolor.hpp"

void main_title();
void main_menu_title();
void solo_title();
void solo_end_title();
void tries_title(int a);
void won_title();
void lost_title();
void sub_separator();
void main_separator();
void hangman_draw(int a);
void hangman_saved();

#endif //HANGMAN_TEXTURES_H
