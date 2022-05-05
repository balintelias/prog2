#ifndef CONTAINER_H
#define CONTAINER_H

#include <list>
#include <utility>

//template <class T, class H>
typedef std::string KEY;
typedef std::string VALUE;

//egyelőre nemgenerikus megvalósítás, std::string kulcs és std::string értékkel
class Container
{
private:
    std::list<std::pair<KEY, VALUE>> *table;
    int size;

public:
    // konstruktor
    Container(int param);
    // másoló konstruktor
    Container(Container &other);
    // destruktor
    ~Container();
    // hozzáadni - ilyenkor kulcsot és értéket is kell adni paraméterként
    void insert(std::pair<KEY, VALUE> param);
    // módosításra az std::map insert_or_assign metódusához hasonló metódus - ilyenkor kulcsot és értéket is kell adni paraméterként
    bool insert_or_assign(std::pair<KEY, VALUE> param);
    // törölni - ilyenkor kulcsot kell adni paraméterként
    bool erase(KEY key);
    // lekérdezni h a kulcshoz van-e érték tárolva - ilyenkor a kulcsot kell adni paraméterként
    std::pair<KEY, VALUE> find(KEY key);
    //esetleg:
    //VALUE find(KEY key);
    // kiírja a tároló tartalmát (teszteléshez)
    void print();
    //operátorok:~~~~~~~~~~~~~~~
    //értékadás operátor
    bool operator=(Container &other);
    //egyenlőség vizsgálat
    bool operator==(Container &other);
    //indexelő operátor
    bool operator[](Container &other);
};

#endif