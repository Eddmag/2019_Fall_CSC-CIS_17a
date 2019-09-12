/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on September 11, 2019, 10:35 PM
 * Purpose: use Functions to print a Celsius table
 */

// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

// User Libraries

// Global Variables

// Function prototypes
float celsius (int);                                                            //Prototype to let the compiler know to expect a function late

int main() {
    // Declare Variables
    int f = 0;                                                                  // Initialize a value for Fahrenheit
    int count;                                                                  // Add a counting variable
    
    // Table
    cout << setw(2) << "Fahrenheit" << setw(15) << "Celcius" << endl;           // Draw the table

    // Output    
    for (f = 0; f <= 20; f++){
        cout << setprecision(2) << fixed << setw(5) << f << setw(19) 
             << celsius(f) << endl;                                             // Output values for the table
    }
    return 0;
}
float celsius (int f){                                                          // function converts Fahrenheit to Celsius
    float c ;
    c = ((static_cast<float>(f) - 32)* (5.0/9.0));
    return c;  
}

