/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on September 11, 2019, 10:00 PM
 * Purpose: Predict population size
 */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries

// Global Variables

// Function prototypes

int main() {
    // Declare Variables
    unsigned int pop, days = 0;
    float popinc = 0;
    

    // Prompt
    cout << "This program will predict the size of a population!" << endl;
         
    while (pop <2){
        cout << "Enter the number of the starting amount of a population (must be at least 2): " << endl ;
        cin  >> pop;
    }
    while (popinc <= 0){
        cout << "Enter the amount, as a percentage, that the population increases per day(must be positive): " << endl ;
        cin  >> popinc;
    }
     while (days < 1){
        cout << "Enter the number of days the population will grow over: " ;
        cin  >> days;
    }
    // Convert to percent
    popinc *= .01;
    popinc += 1;
    
    // Output    
    for (int i=0; i<days ;i++){
        
        cout << "Day " << i + 1 << ": Population size is now: " << pop << endl;  
        pop = pop * popinc;
    }
    return 0;
}
