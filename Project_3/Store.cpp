// CS1300 Spring 2020
// Author: Sameek Das and Cesser Jackson
// Recitation: 201 – Abhilash Jahagirdar
// Project 3 

#include <iostream>
#include <math.h>    
#include "Store.h"
using namespace std;

Store::Store(){                                                                 // default constructor
    name = "";                                                                  // name is an empty string and the store will not have hand sanitizer or toilet paper
    timer = 0;
    open = true;
    hasSanitizer = false;
    hasPaper = false;
}
Store::Store(string n){                                                         // overloaded constructor
    name = n;                                                                   // allows name of store to be selected
    timer = 0;
    open = true;
    hasSanitizer = false;
    hasPaper = false;
    int x = (rand() % 100 + 1);                                                 // there is a 50/50 shot that the store will have sanitizer or toilet paper
    int y = (rand() % 100 + 1);
    if (x > 50) {       
        hasSanitizer = true;
    }
    if (y > 50) {                                                           
        hasPaper = true;
    }
}

string Store::getName() {
    return name;
}
void Store::raiseTimer() {                                                      // increments the timer by 1
    timer++;
    if (timer >= 5) {                                                           // if the timer exceeds 5 days the store closes
        open = false;
    }
}
void Store::resetTimer() {                                                      // resets the timer back to 0
    timer = 0;
}
int Store::getTimer() {
    return timer;
}
bool Store::getSanitizer() {
    return hasSanitizer;
}
bool Store::getPaper() {
    return hasPaper;
}
bool Store::isOpen() {
    return open;
}
