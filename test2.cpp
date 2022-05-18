#include "key.h"
#include "container.hpp"
#include "error.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    try
    {
        Container<IntKey, int> container(8);
        IntKey key1 = 10;
        IntKey key2 = 10000;
        int value1 = 15;
        int value11 = 16;
        container.insert_or_assign(key1, value1);
        container.insert_or_assign(key1, value11);
        container.print();
        Container<IntKey, std::string> cont(8);
        bool val = true;
        // val = container == cont; //invalid comparison
        std::cout << val << std::endl;

        std::cout << container.find(key1).second << std::endl;
        std::cout << container.find(key2).second << std::endl;

        return 0;
    }
    catch (NotInList &e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
}
