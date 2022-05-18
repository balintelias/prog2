#include "key.h"

#include <string>

StrKey::StrKey()
{
}

StrKey::StrKey(std::string param)
{
    key = param;
}

StrKey::StrKey(const char *param)
{
    key = param;
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
    std::hash<std::string> mystdhash;
    return abs(mystdhash(key));
}

IntKey::IntKey(int param)
{
    key = param;
}

void IntKey::setKey(int param)
{
    key = param;
}

int IntKey::getKey()
{
    return key;
}

int IntKey::hash()
{
    std::hash<int> mystdhash;
    return abs(mystdhash(key));
}