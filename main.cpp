#include <iostream>
#include "std_lib_facilities.h"

string word_picker();
vector <size_t> occurrence_finder(string picked, char guess);

int main()
{
    string picked_word = word_picker();

    std::cout << "Pick a letter: ";

    char user_letter_guess = 'o';
    std::cin >> user_letter_guess;
    std::cout << "\n";

    occurrence_finder(picked_word, user_letter_guess);

    return 0;
}

string word_picker()
{
    vector<string> dictionary;
    fstream file("/home/crex/CLionProjects/hangman/words_alpha.txt"); //Warning! Works only on this environment!
    std::string words;

    while(file >> words)
    {
        dictionary.push_back(words);
    }

    srand((unsigned int) time(nullptr));
    constexpr int TOTAL_OF_WORDS = 370099;
    int x = rand()%TOTAL_OF_WORDS;
    std::string picked_word = dictionary[x];

    for(int i = 0; i < picked_word.length(); i++)
        std::cout << "_ ";

    std::cout << "\n\n";

    return picked_word;
}

vector <size_t> occurrence_finder(string picked, char guess)
{
    vector <size_t> founds_vec;
    size_t found = picked.find(guess);

    if (found == std::string::npos)
        std::cout << "This letter isn't in my word!" << "\n";

    else
    {
        while(found != std::string::npos) //Doesn't work at all! Don't run!
        {
            founds_vec.push_back(found);

            std::cout << picked.at(found);

            found = picked.find(guess, found + 1);
        }
    }

    return founds_vec;
}


//std::cout << picked_word << "\n\n";