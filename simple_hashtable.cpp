/*

a hash-tábla egyszerű terve, std::string kulcsokat és std::string értékeket tárol

*/
#include <iostream>
#include <list>

#define TABLE_SIZE 8

using namespace std;

int simple_hash(string key, int key_size, int table_size)
{
    unsigned int sum = 0;
    char *ptr = (char *)&key;
    for (int i = 0; i < key_size; i++)
    {
        sum += *(ptr + i);
    }
    sum = sum % table_size;
    return sum;
}

struct data_pair
{
    string key, value;
};

class Container
{
private:
    list<data_pair> *table;
    int table_size;

public:
    Container(int table_size);
    // hozzáadni - ilyenkor kulcsot és értéket is kell adni paraméterként
    void insertElement(data_pair param);
    // módosítani - ilyenkor kulcsot és értéket is kell adni paraméterként
    bool editElement(data_pair param);
    // törölni - ilyenkor kulcsot kell adni paraméterként
    bool deleteElement(string key);
    // lekérdezni h a kulcshoz van-e érték tárolva - ilyenkor a kulcsot kell adni paraméterként
    bool isKeyInTable(string key);
    // kiírja a tároló tartalmát
    void print();
};

Container::Container(int table_size_param)
{
    this->table_size = table_size_param;
    table = new list<data_pair>[table_size];
}

void Container::insertElement(data_pair param)
{

    int index = simple_hash(param.key, sizeof(param.key), this->table_size);
    table[index].push_back(param);
}

bool Container::editElement(data_pair param)
{
    // hash és kulcs alapján kikeresi az elemet, és átírja a listában
    return true;
}

bool Container::deleteElement(string key)
{
    // hash és kulcs alapján kikeresi az elemet, és törli a listából
    return true;
}

bool Container::isKeyInTable(string key)
{
    // int index = simple_hash(&key, sizeof(key), table_size);
    // return contains(table[index], key)
    //...
    return true;
}

void Container::print()
{
    for (int i = 0; i < table_size; i++)
    {
        cout << i;
        // traversing at the recent/ current index
        for (auto j : table[i])
            cout << " ==> " << j.key << "/" << j.value;
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    Container ht(TABLE_SIZE);
    data_pair input[5];
    //nevekhez telefonszámokat rendelünk
    input[0].key = "pelda geza";
    input[0].value = "06301111111";
    input[1].key = "minta janos";
    input[1].value = "06302222222";
    input[2].key = "koder robert";
    input[2].value = "06303333333";
    input[3].key = "tanyer kazmer";
    input[3].value = "06304444444";
    input[4].key = "kossuth lajos";
    input[4].value = "06305555555";
    for (int i = 0; i < 5; i++)
    {
        ht.insertElement(input[i]);
    }
    ht.print();

    return 0;
}
