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

// egyelőre nemgenerikus megvalósítás, StrKey kulcs és std::string értékkel
class Container
{
private:
    std::list<std::pair<KEY, VALUE>> *table; 
    //std::vector<std::list<std::pair<KEY, VALUE>>> table; std::vector
    int table_size;

public:
    // konstruktor
    Container(int param = 128);
    // másoló konstruktor
    Container(Container &other);
    // destruktor
    ~Container();
    // hozzáadni - ilyenkor kulcsot és értéket is kell adni paraméterként
    void insert(KEY &key, VALUE &value);
    // módosításra az std::map insert_or_assign metódusához hasonló metódus
    // ilyenkor kulcsot és értéket is kell adni paraméterként
    bool insert_or_assign(KEY &key, VALUE &value);
    // törölni - ilyenkor kulcsot kell adni paraméterként
    bool erase(KEY &key);
    // lekérdezni h a kulcshoz van-e érték tárolva
    // ilyenkor a kulcsot kell adni paraméterként
    std::pair<KEY, VALUE> find(KEY &key);
    // esetleg:
    // VALUE find(KEY key);
    // vagy bool visszatérési érték
    // kiírja a tároló tartalmát (teszteléshez)
    void print();
    // operátorok:~~~~~~~~~~~~~~~
    //értékadás operátor
    void operator=(Container &other);
    // egyenlőség vizsgálat
    bool operator==(Container &other);
    // indexelő operátor
    VALUE operator[](KEY key);
};

#endif