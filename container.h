#ifndef CONTAINER_H
#define CONTAINER_H

template <class T, class H>
class Container
{
private:
    list<data_pair<T, H>> *table;
    int size;

public:
    // konstruktor
    Container(int param);
    // másoló konstruktor
    Container(Container &other);
    // destruktor
    //~Container();
    // hozzáadni - ilyenkor kulcsot és értéket is kell adni paraméterként
    void insertElement(data_pair<T, H> param);
    // módosítani - ilyenkor kulcsot és értéket is kell adni paraméterként
    bool editElement(data_pair<T, H> param);
    // törölni - ilyenkor kulcsot kell adni paraméterként
    bool deleteElement(H key);
    // lekérdezni h a kulcshoz van-e érték tárolva - ilyenkor a kulcsot kell adni paraméterként
    bool isKeyInTable(H key);
    // kiírja a tároló tartalmát
    void print();
    //operátorok:~~~~~~~~~~~~~~~
    bool operator=(Container &other);
    bool operator==(Container &other);
};

#endif