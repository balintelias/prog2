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
    init();
    Container<StrKey, std::string> database;
    menu();
    StrKey key;
    std::string value;
    while (1)
    {
        char userInput = getUserInput();
        getchar();
        switch (userInput)
        {
        case 'H':
            try
            {
                key = getKeyFromUser();
                value = getValueFromUser();
                database.insert_or_assign(key, value);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }
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
        menu();
    }
    return 0;
}
