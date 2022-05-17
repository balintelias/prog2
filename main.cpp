#include "header.h"
#include "key.h"
#include "container.h"
#include "error.h"

#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    Container cont(5);
    /* std::pair<KEY, VALUE> pair1("pelda geza","06301111111");
    std::pair<KEY, VALUE> pair2("minta janos","06302222222");
    std::pair<KEY, VALUE> pair3("koder robert","06303333333");
    std::pair<KEY, VALUE> pair4("tanyer kazmer","06304444444");
    std::pair<KEY, VALUE> pair5("kossuth lajos","06305555555"); */

    std::cout<<"insert_or_assign metódus tesztje:"<<std::endl<<std::endl;

    KEY key1 = "pelda geza";
    VALUE value1 = "06301111111";
    cont.insert_or_assign(key1, value1);
    cont.print();
    std::cout << std::endl;

    KEY key2 = "minta janos";
    VALUE value2 = "06302222222";
    cont.insert_or_assign(key2, value2);
    cont.print();
    std::cout << std::endl;

    VALUE value21 = "06302222233";
    cont.insert_or_assign(key2, value21);
    cont.print();
    std::cout << std::endl;

    std::cout<<"find metódus és operator[] tesztje:"<<std::endl<<std::endl;

    KEY key3 = "koder robert";
    std::cout<<"find():"<<std::endl;
    try
    {
        std::cout << cont.find(key2).second<<std::endl;
    }
    catch (NotInList &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << cont.find(key3).second<<std::endl;
    }
    catch (NotInList &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout<<"operator[]:"<<std::endl;
    try
    {
        std::cout<<cont[key2]<<std::endl;
    }
    catch(NotInList &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout<<cont[key3]<<std::endl;
    }
    catch(NotInList &e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}