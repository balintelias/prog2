#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <vector>

// hash tábla indexelésére használunk egy f függvényt, amely előállítja a kulcsból és a méretből az indexet
// index = f(kulcs, méret)
int hash(void *p, int key_size, int table_size);

class KeyAncestor
{
public:
    virtual int hash();
};

class IntKey : public KeyAncestor
{
private:
    int key;

public:
    void setKey(int param);
    int getKey();
    int hash();
};

class StrKey : public KeyAncestor
{
private:
    std::string key;

public:
    StrKey(std::string param);
    void setKey(std::string param);
    std::string getKey();
    int hash();
};

class MyArray
{
private:
    std::vector<std::string*> values;
    int size;
};

#endif