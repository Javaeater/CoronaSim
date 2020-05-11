// CS1300 Spring 2020
// Author: Sameek Das and Cesser Jackson
// Recitation: 201 – Abhilash Jahagirdar
// Project 3 

#include <iostream>
#include "User.h"
#include "Work.h"
#include "Store.h"
#ifndef Home_h
#define Home_h

using namespace std;

class Home {                                                                    // defines the Store class    
    public:
    Home ();
    void displayMenu();
    void goToStore();
    int goToResturant();
    int goToWork();
    int goToStation();
    void sleep();
    User useSupplies(int a, int b, User player);
    Store getStore(int i);
    //bool randomizer(int n);
    private:
    Work Job;
    Store stores[5];
};
#endif          