/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on November 17, 2019, 6:46 PM
 * Purpose:     2.  Day of the Year 
                        Assuming that a year has 365 days, write a class named 
                       DayOfYear  that takes an inte-
                       ger representing a day of the year and translates it to a string consisting of the month
                       followed by day of the month. For example, 
                         Day 2 would be  January 2 .
                        Day 32 would be  February 1 .
                        Day 365 would be  December 31.   
                        The constructor for the class should take as parameter an integer representing the day
                       of the year, and the class should have a member function 
                       print()  that prints the day
                       in the month–day format. The class should have an integer member variable to repre-
                       sent the day and should have static member variables holding 
                       string  objects that can 
                       be used to assist in the translation from the integer format to the month-day format.
                        Test your class by inputting various integers representing days and printing out their 
                       representation in the month–day format. 
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
    DayOfYear i(1);
    
    i.print();
    
    DayOfYear j(45);
    
    j.print();
    
    DayOfYear k(185);
    
    k.print();
    
    DayOfYear l(307);
    
    l.print();
    
    DayOfYear m(365);
    
    m.print();
    // Prompt
    
    // Output    
    return 0;
}




