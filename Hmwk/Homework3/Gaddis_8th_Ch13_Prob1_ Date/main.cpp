
/* 
 * File:   main.cpp
 * Author: Eddy
 * Purpose:             1. Date
        Design a class called Date . The class should store a date in three integers: month , day ,
        and year . There should be member functions to print the date in the following forms:
        12/25/2014
        December 25, 2014
        25 December 2014
        Demonstrate the class by writing a complete program implementing it.
        Input Validation: Do not accept values for the day greater than 31 or less than 1. Do
        not accept values for the month greater than 12 or less than 1.
 *
 * Created on November 3, 2019, 1:03 AM
 */

#include <cstdlib>
#include <iostream>

// Date Class
class Date{
    private:
        static const int DTSIZE = 3;
        int date[DTSIZE];
        
    public:
        Date();
        void setDate();
        void setDtAl();
        
};
// Three integers for month day and year

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Date date;
    
    date.setDate();

    return 0;
}

Date::Date(){
    for (int i = 0; i < DTSIZE ; i++){
        date[i] = 0;
    }
}

void Date::setDate(){
    cout << "What is the current month in numerical form (1 - 12)?" << endl;
    
    while(date[0] <= 0 || date[0] > 12){ 
        cin >> date[0];
        if (date[0] <= 0 || date[0] > 12){
            cout << "Must be between 1 to 12 !" << endl;
        }
    }
}