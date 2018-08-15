//
// Created by crex on 14/08/18.
//

#include "hangman_textures.h"

void TriesTitle(int a)
{
    if (a > 1)
    {
        std::cout << "\n\n\t" <<"<----------------------- ";
        std::cout << termcolor::grey << a << " tries left" << termcolor::reset;
        std::cout << " ----------------------->";
    }

    else
    {
        std::cout << "\n\n\t" <<"<------------------------ ";
        std::cout << termcolor::grey << a << " try left" << termcolor::reset;
        std::cout << " ------------------------>";
    }
}

void HangmanDraw(int a)
{
    switch(a)
    {
        case 0:
            break;

        case 1:
            std::cout << "\t" << "--------------------------" << "\n";
            std::cout << "\t" << "| " << "Hangman is in the jail" << " |" << "\n";
            std::cout << "\t" << "--------------------------" << "\n";
            break;

        case 2:
            std::cout << "\t" << "---------------------------" << "\n";
            std::cout << "\t" << "| " << "Hangman hopes for pardon" << " |" << "\n";
            std::cout << "\t" << "---------------------------" << "\n\n";

            std::cout << "\t" << "|" << "\n";
            std::cout << "\t" << "|" << "\n";
            std::cout << "\t" << "|" << "\n";
            std::cout << "\t" << "|" << "\n";
            std::cout << "\t" << "\u22A5" << "\n";
            break;

        case 3:
            std::cout << "\t" << "------------------------------" << "\n";
            std::cout << "\t" << "| " << "Hangman prays for his souls" << " |" << "\n";
            std::cout << "\t" << "------------------------------" << "\n\n";

            std::cout << "\t" << "------" << "\n";
            std::cout << "\t" << "|     " << "\n";
            std::cout << "\t" << "|" << "\n";
            std::cout << "\t" << "|" << "\n";
            std::cout << "\t" << "|" << "\n";
            std::cout << "\t" << "\u22A5" << "\n";
            break;

        case 4:
            std::cout << "\t" << "---------------------------------------------" << "\n";
            std::cout << "\t" << "| " << "Hangman shivers as he looks at the gallows" << " |" << "\n";
            std::cout << "\t" << "---------------------------------------------" << "\n\n";

            std::cout << "\t" << "------" << "\n";
            std::cout << "\t" << "|    |" << "\n";
            std::cout << "\t" << "|" << "\n";
            std::cout << "\t" << "|" << "\n";
            std::cout << "\t" << "|" << "\n";
            std::cout << "\t" << "\u22A5" << "\n";
            break;

        case 5:
            std::cout << "\t" << "------" << "\n";
            std::cout << "\t" << "|    |" << "\n";
            std::cout << "\t" << "|    O" << "\n";
            std::cout << "\t" << "|   /|\\" << "\n";
            std::cout << "\t" << "|   / \\" << "\n";
            std::cout << "\t" << "\u22A5" << "\n";
            break;

        default:
            std::cout << termcolor::red << "\t" << "Something went wrong, no hangman can be produced" << termcolor::reset;
    }
}

void HangmanSaved()
{
    std::cout << "\t" << "\\O/" << "\n";
    std::cout << "\t" << " |" << "\n";
    std::cout << "\t" << "/ \\" << "\n";
}