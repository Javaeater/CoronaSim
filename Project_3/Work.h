// CS1300 Spring 2020
// Author: Sameek Das and Cesser Jackson
// Recitation: 201 – Abhilash Jahagirdar
// Project 3 

#ifndef WORK_H
#define WORK_H
#include <iostream>
using namespace std;
class Work {                                                                    
    //private
    private:
        int salary;
        string jobTitle;
        bool pto;
        bool rz;
    //public
    public:
        //default const
        Work();
        //Param Const
        Work(string nm);
        //the user works
        int goToWork();
        //see if they want pto
        int usePto();
        //check if they want a raise
        bool getRaise();
        //view salary
        void viewSalary();
        //returns true or false based on percent chance
        //bool randomizer(int n);
};
#endif