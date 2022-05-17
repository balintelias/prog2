#include "header.h"
#include "key.h"
#include "container.hpp"
#include "error.h"

#include <iostream>

int main(int argc, char const *argv[])
{
    Container<IntKey, int> container(8);
    IntKey key1 = 10;
    int value1 = 15;
    int value11 = 16;
    // container.insert_or_assign(key1, value1);
    // container.insert_or_assign(key1, value11);
    // container.print();
    Container<IntKey, std::string> cont(8);
    bool val = true;
    //val = container == cont;
    std::cout << val << std::endl;

    return 0;
}
