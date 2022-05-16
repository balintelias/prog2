#ifndef CONTAINER_H
#define CONTAINER_H

#include "key.h"
#include <list>
#include <vector>
#include <utility>
#include <string>

// template <class KEY, class VALUE>
typedef StrKey KEY;
typedef std::string VALUE;

// ungeneric implementation, StrKey key and std::string value
class Container
{
private:
    std::list<std::pair<KEY, VALUE>> *table; 
    //std::vector<std::list<std::pair<KEY, VALUE>>> table; std::vector
    int table_size;
    std::pair<KEY, VALUE> find_helper(KEY &key);
public:
    // constructor
    Container(int param = 128);
    // copy constructor
    Container(Container &other);
    // destruktor
    ~Container();
    // insert - parameter: KEY and VALUE
    void insert(KEY &key, VALUE &value);
    // to edit - method similar to std::map insert_or_assign method
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

#endif