/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on September 11, 2019, 8:02 PM
 * Purpose: Convert from US Dollars to Yen and Euros
 */

// System Libraries
#include <iostream>
#include <iomanip>  //Library for function that allows fixed point notation
using namespace std;

// User Libraries

// Global Variables

// Function prototypes

int main() {
    // Declare Variables
    const float YEN_PER_DOLLAR = 108.02; // SET Yen per dollar to current rate at 8PM on 09/11/2019
    const float EUROS_PER_DOLLAR = 0.91; // SET Euro per dollar to current rate at 8PM on 09/11/2019
    float Dollar, Yen, Euro = 0; // Initialize variables for all currencies 
    

    // Prompt
    cout << "This program converts US Dollar exchange rates to Yen and Euros." ;
    while (Dollar <= 0){
    cout << endl << "Please enter a positive dollar amount in USD: ";
    cin  >> Dollar;   // ask for value of Dollars
    }
    // Calculate
    Yen = Dollar * YEN_PER_DOLLAR;  // Multiply the dollar amounts by the currency exchange rates
    Euro = Dollar * EUROS_PER_DOLLAR;
    
    // Output    
    
    cout << "The Value of $" << fixed << setprecision(2) << Dollar << " in Yen is: " << Yen << endl; // Output the values in fixed point notation
    cout << "The Value of $" << Dollar << " in Euros is: " << Euro;
    
    return 0;
}

