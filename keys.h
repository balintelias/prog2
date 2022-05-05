#ifndef KEYS_H
#define KEYS_H

#include <string>
#include <functional>

#define TABLE_SIZE 128

class StrKey
{
private:
    std::string key;
public:
    StrKey(int param);
    ~StrKey();
    void setKey(std::string param);
    std::string getKey();
    int hash(); //megvalósítás: std::hash
};

//szemléltető implementáció
int StrKey::hash()
{
    std::hash<std::string> mystdhash;
    int index = mystdhash(key);
    index = index % TABLE_SIZE;
    return index;
}

#endif