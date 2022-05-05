#ifndef KEY_H
#define KEY_H

#include <string>

#define TABLE_SIZE 128

//aktuális megvalósítás a keys.h fileban, ezt még nem törlöm

class KeyAncestor
{
public:
    virtual int hash() {}
};

class IntKey : public KeyAncestor
{
private:
    int key;

public:
    IntKey(int param) : key(param) {}
    void setKey(int param);
    int getKey();
    int hash();
};

class StrKey : public KeyAncestor
{
private:
    std::string key;

public:
    StrKey(std::string param) : key(param) {}
    void setKey(std::string param);
    std::string getKey();
    int hash();
};

#endif