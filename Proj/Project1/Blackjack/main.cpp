
/* 
 * File:   main.cpp
 * Author: Eddy
 * Project 1: Blackjack
 * Created on October 19, 2019, 2:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

enum Facecard{
    King,
    Queen,
    Jack,
    Ace
};

int bet();
int deal();
bool checkScore();
void play();
void dealerPlay();
int shuffle();
int dealToPlayer();
int clearPlayerHand(int &);

int main(int argc, char** argv) {
    // Set Variables
    int NUMHND = 1; //Number of hands == 2 
    int HNDSZ = 10; // number of cards in a hand 
    int STSIZE = 12; //Number of cards in a suit
    int NUMST = 3;  // Number of suits
    bool isGmOvr = false; // Game over variable
    bool plyrWin = false;
    int plyrMon = 200; // player money
    int dlrPot = 1000; // money in the dealers pot
    int plyrBet;
  int crdDeck[STSIZE][NUMST]={
        { Ace, 2,3,4,5,6,7,8,9,10, Jack, Queen, King},
        { Ace, 2,3,4,5,6,7,8,9,10, Jack, Queen, King},
        { Ace, 2,3,4,5,6,7,8,9,10, Jack, Queen, King},
        { Ace, 2,3,4,5,6,7,8,9,10, Jack, Queen, King}
    };   
    int plyrHnd[HNDSZ][NUMHND]={
        {0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0}
    };
    
    //Start Game
    while (isGmOvr == false){
    // Get player bet
        plyrBet = 0;
        while (plyrBet <= 0 || plyrBet > plyrMon ){
        cout << "You currently have $" << plyrMon << endl;
        cout << "Place a bet that is greater than $0 and less than $" << plyrMon << ":"<< endl;
        
            cin >> plyrBet;
    };
        
        
    // Deal Cards
    
    
    //display cards
    
    // check for natural 21
    
    // let player hit or stand
    
    // Dealer plays
    
    // Check score
    
    // Settle Bets
        if (plyrWin == true){
            dlrPot -= (plyrBet * 2);
            plyrMon += (plyrBet * 2);
        }
        if (plyrWin == false){
            plyrMon -= plyrBet;
        }
    // Check if game us over
        if (plyrMon <= 0){
            isGmOvr = true;
            cout << "Gameover! You've lost all your money!" << endl;
            
        }
       
    }
    
    return 0;
}

 int clearPlayerHand(int &plHnd){
  //   plHnd = {
    //    {0,0,0,0,0,0,0,0,0,0,0},
    //    {0,0,0,0,0,0,0,0,0,0,0}
    //};
 }