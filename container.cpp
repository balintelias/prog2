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
    // TODO: copy (std::vector miatt kérdéses)
}

Container::~Container()
{
    // TODO: finish
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
    return true;
}

bool Container::erase(KEY &key)
{
    return true;
}

std::pair<KEY, VALUE> Container::find(KEY &key) //TODO: find() máshogy működik az std::map-ben
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
}