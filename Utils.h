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
#ifndef UTILS_H
#define UTILS_H

namespace seneca {
    class Utils {
    public:
        static int getInt();
        static int getInt(int min, int max);
    };
}

#endif
