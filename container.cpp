#include "container.h"
#include "error.h"
#include "key.h"

#include <list>
#include <utility>
#include <bits/stdc++.h>

Container::Container(int param)
{
    this->table_size = param;
    table = new std::list<std::pair<KEY, VALUE>>[table_size];
}

Container::Container(Container &other)
{
    this->table_size = other.table_size;
    table = new std::list<std::pair<KEY, VALUE>>[table_size];
    for (int i = 0; i < table_size; i++)
    {
        table[i] = other.table[i];
    }
}

Container::~Container()
{
    delete[] table;
}

void Container::insert(KEY &key, VALUE &value)
{
    // hash key
    int index = key.hash();
    index = abs(index % table_size);
    // push back in list
    std::pair<KEY, VALUE> node(key, value);
    table[index].push_back(node);
}

bool Container::insert_or_assign(KEY &key, VALUE &value)
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

void Container::erase(KEY &key) // TODO: erre van std::list metódus, de iterátorokkal
{
    // hash key
    int index = key.hash();
    index = abs(index % table_size);

    table[index].remove_if([key](std::pair<KEY, VALUE> x)
                           { return x.first == key; });
    //([](int n){ return n > 10; });
}

std::pair<KEY, VALUE> Container::find_helper(KEY &key)
{
    int index = key.hash();
    index = abs(index % table_size);
    for (auto j : table[index])
    {
        if (j.first == key)
        {
            return j; // TODO: return modifiable value
        }
    }
    NotInList ex;
    throw ex;
}

std::pair<KEY, VALUE> Container::find(KEY &key) // find() works differently in std::map
{
    try
    {
        std::pair<KEY, VALUE> ret = find_helper(key);
        return ret;
    }
    catch (NotInList e)
    {
        std::cerr << e.what() << '\n';
    }
    // TODO: control reaches end of non-void function [-Wreturn-type] gcc
}

void Container::print()
{
    for (int i = 0; i < table_size; i++)
    {
        for (auto j : table[i])
        {
            std::cout << j.first.getKey() << j.second << std::endl;
        }
    }
}

void Container::operator=(Container &other)
{
    this->table_size = other.table_size;
    //
    for (int i = 0; i < table_size; i++)
    {
        table[i] = other.table[i];
    }
}

bool Container::operator==(Container &other)
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

VALUE Container::operator[](KEY &key)
{
    try
    {
        return find(key).second;
    }
    catch (NotInList &e)
    {
        std::cerr << e.what() << '\n';
    }
    // TODO: control reaches end of non-void function [-Wreturn-type] gcc
}