#include "header.h"

int hash(void *p, int key_size, int table_size)
{
    int sum = 0;
    char* ptr = (char*)p;
    for (int i = 0; i < key_size; i++)
    {
        sum += *(ptr+i);
    }
    sum = sum % table_size;
    return sum;
}

