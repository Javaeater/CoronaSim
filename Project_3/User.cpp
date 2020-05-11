// CS1300 Spring 2020
// Author: Sameek Das and Cesser Jackson
// Recitation: 201 – Abhilash Jahagirdar
// Project 3 

#include <iostream>
#include "User.h"
using namespace std;

User::User () {                                                                 // default constructor
    name = "";                                                                  // sets name to empty string, and gives the user their starting supplies
    money = 100;
    hasCorona = false;
    masks = 2;
    food = 3;
    handSanitizer = 2;
    gas = 5;
    toiletPaper = 5;
}
User::User (string n) {                                                         // overloaded constructor
    name = n;                                                                   // allows user to select their name
    money = 100;
    hasCorona = false;
    masks = 2;
    food = 3;
    handSanitizer = 2;
    gas = 5;
    toiletPaper = 5;
   
}
int User::getNumFood() {                                                        //getters and setters
    return food;
}
string User::getName() {
    return name;
}
int User::getNumMasks() {
    return masks;
}
int User::getNumGas() {
    return gas;
}
int User::getNumToiletPaper() {
    return toiletPaper;
}
int User::getNumHandSanitizer() {
    return handSanitizer;
}
double User::getNumMoney() {
    return money;
}
bool User::getCorona() {
    return hasCorona;
}
int User::addFood(int n) {
    food += n;
    return food;
}
int User::addMasks(int n) {
    masks += n;
    return masks;
}
int User::addGas(int n) {
    gas += n;
    return gas;
}
int User::addSanitizer(int n) {
    handSanitizer += n;
    return handSanitizer;
}
int User::addToiletPaper(int n) {
    toiletPaper += n;
    return toiletPaper;
}
double User::addMoney (double n) {
    money += n;
    return money;
}
void User::setCorona (bool a) {
    hasCorona = a;
}
/** 
 * the sleep function will:
 * advance the day by one
 * decrease the amount of toiletpaper and food to account for what is used in the day
 * checks to see if the user has corona
 * returns true if they have corona
 * returns false if they do not
 * */
 bool User::sleep() {                                                           // increments the supplies used for a
     bool retVal = hasCorona;
     food -= 1;
     gas -= 1;
     toiletPaper -= 1;
     return retVal;
 }
 