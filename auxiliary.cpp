#include "key.h"
#include "container.hpp"
#include "error.h"
#include "auxiliary.h"

#include <iostream>
#include <string>

void init()
{
    std::cout << "Udv a programban." << std::endl;
}

void menu()
{
    std::cout << "Valassz, mit szeretnel tenni:" << std::endl
              << "H - hozzaadas az adatbazishoz" << std::endl
              << "L - adat lekerdezese" << std::endl
              << "S - adat szerkesztese" << std::endl
              << "Q - kilepes a programbol"<<std::endl
              << std::endl;
}

char getUserInput()
{
    char reply = getchar();
    if (reply == 'H' || reply == 'L' || reply == 'S' || reply == 'Q')
    {
        return reply;
    }
    return '\0';
}

StrKey getKeyFromUser()
{
    std::cout << "Add meg a kulcsot:" << std::endl;
    std::string input;
    // input helye
    StrKey reply(input);
    return reply;
}

std::string getValueFromUser()
{
    std::cout << "Add meg az erteket:" << std::endl;
    std::string reply;
    // input helye;
    return reply;
}