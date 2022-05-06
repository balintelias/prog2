#include "key.h"

int StrKey::hash() //TODO: megcsinálni, hogy a kulcs lássa a tároló méretét
{
    std::hash<std::string> mystdhash;
    int index = mystdhash(key);
    index = index % TABLE_SIZE;
    return index;
}