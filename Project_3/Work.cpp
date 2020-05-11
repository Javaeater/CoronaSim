// CS1300 Spring 2020
// Author: Sameek Das and Cesser Jackson
// Recitation: 201 – Abhilash Jahagirdar
// Project 3 

#include "Work.h"
#include "User.h"
//#include "Util.cpp"
#include <math.h>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
bool randomizer (int percent) {                                                 // randomizer that returns true or false based on a percent chance
    int random = rand() % 100 + 1;
    bool retVal;
    if (random > percent) {
        retVal = false;
    }
    else {
        retVal = true;
    }
    cout << random << endl;
    return retVal;
}
Work :: Work() {                                                                
    jobTitle = "";
    //set salary to a random number
    salary = rand() % 100 +1;
    pto = false;
    rz = false;
}

Work :: Work(string nm) {
    jobTitle = nm;
    //set salary to a random number
    salary = rand() % 100 +1;
    pto = false;
    rz = false;
    
}

int Work :: goToWork () {
    //display how much the user made 
    cout << "You have earned $" << salary << " working today.";
    //return the salary 
    return(salary);
}

int Work :: usePto () {
    //1.Check of the user has used pto
    if(pto == true) {
        cout << "You have already used PTO before you can not use it again." << endl;
        return(0);
    }
    else {
        if(randomizer(60) == true) {
            cout << "Your pto was accepted you were paid " << 3*salary << "." << endl;
            pto = true;
            return(3* salary);
        }
        else {
            cout << "Your PTO was not accepted." << endl;
            pto = true;
            return(0);
        }
    }
     //return to the main work menu
}

bool Work :: getRaise () {
    string an;
    //1.Check if they have gotten a raise before
    if(rz == true) {
        cout << "You have already gotten a raise before you can not get one again." << endl;
    }
    else {
        if(randomizer(20) == true) {
            cout << "You recieved a 15 doller raise." << endl;
            salary += 15;
            rz= true;
        }
        else {
            cout << "You did not recieve a raise." << endl;
            rz = true;
        }
    }
    //see if they would like to go to work or home
    cout << "Would you like to go to work? (Answer Y or N)" << endl;
    cin >> an;
    if(an == "Y") {
        return(true);
    }
    else {
        return(false);
    }
}

void Work :: viewSalary() {
    cout << salary << endl;
}
