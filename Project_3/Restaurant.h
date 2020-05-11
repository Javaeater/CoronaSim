// CS1300 Spring 2020
// Author: Sameek Das and Cesser Jackson
// Recitation: 201 – Abhilash Jahagirdar
// Project 3 

#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
class Restaurant {
    //private members
    private:
        string storedR [50];
        int storedP [50];
        int counter;
    //public members
    public:
        //default constructor
        Restaurant();
        //read resturants 
        int readRestaurant (string fName);
        //check if the user is infected
        bool isInfected ();
        //get the resurant name
        string getName (int i);
        //get the restaurant price
        float getPrice(int j);
};
#endif

