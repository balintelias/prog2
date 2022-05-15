#ifndef KEY_H
#define KEY_H

#include <string>
#include <functional>

class StrKey
{
private:
    std::string key;
public:
    StrKey(std::string param);
    void setKey(std::string param);
    std::string getKey();
    int hash(); //implementation: std::hash
    bool operator== (StrKey const &other)
    {
        return key == other.key;
    }
};

#endif