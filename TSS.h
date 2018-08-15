//
// Created by crex on 15/08/18.
//

#ifndef HANGMAN_TSS_H
#define HANGMAN_TSS_H

#include"termcolor.hpp"
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include<forward_list>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<array>
#include<regex>
#include<random>
#include<stdexcept>

using namespace std;

void MainTitleSeparator(int a, std::string const& title, std::string const& color);
void MainTitleSeperator(int a, std::string const& title);

void SubTitleSeparator(int a, std::string const& title, std::string const& color);
void SubTitleSeparator(int a, std::string const& title);

void SubSeparator(int a);

void MainSeparator(int a);

void MinorTitle(std::string const& title, std::string const& color);
void MinorTitle(std::string const& title);

#endif //HANGMAN_TSS_H
