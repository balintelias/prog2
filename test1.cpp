#include "key.h"
#include "container.hpp"
#include "error.h"

#include <iostream>
#include <string>

// Első tesztfeladat, StrKey és std::string értékek vizsgálata

int main(int argc, char const *argv[])
{
    Container<StrKey, std::string> cont(8);

    std::cout << "insert_or_assign metódus tesztje:" << std::endl
              << std::endl;

    // Példa adatok:
    StrKey key1 = "pelda geza";
    std::string value1 = "06301111111";
    StrKey key2 = "minta janos";
    std::string value2 = "06302222222";

    StrKey key10 = "Kossuth Lajos";
    std::string value10 = "0630-1848-49";
    StrKey key11 = "Gorgei Artur";
    std::string value11 = "0630-1818-20";
    StrKey key12 = "Bem Jozsef";
    std::string value12 = "nincs telefonszama";
    StrKey key13 = "Petofi Sandor";
    std::string value13 = "1-800-273-8255";

    cont.insert_or_assign(key1, value1);
    cont.insert_or_assign(key10, value10);
    cont.insert_or_assign(key11, value11);
    cont.insert_or_assign(key12, value12);
    cont.insert_or_assign(key13, value13);
    cont.insert_or_assign(key2, value2);
    cont.print();
    std::cout << std::endl;

    std::string value21 = "0630SZERKESZTETT";
    cont.insert_or_assign(key2, value21);
    cont.print();
    std::cout << std::endl;

    std::cout << "find metódus és operator[] tesztje:" << std::endl
              << std::endl;

    StrKey key3 = "koder robert";
    std::cout << "find():" << std::endl
              << std::endl;

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

    std::cout << std::endl
              << "operator[]:" << std::endl
              << std::endl;
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

    std::cout << std::endl
              << "erase metódus tesztje:" << std::endl
              << std::endl;

    std::cout << "bennevan az elem:" << std::endl
              << "előtte:" << std::endl
              << std::endl;
    cont.print();
    std::cout << std::endl
              << "utána:" << std::endl
              << std::endl;
    cont.erase(key1);
    cont.print();
    std::cout << std::endl
              << "nincs benne az elem:" << std::endl
              << "előtte:" << std::endl
              << std::endl;
    cont.print();
    std::cout << std::endl
              << "utána:" << std::endl
              << std::endl;
    cont.erase(key1);
    cont.print();

    std::cout << std::endl
              << "másoló konstruktor tesztje:" << std::endl
              << std::endl;
    StrKey keycopy = "Varga Beles";
    std::string valuecpy = "0606060606060";
    Container<StrKey, std::string> copied(cont);
    copied.insert_or_assign(keycopy, valuecpy);
    std::cout << "Copied:" << std::endl
              << std::endl;
    copied.print();
    std::cout << std::endl
              << "eredeti:" << std::endl
              << std::endl;
    cont.print();

    std::cout << std::endl
              << "operator= tesztje:" << std::endl
              << std::endl;
    Container<StrKey, std::string> assigned = copied;
    assigned.print();

    std::cout << std::endl
              << "operator== tesztje:" << std::endl
              << std::endl;
    bool value;
    value = copied == assigned;
    std::cout << value << std::endl;
    return 0;
}