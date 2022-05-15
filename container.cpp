#include "container.h"

#include <list>
#include <utility>

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
    // TODO: ezt befejezni
    return true;
}

bool Container::erase(KEY &key)
{
    // hash key
    int index = key.hash();
    index = index % table_size;
    // TODO: find in list:
    return true;
}

std::pair<KEY, VALUE> Container::find(KEY &key) // TODO: find() máshogy működik az std::map-ben
{
    int index = key.hash();
    index = index % table_size;
    for (auto j : table[index])
    {
        if (j.first == key)
        {
            return j;
        }
    }
    // TODO: ha nincs benne, akkor valami más, preferably iterator
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

VALUE Container::operator[](KEY key)
{
    return find(key).second;
}