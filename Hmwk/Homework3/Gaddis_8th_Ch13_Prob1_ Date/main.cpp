
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
#include <cstring>
#include <sstream>

using namespace std; 

// Date Class
class Date{
    private:
        static const int DTSIZE = 3;
        int date[DTSIZE];
        string dtAl[DTSIZE];
        
    public:
        Date();
        void setDate();
        bool checkDate();
        void setDtAl();
        void printDate();
        
};
// Three integers for month day and year

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Date date;
    
    date.setDate();
    date.printDate();
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
    
    cout << "What is the current day in numerical form (1 - 31)?" << endl;
    
    while(date[1] <= 0 || date[1] > 31){ 
        do{
            cin >> date[1];
            if (date[1] <= 0 || date[1] > 31){
                cout << "Must be between 1 to 31 !" << endl;
            }
            if (checkDate() == false){
                cout << "Not a real date!" << endl;
            }
        } while (checkDate() == false);
    }
    
    date[2] = 2019;
    setDtAl();
}

bool Date::checkDate(){
    if (date[0] == 1 || date[0] == 3 || date[0] == 5 || date[0] == 7 || date[0] == 8 || date[0] == 10 || date[0] == 12 && date[1] > 0 && date[1] <= 31){
        return true;
    }
    if (date[0] == 2 &&  date[1] < 29 && date[1]> 0){
        return true;
    }
    if ( (date[1] > 0 && date[1] <= 30) && date[0] == 4 || date[0] == 6 || date[0] == 9 || date[0] == 11){
        return true;
    }
    return false;    
}

void Date::printDate(){
    cout << "Today's date is " << date[0] << "/" << date[1] << "/" << date[2] << "!" << endl;
    cout << "It can also be represented as " << dtAl[0] << " " << dtAl[1] << ", " << dtAl[2] << endl;
    cout << "or " <<dtAl[1] << " " << dtAl[0] << " " << dtAl[2] << endl;
}

void Date::setDtAl(){
    
    ostringstream temp;
    temp << date[1];
    dtAl[1] = temp.str();
    temp.str(string());
    temp << date[2];
    dtAl[2] = temp.str();
   
    
    switch (date[0]){
        case 1:
            dtAl[0] = "January";
            break;
        case 2:
            dtAl[0] = "February";
            break;
        case 3:
            dtAl[0] = "March";
            break;
        case 4:
            dtAl[0] = "April";
            break;
        case 5:
            dtAl[0] = "May";
            break;
        case 6:
            dtAl[0] = "June";
            break;
        case 7:
            dtAl[0] = "July";
            break;
        case 8:
            dtAl[0] = "August";
            break;
        case 9:
            dtAl[0] = "September";
            break;
        case 10:
            dtAl[0] = "October";
            break;
        case 11:
            dtAl[0] = "Novemeber";
            break;
        case 12:
            dtAl[0] = "December";
            break;
        default:
            break;
        
    }
}