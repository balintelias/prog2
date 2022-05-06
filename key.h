#ifndef KEY_H
#define KEY_H

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

#endif