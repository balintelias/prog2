#ifndef DATAPAIR_H
#define DATAPAIR_H

#include <iostream>

template <class T, class H>
class data_pair
{
private:
    T key;
    H value;

public:
    data_pair(T key, H value) : key(key), value(value) {} // constructor
    //~data_pair(); //destructor
    KeyAncestor getKey();
    void setKey(KeyAncestor param);
    T getValue();
    void setValue(T param);

    void print()
    {
        std::cout << "key: " << key << " || value: " << value << std::endl;
    }
};

#endif