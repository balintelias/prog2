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
              << "H - hozzaadas az adatbazishoz/meglevo elem szerkesztese" << std::endl
              << "L - adat lekerdezese" << std::endl
              << "P - adatbazis tartalmanak megjelenitese" << std::endl
              << "Q - kilepes a programbol" << std::endl
              << std::endl;
}

bool isValid(char param)
{
    std::string valid = "HLPQ";
    for (int i = 0; i < valid.length(); i++)
    {
        if (param == valid[i])
            return true;
    }
    return false;
}

char getUserInput()
{
    char reply = getchar();
    getchar();
    if (isValid(reply))
        return reply;
    InvalidInput ex;
    throw ex;
}

StrKey getKeyFromUser()
{
    std::cout << "Add meg a kulcsot:" << std::endl;
    std::string input;
    getline(std::cin, input);
    StrKey reply(input);
    return reply;
}

std::string getValueFromUser()
{
    std::cout << "Add meg az erteket:" << std::endl;
    std::string reply;
    getline(std::cin, reply);
    return reply;
}