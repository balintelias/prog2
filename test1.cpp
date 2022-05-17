#include "key.h"
#include "container.hpp"
#include "error.h"

#include <iostream>
#include <string>

//Első tesztfeladat, StrKey és std::string értékek vizsgálata

int main(int argc, char const *argv[])
{
    Container<StrKey, std::string> cont(5);

    std::cout << "insert_or_assign metódus tesztje:" << std::endl
              << std::endl;

    StrKey key1 = "pelda geza";
    std::string value1 = "06301111111";
    cont.insert_or_assign(key1, value1);
    cont.print();
    std::cout << std::endl;

    StrKey key2 = "minta janos";
    std::string value2 = "06302222222";
    cont.insert_or_assign(key2, value2);
    cont.print();
    std::cout << std::endl;

    std::string value21 = "06302222233";
    cont.insert_or_assign(key2, value21);
    cont.print();
    std::cout << std::endl;

    std::cout << "find metódus és operator[] tesztje:" << std::endl
              << std::endl;

    StrKey key3 = "koder robert";
    std::cout << "find():" << std::endl;

    try
    {
        std::cout << cont.find(key2).second << std::endl;
    }
    catch (NotInList &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << cont.find(key3).second << std::endl;
    }
    catch (NotInList &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "operator[]:" << std::endl;
    try
    {
        std::cout << cont[key2] << std::endl;
    }
    catch (NotInList &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << cont[key3] << std::endl;
    }
    catch (NotInList &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "erase metódus tesztje:" << std::endl
              << std::endl;

    std::cout << "bennevan az elem:" << std::endl
              << "előtte:" << std::endl;
    cont.print();
    std::cout << "utána:" << std::endl;
    cont.erase(key1);
    cont.print();
    std::cout << std::endl
              << "nincs benne az elem:" << std::endl
              << "előtte:" << std::endl;
    cont.print();
    std::cout << "utána:" << std::endl;
    cont.erase(key1);
    cont.print();

    std::cout << "másoló konstruktor tesztje:" << std::endl
              << std::endl;
    StrKey keycopy = "Varga Beles";
    std::string valuecpy = "0606060606060";
    Container<StrKey, std::string> copied(cont);
    copied.insert_or_assign(keycopy, valuecpy);
    std::cout << "Copied:" << std::endl;
    copied.print();
    std::cout << "OG:" << std::endl;
    cont.print();

    std::cout << "operator= tesztje:" << std::endl
              << std::endl;
    Container<StrKey, std::string> assigned = copied;
    assigned.print();

    std::cout << "operator== tesztje:" << std::endl
              << std::endl;
    bool value;
    value = copied == assigned;
    std::cout << value << std::endl;
    return 0;
}