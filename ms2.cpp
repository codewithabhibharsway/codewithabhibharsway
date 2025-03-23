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
// 1.1             03-12           fixed switch bug and insertion typo


abhishek abhishek  03-22
I have done all the coding by myself but only for a little part i had to take my brothers help for
menu.cpp in the part of handling solution and also in menu.h i took some help of my uncle.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Menu.h"
using namespace std;
using namespace seneca;

void test2();
void test1();
void appDemo();

int main() {
    size_t selection{};

    Menu ms2("Milestone 2");
    ms2 << "Run Test 1" << "Run Test 2" << "Final Milestone Application Demo";
    do {
        selection = ms2.select();
        switch (selection) {
        case 0:
            cout << "Have a good day!" << endl;
            break;
        case 1: {
            test1();
            break;
        }
        case 2:
            test2();
            break;
        case 3:
            appDemo();
            break;
        default:
            cout << "This should never happen!" << endl;
        }
    } while (selection);
    return 0;
}

void test1() {
    char option[] = "Option A";
    Menu test1("Test 1, Options Menu", "Return", 1);

    // Add 20 options to the menu
    for (size_t i = 0; i < 20; i++) { // Changed from 30 to 20
        test1 << option;
        option[7]++; // Increment the last character (A -> B -> C, etc.)
    }

    size_t selection;
    do {
        selection = test1.select(); // Get user selection
        if (selection == 0) {
            break; // Exit the loop if the user selects 0
        }
        // Handle other selections
        cout << "You selected option " << selection << endl;
    } while (true); // Loop until the user selects 0
}

void test2() {
    size_t selection{};
    Menu test2("Test 2, Selection test", "Return", 1);
    Menu subMenu(nullptr, "Back to test 2", 2, 4);
    test2 << "Option 1" << "Option 2 with Submenu" << "Option 3";
    subMenu << "Sub-option 1" << "Sub-option 2";
    do {
        selection = test2.select();
        switch (selection) {
        case 1:
            cout << "Option one selected." << endl;
            break;
        case 2:
            while (subMenu.select() != 0) {
                cout << "Staying in Submenu!" << endl;
            }
            break;
        case 3:
            cout << "Option three selected." << endl;
            break;
        case 0:
            break;
        default:
            cout << "This should never happen!" << endl;
            break;
        }
    } while (selection);
}

void appDemo() {
    size_t appSel{}, ordSel{};
    Menu appMenu("Seneca Restaurant", "End Program");
    appMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";
    Menu orderMenu("Order Menu", "Back to main menu", 1);
    orderMenu << "Food" << "Drink";
    cout << endl << "***********************************************************************" << endl;

    do {
        switch (appSel = appMenu.select()) {
        case 1:
            do {
                switch (ordSel = orderMenu.select()) {
                case 1:
                    cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                        "Start Food Ordering Process!!!\n"
                        "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
                    break;
                case 2:
                    cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                        "Start Drink Ordering Process!!!\n"
                        "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
                    break;
                }
            } while (ordSel);
            break;
        case 2:
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                "Print the Bill for customer!!!\n"
                "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
            break;
        case 3:
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                "Start a new bill!!!\n"
                "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
            break;
        case 4:
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                "List all the foods!!!\n"
                "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
            break;
        case 5:
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n"
                "List all the drinks!!!\n"
                "+++++++++++++++++++++++++++++++++++++++++++++++\n" << endl;
            break;
        }
    } while (appSel);
    cout << "End Final Milestone Demo **********************************************" << endl;
}