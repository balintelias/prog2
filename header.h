#ifndef HEADER_H
#define HEADER_H


// hash tábla indexelésére használunk egy f függvényt, amely előállítja a kulcsból és a méretből az indexet
// index = f(kulcs, méret)
int hash(void *p, int key_size, int table_size);

#endif