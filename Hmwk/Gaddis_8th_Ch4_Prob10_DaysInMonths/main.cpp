/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on September 11, 2019, 8:58 PM
 * Purpose: Find the Days in a month
 */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries

// Global Variables

// Function prototypes

int main() {
    // Declare Variables
    short Month, Year, Days = 0 ; // Initialize variables 
    bool LeapYr = false;          // Initialize bool to keep track of leap year
    
    // Prompt
    while ( Month < 1 || Month > 12) {                                             // Ask user for number between 1 and 12
        cout << "Please enter a Month in number form (1 - 12): " ;
        cin  >> Month;
    };
    while ( Year < 1 || Year > 100000) {                                           // Ask user for number from 1 - 100,000
    cout << "Please enter a Year in number form (2019): " ;
    cin  >> Year;
    };
    
    // Calculate
    if (Year % 100 == 0 && Year % 400 == 0){                                        // Check if year is divisible by 100 and 400
        LeapYr = true;
    } else if (Year % 100 != 0 && Year % 4 == 0){                                   // Check if year is divisible by 4
        LeapYr = true;
    }
    else LeapYr = false;                                                            // Set bool value to see if it is a leap year or not
   
    
    if ( Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12){
        Days = 31;
    } else if ( Month == 4 || Month == 6 || Month == 9 || Month == 11){             // Assign days variable with the correct number of days in a month
        Days = 30;
    } else if ( Month == 2){
        if (LeapYr == true){
            Days = 29;                                                              // If leap year add one to the month of February
        }else Days = 28;                                                            
    }
    
    // Output
    cout << endl << Days << " Days" << endl;
    return 0;
}

