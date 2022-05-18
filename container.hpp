#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include "key.h"
#include "error.h"

#include <iostream>
#include <list>
#include <vector>
#include <utility>
#include <string>
#include <bits/stdc++.h>

// template <class KEY, class VALUE>
// typedef StrKey KEY;
// typedef std::string VALUE;

// ungeneric implementation, StrKey key and std::string value
template <class KEY, class VALUE>
class Container
{
private:
    std::list<std::pair<KEY, VALUE>> *table; 
    int table_size;
    // find auxiliary function
    std::pair<KEY, VALUE> find_helper(KEY &key);
    // insert auxiliary function - parameter: KEY and VALUE
    void insert(KEY &key, VALUE &value);
    //erase auxiliary function?

public:
    // constructor
    Container(int param = 128);
    // copy constructor
    Container(Container &other);
    // destruktor
    ~Container();
    
    // to insert/edit - method similar to std::map insert_or_assign method
    // parameter: KEY and VALUE
    bool insert_or_assign(KEY &key, VALUE &value);
    // delete - parameter: KEY
    void erase(KEY &key);
    // ask if KEY has a VALUE associated with it
    // parameter: KEY
    std::pair<KEY, VALUE> find(KEY &key);
    // print the contents of container (for testing)
    void print();
    // operators:~~~~~~~~~~~~~~~
    //assigning operator
    void operator=(Container &other);
    // equality test
    bool operator==(Container &other);
    // indexing operator
    VALUE operator[](KEY &key);
};

template <class KEY, class VALUE>
Container<KEY, VALUE>::Container(int param)
{
    this->table_size = param;
    table = new std::list<std::pair<KEY, VALUE>>[table_size];
}

template <class KEY, class VALUE>
Container<KEY, VALUE>::Container(Container &other)
{
    this->table_size = other.table_size;
    table = new std::list<std::pair<KEY, VALUE>>[table_size];
    for (int i = 0; i < table_size; i++)
    {
        table[i] = other.table[i];
    }
}

template <class KEY, class VALUE>
Container<KEY, VALUE>::~Container()
{
    delete[] table;
}

template <class KEY, class VALUE>
void Container<KEY, VALUE>::insert(KEY &key, VALUE &value)
{
    // hash key
    int index = key.hash();
    index = abs(index % table_size);
    // push back in list
    std::pair<KEY, VALUE> node(key, value);
    table[index].push_back(node);
}

template <class KEY, class VALUE>
bool Container<KEY, VALUE>::insert_or_assign(KEY &key, VALUE &value)
{
    // hash key
    int index = key.hash();
    index = abs(index % table_size);

    for (auto j : table[index])
    {
        if (j.first == key)
        {
            erase(key);
            insert(key, value);
            return true;
        }
    }
    insert(key, value);
    return false;
}

template <class KEY, class VALUE>
void Container<KEY, VALUE>::erase(KEY &key)
{
    // hash key
    int index = key.hash();
    index = abs(index % table_size);

    table[index].remove_if([key](std::pair<KEY, VALUE> x)
                           { return x.first == key; });
    //([](int n){ return n > 10; });
}

template <class KEY, class VALUE>
std::pair<KEY, VALUE> Container<KEY, VALUE>::find_helper(KEY &key)
{
    int index = key.hash();
    index = abs(index % table_size);
    for (auto j : table[index])
    {
        if (j.first == key)
        {
            return j;
        }
    }
    NotInList ex;
    throw ex;
}

template <class KEY, class VALUE>
std::pair<KEY, VALUE> Container<KEY, VALUE>::find(KEY &key) // find() works differently in std::map
{

    std::pair<KEY, VALUE> ret = find_helper(key);
    return ret;
}

template <class KEY, class VALUE>
void Container<KEY, VALUE>::print()
{
    for (int i = 0; i < table_size; i++)
    {
        for (auto j : table[i])
        {
            std::cout << j.first.getKey() << j.second << std::endl;
        }
    }
}

template <class KEY, class VALUE>
void Container<KEY, VALUE>::operator=(Container<KEY, VALUE> &other)
{
    this->table_size = other.table_size;
    //
    for (int i = 0; i < table_size; i++)
    {
        table[i] = other.table[i];
    }
}

template <class KEY, class VALUE>
bool Container<KEY, VALUE>::operator==(Container<KEY, VALUE> &other)
{
    if (this->table_size != other.table_size)
        return false;
    for (int i = 0; i < table_size; i++)
    {
        if (table[i] != other.table[i])
            return false;
    }
    return true;
}

/* template <class KEY, class VALUE>
bool Container<KEY, VALUE>::operator==(Container<KEY, VALUE> &other)
{
    if (this->table_size != other.table_size)
        return false;
    for (int i = 0; i < table_size; i++)
    {
        if (table[i] != other.table[i])
            return false;
    }
    return true;
} */

template <class KEY, class VALUE>
VALUE Container<KEY, VALUE>::operator[](KEY &key)
{

    return find(key).second;
}

#endif