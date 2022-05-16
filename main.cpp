#include "header.h"
#include "key.h"
#include "container.h"

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

    KEY key1 = "pelda geza";
    VALUE value1 = "06301111111";
    cont.insert(key1, value1);
    cont.print();

    /* cont.insert(pair1);
    cont.insert(pair1);
    cont.insert(pair1);
    cont.insert(pair1); */

    /*StrKey key1("pelda geza");
    std::string value1("06301111111");
    cont.insert(key1, value1); //???????
    std::pair<KEY, VALUE> xd = cont.find(key1);
    std::cout << (xd.first).getKey() << " " << xd.second << std::endl;
    std::cout << cont[key1];*/
    return 0;
}