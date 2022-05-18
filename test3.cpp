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
    char userInput;
    while (1)
    {
        try
        {
            userInput = getUserInput();
        }
        catch (InvalidInput &e)
        {
            std::cerr << e.what() << '\n';
        }
        switch (userInput)
        {
        case 'H':
            key = getKeyFromUser();
            value = getValueFromUser();
            database.insert_or_assign(key, value);
            std::cout << "Sikeresen eltarolva";
            break;
        case 'L':
            key = getKeyFromUser();
            try
            {
                value = database.find(key).second;
                std::cout << "A kulcshoz tartozo adat: " << value << std::endl;
            }
            catch (NotInList &e)
            {
                std::cerr << e.what() << '\n';
            }
            break;
        case 'P':
            std::cout << "Az adatbazisban szereplo adatok:" << std::endl;
            database.print();
            break;
        }
        if (userInput == 'Q')
        {
            break;
        }
        std::cout << std::endl;
        menu();
    }
    return 0;
}
