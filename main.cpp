#include <iostream>
#include "std_lib_facilities.h"
#include "textures.h"
#include "hangman_game_modes.h"

/* ---------------------------------------------- HANGMAN GAME SOLO ---------------------------------------------- */

int main()
{
    int user_selection = 0;
    bool stay = true, valid_input;

    main_title();
    std::cout << "\n\n";

    while(stay)
    {
        main_menu_title();
        std::cout << "\n\n";

        do
        {
            std::cout << "\t" << "1. Solo mode" << "\n";
            std::cout << "\t" << termcolor::red << "2. Versus mode" << termcolor::reset << "\n";
            std::cout << "\t" << termcolor::red << "3. Options" << termcolor::reset << "\n";
            std::cout << "\t" << "4. Exit" << "\n\n";
            std::cout << "\t" << "Your selection: ";
            std::cin >> user_selection;

            if(!cin || user_selection < 1 || user_selection > 4)
            {
                cin.clear();
                cin.ignore(1000, '\n');
                std::cout << "\t" << termcolor::red << "Wrong input! Press 1, 2, 3 or 4!";
                std::cout << termcolor::reset <<"\n\n";
                valid_input = false;
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
                        valid_input = false;
                        std::cout << "\t" << termcolor::red << "Unavailable feature for the moment, WIP!";
                        std::cout << termcolor::reset <<  "\n\n";
                        break;

                    case 3:
                        valid_input = false;
                        std::cout << "\t" << termcolor::red << "Unavailable feature for the moment, WIP!";
                        std::cout << termcolor::reset <<  "\n\n";
                        break;

                    case 4:
                        valid_input = true;
                        stay = false;
                        std::cout << "\n";
                        main_separator(66);
                        break;

                    default:
                        valid_input = false;
                        std::cout << "\t" << termcolor::red << "Wrong input! Press 1, 2, 3 or 4!";
                        std::cout << termcolor::reset <<"\n\n";
                        break;
                }
            }


        }while (!valid_input);

    }

    return 0;
}

/* ---------------------------------------------------------------------------------------------------------------- */