/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Purpose: 12. Coin Toss Simulator
                    Write a class named Coin . The Coin class should have the following member variable:
                    • A string named sideUp . The sideUp member variable will hold either “heads” or
                    “tails” indicating the side of the coin that is facing up.
                    The Coin class should have the following member functions:
                    • A default constructor that randomly determines the side of the coin that is facing up
                    (“heads” or “tails”) and initializes the sideUp member variable accordingly.
                    • A void member function named toss that simulates the tossing of the coin. When
                    the toss member function is called, it randomly determines the side of the coin that
                    is facing up (“heads” or “tails”) and sets the sideUp member variable accordingly.
                    • A member function named getSideUp that returns the value of the sideUp member
                    variable.
                    Write a program that demonstrates the Coin class. The program should create an
                    instance of the class and display the side that is initially facing up. Then, use a loop
                    to toss the coin 20 times. Each time the coin is tossed, display the side that is facing
                    up. The program should keep count of the number of times heads is facing up and the
number of times tails is facing up, and display those values after the loop finishes.
 * Created on November 3, 2019, 7:22 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

//Classes
class Coin{
    private:
        string sideUp;
    public:
        Coin();
        void toss();
        void toss20();
        string getSideUp(){
            return sideUp;
        };
    
};

int main(int argc, char** argv) {
    Coin coin;
    coin.toss20();
    return 0;
}

Coin::Coin(){
    srand((unsigned)time(0)); 
    int i;
    i = (rand()%2); //get a random number between 0 - 1
    if (i == 0){
        sideUp = "Heads";
    } else if (i == 1){
            sideUp ="Tails";
        }
}

void Coin::toss(){
     
    int i;
    i = (rand()%2); //get a random number between 0 - 1 
    if (i == 0){
        sideUp = "Heads";
    } else if (i == 1){
            sideUp ="Tails";
        }
    
}

void Coin::toss20(){
    int hdSd = 0; // count variable for heads
    int tlSd = 0; // count variable for tails
    
    cout << "The coin is currently on the " << sideUp << " side." << endl;
    
    for (int i = 0 ; i < 20 ; i++){
        toss();
        if (sideUp == "Heads"){
            hdSd ++;
        } else if (sideUp == "Tails"){
            tlSd++;
            }
        cout << "Flip #" << i+1 << ": " << sideUp << endl;
    }
    
    cout << endl << "The coin landed on Heads " << hdSd << " times!";
    cout << endl << "The coin landed on Tails " << tlSd << " times!";
}