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
#include "Menu.h"
#include <iostream>
#include <limits>

namespace seneca {

    // Constructor with title only
    Menu::Menu(const char* title) : m_title(title ? title : ""), m_exitOption("Exit"), m_initialValue(0), m_extra(0) {}

    // Constructor with title and exit option
    Menu::Menu(const char* title, const char* exitOption)
        : m_title(title ? title : ""), m_exitOption(exitOption ? exitOption : "Exit"), m_initialValue(0), m_extra(0) {}

    // Constructor with title, exit option, and initial value
    Menu::Menu(const char* title, const char* exitOption, int initialValue)
        : m_title(title ? title : ""), m_exitOption(exitOption ? exitOption : "Exit"), m_initialValue(initialValue), m_extra(0) {}

    // Constructor with title, exit option, initial value, and extra parameter
    Menu::Menu(const char* title, const char* exitOption, int initialValue, int extra)
        : m_title(title ? title : ""), m_exitOption(exitOption ? exitOption : "Exit"), m_initialValue(initialValue), m_extra(extra) {}

    // Overloaded insertion operator to add options
    Menu& Menu::operator<<(const char* option) {
        if (option) {
            m_options.push_back(option);
        }
        return *this;
    }

    // Display the menu
    std::ostream& operator<<(std::ostream& os, const Menu& menu) {
        if (!menu.m_title.empty()) {
            os << menu.m_title << std::endl;
        }
        for (size_t i = 0; i < menu.m_options.size(); i++) {
            os << (i + 1) << "- " << menu.m_options[i] << std::endl;
        }
        os << "0- " << menu.m_exitOption << std::endl;
        os << "> ";
        return os;
    }

    // Get user selection
    size_t Menu::select() const {
        size_t selection = 0;
        bool valid = false;

        while (!valid) {
            std::cout << *this; // Display the menu

            // Check if input is valid
            if (!(std::cin >> selection)) {
                std::cin.clear(); // Clear error state
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "Invalid input. Please enter a number between 0 and " << m_options.size() << "." << std::endl;
            }
            else if (selection > m_options.size()) {
                std::cout << "Invalid selection. Please enter a number between 0 and " << m_options.size() << "." << std::endl;
            }
            else {
                valid = true; // Valid input
            }
        }

        return selection;
    }

}