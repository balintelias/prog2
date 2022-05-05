#ifndef KEYS_H
#define KEYS_H

#include <string>
#include <functional>

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
    return mystdhash(key);
}

#endif