#include <iostream>
#include "std_lib_facilities.h"

int main()
{
    vector<string> dictionary;
    fstream file("/home/florian/CLionProjects/hangman/words_alpha.txt");
    std::string words;

    while(file >> words)
    {
        dictionary.push_back(words);
    }

    srand((unsigned int) time(nullptr));
    int i = rand()%370099;

    std::cout << dictionary[i] << "\n";

    return 0;
}