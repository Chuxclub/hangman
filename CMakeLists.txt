cmake_minimum_required(VERSION 3.9)
project(hangman)

set(CMAKE_CXX_STANDARD 14)

add_executable(hangman main.cpp std_lib_facilities.h hangman_func.cpp hangman_func.h hangman_word.cpp hangman_word.h termcolor.hpp textures.cpp textures.h hangman_game_modes.cpp hangman_game_modes.h)
