#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include <string>

class NotInList : public std::exception
{
public:
    std::string what() { return "No instance of key in container."; }
};

#endif