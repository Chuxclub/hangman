#include <iostream>
#include "std_lib_facilities.h"

string word_picker();
//Return random picked word

string word_concealer(string picked);
//Conceals random picked word

vector <size_t> occurrence_finder(string picked, string guess);
//Compares user char with chars in picked word
//Returns a vector with the positions of chars in string

/*string word_revealer(vector <size_t> a, string concealed, string guess);*/


/* ---------------------------------------------- HANGMAN GAME SOLO ---------------------------------------------- */

int main()
{
    bool won = false;

    string picked_word = word_picker();

    string concealed_word = word_concealer(picked_word);
    cout << concealed_word << "\n\n";

    std::cout << "Pick a letter: ";
    string user_letter_guess;

    while(!won)
    {
        std::cin >> user_letter_guess;
        std::cout << "\n";

        vector <size_t> occurrence_pos = occurrence_finder(picked_word, user_letter_guess);

        for(size_t x : occurrence_pos)
            concealed_word.replace(x, 1, user_letter_guess);

        cout << concealed_word << "\n\n";

        for (char x : concealed_word)
        {
            if(x == '*')
            {
                won = false;
                std::cout << "Pick a letter: ";
                break;
            }

            won = true;
        }
    }

    std::cout << "You won!";
    std::cout << "\n";

    return 0;
}

/* ---------------------------------------------------------------------------------------------------------------- */


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

    return picked_word;
}


string word_concealer(string picked)
{
    std::string concealed_word;

    for(int i = 0; i < picked.length(); i++)
        concealed_word.push_back('*'); //Temporary solution to not bother with blank spaces

    return concealed_word;
}

vector <size_t> occurrence_finder(string picked, string guess)
{
    vector <size_t> founds_vec;
    size_t found = picked.find(guess);

    if (found == std::string::npos)
        std::cout << "Try again!" << "\n\n";

    else
    {
        while(found != std::string::npos)
        {
            founds_vec.push_back(found);
            found = picked.find(guess, found + 1);
        }
    }

    return founds_vec;
}

/*string word_revealer(vector <size_t> a, string concealed, string guess)
{
    for(size_t x : a)
        concealed.replace(x, 1, guess);

    return concealed;
}*/


//std::cout << picked_word << "\n\n";
//concealed.replace(x, 1, guess);
//concealed.erase(x, 1);
//concealed.insert(x, guess);
//string revealing_word;