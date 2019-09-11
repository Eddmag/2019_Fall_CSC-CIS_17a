/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on September 10, 2019, 4:02 PM
 * Purpose: Convert temperatures from Celsius to Fahrenheit
 */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries

// Global Variables

// Function prototypes

int main() {
    // Declare Variables
    float F = 0;    // Declare a variable for Fahrenheit and set it equal to zero
    int C = 0;      // Declare a variable for Celsius and set it equal to zero
    
    // Prompt
    cout << "Input a temperature in Celsius: " ; 
    cin >> C ;      // Have user input a value for C
    
    // Calculate
    F = static_cast<float>(C) * 1.8 + 32;
    
    //F = C *1.8;
    // Output    
    cout << "The temperature in Degrees Fahrenheit for the value you entered is: " 
         << F << endl;        // Output the Fahrenheit float
    return 0;
}

