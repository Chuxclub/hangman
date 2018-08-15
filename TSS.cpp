//
// Created by crex on 15/08/18.
//

#include "TSS.h"


void MainTitleSeparator(int a, std::string const& title, std::string const& color)
{
    std::string main_separator;

    for(int i = 0; i < a; i++)
        main_separator.push_back('=');

    if (color == "red")
        std::cout << "* " << main_separator << " " << termcolor::red << title << " " << termcolor::reset << main_separator << " *";

    else if (color == "blue")
        std::cout << "* " << main_separator << " " << termcolor::blue << title << " " << termcolor::reset << main_separator << " *";

    else if (color == "cyan")
        std::cout << "* " << main_separator << " " << termcolor::cyan << title << " " << termcolor::reset << main_separator << " *";

    else if (color == "yellow")
        std::cout << "* " << main_separator << " " << termcolor::yellow << title << " " << termcolor::reset << main_separator << " *";

    else if (color == "green")
        std::cout << "* " << main_separator << " " << termcolor::green << title << " " << termcolor::reset << main_separator << " *";

    else if (color == "magenta")
        std::cout << "* " << main_separator << " " << termcolor::magenta << title << " " << termcolor::reset << main_separator << " *";

    else if (color == "grey")
        std::cout << "* " << main_separator << " " << termcolor::grey << title << " " << termcolor::reset << main_separator << " *";

    else if (color == "white")
        std::cout << "* " << main_separator << " " << termcolor::white << title << " " << termcolor::reset << main_separator << " *";

    else
        std::cerr << "Wrong color input in function main_title_separator!";

}

void MainTitleSeperator(int a, std::string const& title)
{
    std::string main_separator;

    for(int i = 0; i < a; i++)
        main_separator.push_back('=');

    std::cout << "* " << main_separator << " " << title << " " << main_separator << " *";
}

void SubTitleSeparator(int a, std::string const& title, std::string const& color)
{
    std::string sub_separator;

    for(int i = 0; i < a; i++)
        sub_separator.push_back('-');

    if (color == "red")
        std::cout << "<" << sub_separator << " " << termcolor::red << title << " " << termcolor::reset << sub_separator << ">";

    else if (color == "blue")
        std::cout << "<" << sub_separator << " " << termcolor::blue << title << " " << termcolor::reset << sub_separator << ">";

    else if (color == "cyan")
        std::cout << "<" << sub_separator << " " << termcolor::cyan << title << " " << termcolor::reset << sub_separator << ">";

    else if (color == "yellow")
        std::cout << "<" << sub_separator << " " << termcolor::yellow << title << " " << termcolor::reset << sub_separator << ">";

    else if (color == "green")
        std::cout << "<" << sub_separator << " " << termcolor::green << title << " " << termcolor::reset << sub_separator << ">";

    else if (color == "magenta")
        std::cout << "<" << sub_separator << " " << termcolor::magenta << title << " " << termcolor::reset << sub_separator << ">";

    else if (color == "grey")
        std::cout << "<" << sub_separator << " " << termcolor::grey << title << " " << termcolor::reset << sub_separator << ">";

    else if (color == "white")
        std::cout << "<" << sub_separator << " " << termcolor::white << title << " " << termcolor::reset << sub_separator << ">";

    else
        std::cerr << "Wrong color input in function sub_title_separator!";

}

void SubTitleSeparator(int a, std::string const& title)
{
    std::string sub_separator;

    for(int i = 0; i < a; i++)
        sub_separator.push_back('-');

    std::cout << "<" << sub_separator << " " << title << " " << sub_separator << ">";
}

void SubSeparator(int a)
{
    std::cout << "<";

    for(int i = 0; i < a; i++)
        std::cout << "-";

    std::cout << ">";
}

void MainSeparator(int a)
{
    std::cout << "* ";

    for(int i = 0; i < a; i++)
        std::cout << "=";

    std::cout << " *";
}

void MinorTitle(std::string const& title, std::string const& color)
{
    if (color == "red")
        std::cout << "<" << termcolor::red << title << termcolor::reset << ">";

    else if (color == "blue")
        std::cout << "<" << termcolor::blue << title << termcolor::reset << ">";

    else if (color == "cyan")
        std::cout << "<" << termcolor::cyan << title << termcolor::reset << ">";

    else if (color == "yellow")
        std::cout << "<" << termcolor::yellow << title << termcolor::reset << ">";

    else if (color == "green")
        std::cout << "<" << termcolor::green << title << termcolor::reset << ">";

    else if (color == "magenta")
        std::cout << "<" << termcolor::magenta << title << termcolor::reset << ">";

    else if (color == "grey")
        std::cout << "<" << termcolor::grey << title << termcolor::reset << ">";

    else if (color == "white")
        std::cout << "<" << termcolor::white << title << termcolor::reset << ">";

    else
        std::cerr << "Wrong color input in function minor_title!";
}

void MinorTitle(std::string const& title)
{
    std::cout << "<" << title << ">";
}
