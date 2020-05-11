// CS1300 Spring 2020
// Author: Sameek Das and Cesser Jackson
// Recitation: 201 – Abhilash Jahagirdar
// Project 3 

#include <iostream>
#ifndef User_h
#define User_h

using namespace std;

class User {                                                                    // defines the User class    
    public:
    User ();
    User (string n);
    int getNumFood();
    int getNumMasks();
    int getNumGas();
    int getNumToiletPaper();
    int getNumHandSanitizer();
    //int getNumActivities();
    double getNumMoney();
    bool sleep();
    string getName();
    bool getCorona();
    int addFood(int n);
    int addMasks(int n);
    int addGas(int n);
    int addSanitizer(int n);
    int addToiletPaper(int n);
    //int addActivity (int n);
    //void resetActivities();
    double addMoney (double n);
    void setCorona(bool a);
    private:
    string name;
    double money;
    bool hasCorona;
    int masks;
    int food;
    // bool laptop;
    // bool phone;
    int gas;
    int handSanitizer;
    //int activities;
    int toiletPaper;
};
#endif
