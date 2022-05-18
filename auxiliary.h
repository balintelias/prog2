#ifndef AUXILIARY_H
#define AUXILIARY_H

#include "key.h"
#include "container.hpp"
#include "error.h"

#include <iostream>
#include <string>

void init();

void menu();

char getUserInput();

StrKey getKeyFromUser();

std::string getValueFromUser();

#endif