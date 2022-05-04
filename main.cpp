#include "header.h"
#include "key.h"
#include "datapair.h"
#include "container.h"
#include <iostream>
#include <string>

#define TABLE_SIZE 128

const int tableSize = 128;

int main(int argc, char const *argv[])
{
    data_pair<int, int> x(10, 20);
    x.print();

    std::cout << std::endl;

    data_pair<std::string, std::string> str("pelda", "geza");
    str.print();

    std::cout << std::endl;

    data_pair<std::string, int> mixed("pelda", 454351354);
    mixed.print();

    // TODO: figure out how to pass template class to template class

    // TODO: implement key classes

    //KeyAncestor *xkey = new IntKey(10);
    IntKey xkey(10);
    std::cout<<xkey.hash()<<std::endl;

    return 0;
}
