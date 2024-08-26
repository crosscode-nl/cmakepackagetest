//
// Created by Patrick Vollebregt on 26/08/2024.
//
#include "pubb.h"

#include <iostream>
#include "priva.h"

void pubb_hi() {
    std::cout << "Hello pubb, World!" << std::endl;
    priva_hi();
}
