#ifndef KEY_H
#define KEY_H

#include <string>
#include <functional>

class StrKey
{
private:
    std::string key;

public:
    StrKey();
    StrKey(std::string param);
    StrKey(const char *param);
    void setKey(std::string param);
    std::string getKey();
    int hash(); // implementation: std::hash
    bool operator==(StrKey const &other) const { return key == other.key; }
};

class IntKey
{
private:
    int key;

public:
    IntKey(int param);
    void setKey(int param);
    int getKey();
    int hash(); // implementation: std::hash
    bool operator==(IntKey const &other) const { return key == other.key; }
};

#endif