#ifndef KEY_H
#define KEY_H

class KeyAncestor
{
public:
    virtual int hash();
};

class IntKey : public KeyAncestor
{
private:
    int key;

public:
    IntKey(int param);
    void setKey(int param);
    int getKey();
    int hash();
};

class StrKey : public KeyAncestor
{
private:
    std::string key;

public:
    StrKey(std::string param);
    void setKey(std::string param);
    std::string getKey();
    int hash();
};

#endif