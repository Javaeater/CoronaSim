// CS1300 Spring 2020
// Author: Sameek Das and Cesser Jackson
// Recitation: 201 – Abhilash Jahagirdar
// Project 3 

#include <iostream>
#include "Work.h"
#include "User.h"
#include "Restaurant.h"
#include "Home.h"
#include "Store.h"
//#include "Util.cpp"
#include <stdlib.h>
#include <math.h>
#include <iomanip>
using namespace std;
bool percentChance (int percent) {                                              // randomizer that returns true or false based on a percent chance
    int random = rand() % 100 + 1;
    bool retVal;
    if (random > percent) {
        retVal = false;
    }
    else {
        retVal = true;
    }
    // cout << random << endl;
    return retVal;
}
Home :: Home() {                                                                // constructor
    stores[0] = Store("Walmart");
    stores[1] = Store("Target");
    stores[2] = Store("Walgreens"); 
    stores[3] = Store("Whole Foods");
    stores[4] = Store("Home Depot");
}

void Home :: displayMenu() {
            cout << "1. Go to store" << endl;                                   //Display a menu with the 7 selections
            cout << "2. Go to gas station" << endl;
            cout << "3. Go out to eat" << endl; 
            cout << "4. Go to work" << endl;
            //cout << "5. Use supplies" << endl; 
            cout << "5. Sleep" << endl;
            cout << "6. Quit" << endl; 
}

int Home :: goToStation() {                                                     // displays a menu for the gas station and returns the amount of gas user will want to buy
       int amount;
       cout << "How many days of gas would you like? (each day of gas costs 5$)" << endl;
       cin >> amount;
       return amount;
}

void Home :: goToStore() {                                                      // displays a list of stores
    for (int i = 0; i < 5; i++) {   
        if ((stores[i]).isOpen() == true) {
            cout << (i + 1) << ". " << (stores[i]).getName() << endl;
        }
        else {
            cout << (i + 1) << ". " << "This store is closed now" << endl;
        }
    }
    
}
int Home :: goToResturant() {                                                   // displays a list of resturaunts
    int rIn;
    cout << "What restaurant would you like to use?" << endl;
    cin >> rIn;
    return(rIn);
}

int Home :: goToWork() {                                                        // displays the work menu
    int wIn;
    cout << "1. Work for the day" << endl;
    cout << "2. Try to get PTO" << endl;
    cout << "3. Try to get a raise" << endl;
    cin >> wIn;
    return(wIn);
}
User Home :: useSupplies(int a, int b, User player) {                           // displays a menu that allows the user to select what supplies they will use
    int choice;
    cout << "would you like to use supplies" << endl;
    cout << "1. Hand Sanitizer" << endl;
    cout << "2. Mask" << endl;
    cout << "3. Both" << endl;
    cout << "4. Neither" << endl;
    cin >> choice;
    if (choice == 1) {
        if (percentChance(a) == true) {
                player.setCorona(true);
        }
        player.addSanitizer(-1);
    }
    else if (choice == 2) {
        if (percentChance(b) == true) {
                player.setCorona(true);
        }
        player.addMasks(-1);
    }
    else if (choice == 3) {
        player.addMasks(-1);
        player.addSanitizer(-1);
    }
    else {
        if (percentChance(a+b) == true) {
                player.setCorona(true);
        }
    }
    return player;
}
Store Home::getStore(int i) {                                                   // returns a store from the store list
    return stores[i-1];
}