#include "key.h"

#include <string>

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

void IntKey::setKey(int param)
{
    key = param;
}

int IntKey::getKey()
{
    return key;
}

void StrKey::setKey(std::string param)
{
    key = param;
}

std::string StrKey::getKey()
{
    return key;
}

int StrKey::hash()
{
    unsigned int sum = 0;
    char *ptr = (char *)&key;
    for (int i = 0; i < sizeof(key); i++)
    {
        sum += *(ptr + i);
        sum *= 31;
    }
    sum = sum % TABLE_SIZE;
    return sum;
}