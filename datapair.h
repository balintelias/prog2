#ifndef DATAPAIR_H
#define DATAPAIR_H

#include <iostream>

//might not need this at all
//A data_pair osztály helyett lehet, hogy a C++STL pair típusa is megfelelő

//valószínűleg std::pairt fogok használni, de ezt nem törlöm, amíg nem biztos, hogy nincs rá szükség

template <class T, class H>
class data_pair
{
private:
    T key;
    H value;

public:
    data_pair(T key, H value) : key(key), value(value) {} // constructor
    data_pair(data_pair &other);
    ~data_pair(); //destructor
    T getKey();
    void setKey(T param);
    H getValue();
    void setValue(H param);

    void print()
    {
        std::cout << "key: " << key << " || value: " << value << std::endl;
    }
};

#endif