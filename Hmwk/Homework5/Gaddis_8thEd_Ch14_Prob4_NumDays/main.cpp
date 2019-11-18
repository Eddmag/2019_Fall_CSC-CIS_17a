/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on November 17, 2019, 6:51 PM
 * Purpose:         4. NumDays  Class 
                                Design a class called 
                               NumDays . The class’s purpose is to store a value that represents a 
                               number of work hours and convert it to a number of days. For example, 8 hours would
                               be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would 
                               be converted to 2.25 days. The class should have a constructor that accepts a number
                               of hours, as well as member functions for storing and retrieving the hours and days.
                               The class should also have the following overloaded operators:    

                               +   Addition operator.  When two  NumDays  objects are added together, the overloaded
                               + operator should return the sum of the two objects’ hours members.



                               −   Subtraction operator.  When one  NumDays  object is subtracted from another,
                               the overloaded 
                               −  operator should return the difference of the two objects’ hours
                               members.  

                               ++   Prefix and postfix increment operators.  These operators should increment the
                               number of hours stored in the object. When incremented, the number of days
                               should be automatically recalculated.  

                               −−   Prefix and postfix decrement operators.  These operators should decrement the
                               number of hours stored in the object. When decremented, the number of days
                               should be automatically recalculated. 
 */

// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

// User Libraries

// Global Variables

// Function prototypes


class NumDays{
    private:
        int wHr = 0;
        float days = 0.0;
    public:
        NumDays(int i){
            wHr = i;
        }
        NumDays operator + (NumDays& i){
            NumDays j(0);
            j.wHr = this->wHr + i.wHr;
            return j;
        }
        NumDays operator - (NumDays& i){
            NumDays j(0);
            j.wHr = this->wHr - i.wHr;
            return j;
        }
        NumDays operator -- (int i){
           
            this->wHr = this->wHr - 1;
            return *this;
        }
        NumDays operator ++ (int i){
           
            this->wHr = this->wHr + 1;
            return *this;
        }
        int getHours(){
            return wHr;
        }
        float getDays(){
            setDays();
            return days;
        }
        void setDays(){   
            days = static_cast<float>(wHr) / 8.0;
        }
};
int main() {
    // Declare Variables
    NumDays john(41);
    NumDays jane(39);
    NumDays dpmnt(0);
    // Prompt

    // Output    
    
    cout << "John worked " << john.getHours() << " hours, which is equivalent to " << fixed << setprecision(2) << john.getDays() << " days." << endl
         << "Jane worked " << jane.getHours() << " hours, which is equivalent to " << fixed << setprecision(2) << jane.getDays() << " days." << endl;
    
    dpmnt = john + jane;
    
    cout << "Together John and Jane worked " << dpmnt.getHours() << " hours, which is equivalent to " << fixed << setprecision(2) << dpmnt.getDays() << " days." << endl;
    
    john--;
    
    cout << "If John worked one hour less he would have worked " << john.getHours() << " hours, which is equivalent to " << fixed << setprecision(2) << john.getDays() << " days." << endl;
    
    jane++;
    
    cout << "If Jane worked one hour more she would have worked " << john.getHours() << " hours, which is equivalent to " << fixed << setprecision(2) << john.getDays() << " days." << endl;
    return 0;
}


