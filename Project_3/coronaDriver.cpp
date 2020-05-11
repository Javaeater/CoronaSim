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
#include <stdlib.h>
#include <math.h>
#include <iomanip>

int main() {
    srand(time(0));                                                             // seeds the rand() function
    int uChoice;                                                                // initializes variables
    int wChoice;
    int pay;
    bool workAgain = false;
    int rChoice;
    bool gameOver = false;
    int countDown = (rand() % 10 + 1) +20;
    int g = 0;
    int s = 0;
    string username;                                                            
    Work job;
    Home game;
    Restaurant gameR;
    int counter = gameR.readRestaurant("rest.txt");                             
    cout << "choose your name" << endl;                                         // gets the player's name
    cin >> username;
    User player(username);
    while(gameOver == false) {                                                  // displays the amount of supplies and time user has left
        cout << "Hello, " << player.getName() << " you have " << countDown << " days till quarantine is over." << endl;
        cout << "Here are your supplies:" << endl;
        cout << "food: " << player.getNumFood() << endl;
        cout << "money: " << player.getNumMoney() << endl;
        cout << "gas: " << player.getNumGas() << endl;
        cout << "toilet paper: " << player.getNumToiletPaper() << endl;
        cout << "masks: " << player.getNumMasks() << endl;
        cout << "hand sanitizer: " << player.getNumHandSanitizer() << endl;
        game.displayMenu();                                                     // displays the menu options for home
        cout << "Pick an option" << endl;
        cin >> uChoice;
        switch(uChoice) {                                                       // executes different things based on the user's menu choice
            case 1:                                                             // asks user if they want to use supplies before going to the store
                player = game.useSupplies(45, 35, player);
                game.goToStore();
                cout << "choose what store you would like to visit." << endl;   // user picks store
                cin >> s;
                cout << (game.getStore(s)).getName() << endl;                   
                cout << "choose what you want to buy." << endl;                 // displays menu of items at store
                cout << "1. food" << endl;
                cout << "2. masks" << endl;
                if ((game.getStore(s)).getSanitizer() == true) {
                    cout << "3. hand sanitizer" << endl;
                }
                if ((game.getStore(s)).getPaper() == true) {
                    cout << "4. toilet paper" << endl;
                }
                cout << "5. nothing" << endl;
                cin >> s;                                                       // user picks item
                if (s == 1) {
                    cout << "how much would you like to buy?";                  // asks user how much of item they would like to buy
                    cin >> s;
                    player.addMoney(-1 * 10 * s);
                    player.addFood(s);
                }
                else if (s == 2) {
                    cout << "how much would you like to buy?";
                    cin >> s;
                    player.addMoney(-1 * 12 * s);
                    player.addMasks(s);
                }
                else if (s == 3 && (game.getStore(s)).getSanitizer() == true) {
                    cout << "how much would you like to buy?";
                    cin >> s;
                    player.addMoney(-1 * 12 * s);
                    player.addSanitizer(s);
                }
                else if (s == 4 && (game.getStore(s)).getPaper() == true) {
                    cout << "how much would you like to buy?";
                    cin >> s;
                    player.addMoney(-1 * 12 * s);
                    player.addToiletPaper(s);
                }
                else {
                    cout << "thank you for shopping at " << (game.getStore(s)).getName() << " have a nice day!" << endl;    
                }
                player.sleep();                                                 // player ends day after shopping
                break;
            case 2:
                player = game.useSupplies(30, 30, player);                      
                g = game.goToStation();
                player.addMoney(-1 * g * 5);
                player.addGas(g);
                cout << "gas: " << player.getNumGas() << endl;
                break;
                player.sleep();                 
            case 3:
                player = game.useSupplies(30, 30, player);
                for(int x = 0; x < counter; x++) {
                    cout << x << ". " << gameR.getName(x) << endl;
                }
                cout << "What resturant did you want to eat at?" << endl;
                cin >> rChoice;
                cout << "Nice choice you have been charged $" << gameR.getPrice(rChoice) << endl << endl;
                player.addMoney(-rChoice);
                player.addFood(1);
                break;
                player.sleep();
            case 4:
                player = game.useSupplies(20, 40, player);
                wChoice = game.goToWork();
                if(wChoice == 1) {
                    pay = job.goToWork();
                    player.addMoney(pay);
                    
                }
                else if(wChoice == 2) {
                    pay = job.usePto();
                    player.addMoney(pay);
                }
                else {
                    workAgain = job.getRaise();
                    if(workAgain == true) {
                        pay = job.goToWork();
                        player.addMoney(pay); 
                    }
                }
                player.sleep();
                break;
            case 5:
                player.sleep();
                break;
            case 6:
                cout << "thank you for playing!" << endl; 
                gameOver = true;
                break;
            default:
                cout << "Error enter correct input" << endl << endl;
                break;
        }
        countDown -= 1;
        if (countDown == 0) {
            cout << "Congratulations you have survived the pandemic" << endl;
            gameOver = true;
        }
        if (player.getCorona() == true) {
                    cout << "you lost because you caught corona!" << endl;
                    gameOver = true;
        }
        if (player.getNumFood() <= 0) {
                    cout << "you lost because you ran out of food!" << endl;
                    gameOver = true;
        }
        if (player.getNumGas() <= 0) {
                    cout << "you lost because you ran out of gas!" << endl;
                    gameOver = true;
        }
        if (player.getNumToiletPaper() <= 0) {
                    cout << "you lost because you ran out of toilet paper!" << endl;
                    gameOver = true;
        }
        if (player.getNumMoney() <= 0) {
                    cout << "you lost because you ran out of money!" << endl;
                    gameOver = true;
        }
    }
}