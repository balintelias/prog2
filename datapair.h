#ifndef DATAPAIR_H
#define DATAPAIR_H

template <class T>
class data_pair
{
private:
    KeyAncestor key;
    T value;
public:
    data_pair(); //constructor
    ~data_pair(); //destructor
    KeyAncestor getKey();
    void setKey(KeyAncestor param);
    T getValue();
    void setValue(T param);
};

#endif