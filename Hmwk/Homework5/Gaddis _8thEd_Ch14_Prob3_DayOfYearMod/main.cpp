/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on November 17, 2019, 6:48 PM
 * Purpose:        3.     Day of the Year Modification  
                                Modify the 
                               DayOfYear  class, written in Programming Challenge 2, to add a constructor
                               that takes two parameters: a 
                               string object representing a month and an integer in
                               the
                               range 0 through 31 representing the day of the month. The constructor should then
                               initialize
                               the integer member of the class to represent the day specified by the month
                               and
                               day of month parameters. The constructor should terminate the program with an
                               appropriate
                               error message if the number entered for a day is outside the range of days 
                               for the month given. 
                                Add the following overloaded operators:

                               ++   prefix and postfix increment operators.  These operators should modify the 

                               DayOfYear  object so that it represents the next day. If the day is already the end
                               of the year, the new value of the object will represent the first day of the year. 

                               −−   prefix and postfix decrement operators . These operators should modify the

                               DayOfYear  object so that it represents the previous day. If the day is already the
                               first day of the year, the new value of the object will represent the last day of the
                               year.   
 */

// System Libraries
#include <iostream>
#include <string>
using namespace std;

// User Libraries

// Global Variables

// Function prototypes
class DayOfYear{
    private:
        int day;
    public:
        DayOfYear( int i ){
            day = i;
        }
        DayOfYear( string i , int j ){
            day = i;
        }
        print(){
            int tDay = day;
            int *dPtr = &tDay;
            
            int month = getMonth(dPtr);
            string monthAl = getMonthAlph(month);
            
            cout << monthAl << " " << tDay << endl;
            
 
        }
        string getMonthAlph(int month){
            switch (month){
                case 1:
                    return "January";
                    break;
                case 2:
                    return "February";
                    break;
                case 3:
                    return "March";
                    break;
                case 4:
                    return "April";
                    break;
                case 5:
                    return "May";
                    break;
                case 6:
                    return "June";
                    break;
                case 7:
                    return "July";
                    break;
                case 8:
                    return "August";
                    break;
                case 9:
                    return "September";
                    break;
                case 10:
                    return "October";
                    break;
                case 11:
                    return "November";
                    break;
                case 12:
                    return "December";
                    break;
                default:
                    break;
            }
        }
        int getMonth(int *i){
            int month = 1;
            if (*i > 31){        // January
                *i -= 31;
                month++;
            } else return month;
            if (*i > 28){        // February
                *i -= 28;
                month++;
            } else return month;
            if (*i > 31){        // March
                *i -= 31;
                month++;
            } else return month;
            if (*i > 30){        // April
                *i -= 30;
                month++;
            } else return month;
            if (*i > 31){        // May
                *i -= 31;
                month++;
            } else return month;
            if (*i > 30){        // June
                *i -= 30;
                month++;
            } else return month;
            if (*i > 31){        // July
                *i -= 31;
                month++;
            } else return month;
            if (*i > 31){        // August
                *i -= 31;
                month++;
            } else return month;
            if (*i > 30){        // September
                *i -= 30;
                month++;
            } else return month;
            if (*i > 31){        // October
                *i -= 31;
                month++;
            } else return month;
            if (*i > 30){        // November
                *i -= 30;
                month++;
            } else return month;
            
            return month;
        }
};
int main() {
    // Declare Variables

    // Prompt

    // Output    
    return 0;
}

