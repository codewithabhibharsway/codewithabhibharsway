/***********************************************************************
// OOP244 Project, milestone 2 : tester program
//
// File	ms2.cpp
// Version 1.1
// Author Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
abhishek abhishek   03-22
I have done all the coding by myself but only for a little part i had to take my brothers help for
menu.cpp in the part of handling solution and also in menu.h i took some help of my uncle.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits>
#include "Utils.h"

namespace seneca {

    // Basic getInt function with input validation
    int Utils::getInt() {
        int input;
        while (true) {
            std::cin >> input;
            if (!std::cin.fail()) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return input;
            } else {
                std::cout << "Invalid integer: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    // getInt with range validation
    int Utils::getInt(int min, int max) {
        int input;
        while (true) {
            std::cin >> input;
            if (!std::cin.fail() && input >= min && input <= max) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return input;
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid value: [" << min << " <= value <= " << max << "], try again: ";
            }
        }
    }
}
