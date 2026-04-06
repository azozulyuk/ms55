/* Citation and Sources...
-----------------------------------------------------------
Final Project Milestone 5:1
Module: 5.1
Filename: main.cpp
-----------------------------------------------------------
Author: Anastasiya Zozulyuk
Student number: 139,230,247
Email: azozulyuk@myseneca.ca
Subject: BTP200NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/04/1  Completing code
V0.8    2025/04/4  Debugged
V0.9    -         Asked prof for help for XYZ
V1.0    2026/04/4  Ready for submission
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function main,ect.
-----------------------------------------------------------
*/
#include <iostream>
#include "Menu.h"
#include "Ordering.h"

using namespace std;
using namespace seneca;

int main() {

    Ordering ord("drinks.csv", "foods.csv");
    if (!ord) {
        cout << "Failed to open data files or the data files are corrupted!" << endl;
        return 1;
    }

    Menu m("Seneca Restaurant", "End Program", 0);
    m << "Order"
        << "Print Bill"
        << "Start a New Bill"
        << "List Foods"
        << "List Drinks";

    Menu o("Order Menu", "Back to main menu", 3);
    o << "Food" << "Drink";
    Menu c("You have bills that are not saved. Are you sure you want to exit?", "No", 0);
    c << "Yes";

   
    int doneNow = 0;

    while (!doneNow) {
        int newchoice = m.run();

        switch (newchoice) {

        case 1: {
            int option = -1;

            while (option != 0) {
                option = o.run();

                if (option == 1) {
                    ord.orderFood();
                }
                else if (option == 2) {
                    ord.orderDrink();
                }
            }
            break;
        }

        case 2:
            ord.printBill(cout);
            break;

        case 3:
            ord.resetBill();
            break;

        case 4:
            ord.listFoods();
            break;

        case 5:
            ord.listDrinks();
            break;

        case 0:
    if (ord.hasUnsavedBill()) {
        Menu confirm("You have bills that are not saved, are you sue you want to exit?", "No", 0);
        confirm << "Yes";

        int check = confirm.run();

        if (check == 1) {
            doneNow = 1;
        }
    }
    else {
        doneNow = 1;
    }
    break;
        }
    }

    return 0;
}
