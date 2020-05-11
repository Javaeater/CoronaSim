// CS1300 Spring 2020
// Author: Sameek Das and Cesser Jackson
// Recitation: 201 – Abhilash Jahagirdar
// Project 3 

#include <iostream>
#ifndef Store_h
#define Store_h

using namespace std;

class Store {                                                                   //defines the store class
    public:
    Store();
    Store(string n);
    string getName();
    void raiseTimer();
    void resetTimer();
    int getTimer();
    bool getSanitizer();
    bool getPaper();
    bool isOpen();
    private:
    string name;
    int timer;
    bool open;
    bool hasPaper;
    bool hasSanitizer;
    
};
#endif