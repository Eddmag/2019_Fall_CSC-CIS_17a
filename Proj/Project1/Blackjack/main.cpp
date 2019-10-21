
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
#include <ctime>

using namespace std;
 const int STSIZE = 13; //Number of cards in a suit
 const int NUMST = 4;  // Number of suits
enum Facecard{
    King = 10,
    Queen = 10,
    Jack = 10,
    Ace = 1
};
struct deck{
    int suits, numcard;
    int **crdDeck;//[x][y];//={
       
    //};
    int **shflDck ; // Shuffled deck
    
};
int bet();
int deal();
bool checkScore();
void play();
void dealerPlay();
int shuffleDeck(int );
int dealToPlayer();
int clearPlayerHand(int &);


int main(int argc, char** argv) {
    // Set Variables
    int NUMHND = 1; //Number of hands == 2 
    int HNDSZ = 10; // number of cards in a hand 
    
    bool isGmOvr = false; // Game over variable
    bool plyrWin = false;
    int plyrMon = 200; // player money
    int dlrPot = 1000; // money in the dealers pot
    int plyrBet;
    
    srand((unsigned)time(0));
    
    int stdDeck[NUMST][STSIZE] = {
        { Ace, 2,3,4,5,6,7,8,9,10, Jack, Queen, King},
        { Ace, 2,3,4,5,6,7,8,9,10, Jack, Queen, King},
        { Ace, 2,3,4,5,6,7,8,9,10, Jack, Queen, King},
        { Ace, 2,3,4,5,6,7,8,9,10, Jack, Queen, King},
    };
    bool usdDeck[NUMST][STSIZE] = {0};
    
    int plyrHnd[HNDSZ][NUMHND]={0};
    
    //Start Game
    while (isGmOvr == false){
    // Get player bet
        plyrBet = 0;
        while (plyrBet <= 0 || plyrBet > plyrMon ){
        cout << "You currently have $" << plyrMon << endl;
        cout << "Place a bet that is greater than $0 and less than $" << plyrMon << ":"<< endl;
            while(! (cin >> plyrBet) ) {
                cout << "Not a Valid input try again" << endl;
                cin.clear();
                while(cin.get() != '\n');
            };
        
        };
        
        int cardsDealt=0;
    // Deal Cards
        do {
            bool newCard = false;
             
            int i, j;
            i = (rand()%STSIZE);
            j = (rand()%NUMST);
            
            if (usdDeck[j][i] == false){
                plyrHnd[0][cardsDealt] = stdDeck[j][i];
                usdDeck[j][i] = true;
                cardsDealt++;
            }
            
        }while (cardsDealt < 2);
    
    // display cards
        cout << plyrHnd[0][0] << " " << plyrHnd[0][1];
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
 
 int shuffleDeck(int deck ){
    
 }