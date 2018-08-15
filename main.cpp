#include "std_lib_facilities.h"
#include "hangman_game_modes.h"
#include "TSS.h"

/* ---------------------------------------------- HANGMAN GAME SOLO ---------------------------------------------- */

int main()
{
    unsigned short int user_selection = 0;
    bool stay = true, valid_input;

    std::cout << "\n     ";
    MainTitleSeparator(20, "WELCOME TO HANGMAN GAME!", "cyan");
    std::cout << "\n\n";

    while(stay)
    {
        std::cout << "\t\t\t\t  ";
        MinorTitle("MAIN MENU", "green");
        std::cout << "\n\n";

        do
        {
            std::cout << "\t" << "1. Solo mode" << "\n";
            std::cout << "\t" << "2. Exit" << "\n\n";
            std::cout << "\t" << "Your selection: ";
            std::cin >> user_selection;

            if(!cin || user_selection < 1 || user_selection > 2)
            {
                valid_input = false;
                cin.clear();
                cin.ignore(1000, '\n');
                std::cout << "\t" << termcolor::red << "Wrong input! Press 1 or 2!" << termcolor::reset <<"\n\n";
            }

            else
            {
                switch(user_selection)
                {
                    case 1:
                        valid_input = true;
                        solo();
                        break;

                    case 2:
                        valid_input = true;
                        stay = false;
                        std::cout << "\n     ";
                        MainSeparator(66);
                        std::cout << "\n\n";
                        break;

                    default:
                        valid_input = false;
                        std::cout << "\t" << termcolor::red << "Wrong input! Press 1 or 2!" << termcolor::reset <<"\n\n";
                        break;
                }
            }

        }while (!valid_input);
    }

    return 0;
}

/* ---------------------------------------------------------------------------------------------------------------- */