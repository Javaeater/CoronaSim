// CS1300 Spring 2020
// Author: Sameek Das and Cesser Jackson
// Recitation: 201 – Abhilash Jahagirdar
// Project 3 
#include "Restaurant.h"
#include <iostream>
#include<fstream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
    Restaurant :: Restaurant(){
       //1. Set the storedR array to empty strings and value to 0
       for(int i = 0; i < 50; i++) {
         storedR[i] = "";
         storedP[i] = 0;
       }
    }
    
    int Restaurant :: readRestaurant(string fName) {
      string line;
      int count = 0;
      //1. open the file
      ifstream file;
      file.open(fName);
      //2. Read the names of each restaurant from the file and store them in storedR
      if (file.is_open()) {
        while(getline(file, line)) {
          storedR[count] = line;
          storedP[count] = rand() % 100 +1;
          count++;
        }
        return(count);
      }
      
      else {
        cout << "file could not be opened" << endl;
        return(0);
      }
    }
    
    string Restaurant :: getName(int i) {
      return storedR[i];
    }
    
    float Restaurant :: getPrice(int j) {
      return storedP[j];
    }
    