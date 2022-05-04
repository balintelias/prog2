#ifndef KEY_H
#define KEY_H

#include <string>

#define TABLE_SIZE 128

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

int IntKey::hash()
{
    unsigned int sum = 0;
    char *ptr = (char *)&key;
    for (int i = 0; i < sizeof(int); i++)
    {
        sum += *(ptr + i);
        sum *= 31;
    }
    sum = sum % TABLE_SIZE;
    return sum;
}

#endif