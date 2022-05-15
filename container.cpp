#include "container.h"

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
    index = index % table_size;
    // push back in list
    std::pair<KEY, VALUE> node(key, value);
    table[index].push_back(node);
}

bool Container::insert_or_assign(KEY &key, VALUE &value)
{
    // hash key
    int index = key.hash();
    index = index % table_size;
    // TODO: finish this
    std::pair<int, std::pair<KEY, VALUE>> ret = this->find(key);
    if (ret.first == 0)
        return false;

    ret.second.second = value;
    return true;
}

void Container::erase(KEY &key)
{
    // hash key
    int index = key.hash();
    index = index % table_size;

    /*// iterator
    std::list<std::pair<KEY, VALUE>>::iterator it;
    it = std::find(table[index].begin(), table[index].end(), );*/

    table[index].remove_if([key](std::pair<KEY, VALUE> x)
                           { return x.first == key; });
    //([](int n){ return n > 10; });
}

std::pair<int, std::pair<KEY, VALUE>> Container::find(KEY &key) // find() works differently in std::map
{
    int index = key.hash();
    index = index % table_size;
    for (auto j : table[index])
    {
        if (j.first == key)
        {
            std::pair<int, std::pair<KEY, VALUE>> ret(1, j);
            return ret;
        }
    }
    // no instance of key in container:
    VALUE retvalue();
    // std::pair<KEY, VALUE> retpair(key, retvalue);
    std::pair<KEY, VALUE> pair5(key, "06305555555");
    std::pair<int, std::pair<KEY, VALUE>> ret(0, pair5);
    return ret;
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
    return find(key).second.second;
    // TODO: exception, if no instance of key in container
}