
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
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>

namespace seneca {

    class Menu {
        std::string m_title;              // Title of the menu
        std::string m_exitOption;         // Text for the exit option
        int m_initialValue;               // Initial value (optional)
        int m_extra;                      // Extra parameter (optional)
        std::vector<std::string> m_options; // List of menu options

    public:
        // Constructors
        Menu(const char* title = "");                          // Constructor with title only
        Menu(const char* title, const char* exitOption);       // Constructor with title and exit option
        Menu(const char* title, const char* exitOption, int initialValue); // Constructor with title, exit option, and initial value
        Menu(const char* title, const char* exitOption, int initialValue, int extra); // Constructor with title, exit option, initial value, and extra parameter

        // Disable copying and assignment
        Menu(const Menu&) = delete;
        Menu& operator=(const Menu&) = delete;

        // Overloaded insertion operator to add options
        Menu& operator<<(const char* option);

        // Display the menu
        friend std::ostream& operator<<(std::ostream& os, const Menu& menu);

        // Get user selection
        size_t select() const;
    };

}

#endif