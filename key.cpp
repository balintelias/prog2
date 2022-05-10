#include "key.h"

#include <string>

StrKey::StrKey(std::string param)
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
    return mystdhash(key);
}