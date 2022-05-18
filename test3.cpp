#include "key.h"
#include "container.hpp"
#include "error.h"
#include "auxiliary.h"

#include <iostream>
#include <string>

// A házi feladat működésének komplex bemutatóprogramja
// A program egy adatbázist és a hozzávaló interface-t szimulálja,
// amelyben nevekhez telefonszámokat rendelünk.

// A felhasználó az összes alapvető funkcionalitást kipróbálhatja az interface-en keresztül.

int main(int argc, char const *argv[])
{
    try
    {
        init();
        Container<StrKey, std::string> database;
        menu();
        while (1)
        {
            char userInput = getUserInput();
            getchar();
            switch (userInput)
            {
            case 'H':
                std::cout << "Ilyenkor hozzaad" << std::endl;
                break;
            case 'L':
                std::cout << "Ilyenkor lekerdez" << std::endl;
                break;
            case 'S':
                std::cout << "Ilyenkor szerkeszt" << std::endl;
                break;
            case '\0':
                std::cout << "Ervenytelen bemenet" << std::endl;
                break;
            }
            if (userInput == 'Q')
            {
                break;
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}