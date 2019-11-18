/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on November 17, 2019, 10:28 PM
 * Purpose:   5. Time Off
                    Design a class named TimeOff . The purpose of the class is to track an employee’s
                    sick leave, vacation, and unpaid time off. It should have, as members, the following
                    instances of the NumDays class described in Programming Challenge 4:
                        maxSickDays A NumDays object that records the maximum number of days of
                    sick leave the employee may take.
                        sickTaken A NumDays object that records the number of days of sick leave the
                    employee has already taken.
                        maxVacation A NumDays object that records the maximum number of days of
                    paid vacation the employee may take.
                        vacTaken A NumDays object that records the number of days of paid vacation
                    the employee has already taken.
                        maxUnpaid A NumDays object that records the maximum number of days of
                    unpaid vacation the employee may take.
                        unpaidTaken A NumDays object that records the number of days of unpaid leave
                    the employee has taken.
 * 
                    Additionally, the class should have members for holding the employee’s name and identification
                    number. It should have an appropriate constructor and member functions for
                    storing and retrieving data in any of the member objects.
                    Input Validation: Company policy states that an employee may not accumulate more
                    than 240 hours of paid vacation. The class should not allow the maxVacation object
to store a value greater than this amount.
 * 
 */
// system libraries
#include <iostream>

using namespace std;

// user libraries

// classes
class NumDays{
    private:
        int wHr = 0;
        float days = 0.0;
    public:
        NumDays(){
            
        }
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
        void setHours(int i){   
            wHr = i;
        }
        void setDays(){   
            days = static_cast<float>(wHr) / 8.0;
        }
};

class TimeOff{
    private:
        string name;
        int id;
        
        NumDays maxSickDays;
        NumDays sickTaken;
        NumDays maxVacation;
        NumDays vacTaken;
        NumDays maxUnpaid;
        NumDays unpaidTaken;
        
    public:
        TimeOff(string, int, int, int, int);
        void setTime(NumDays &x, int i){
            x.setHours(i);
        }
        string getName(){
            return name;
        }
        int getId(){
            return id;
        }
        int getMaxSick(){
            return maxSickDays.getHours();
        }
        int getMaxVac(){
            return maxVacation.getHours();
        }
        int getMaxUPT(){
            return maxUnpaid.getHours();
        }
        int getSick(){
            return sickTaken.getHours();
        }
        int getVac(){
            return vacTaken.getHours();
        }
        int getUPT(){
            return unpaidTaken.getHours();
        }
        
};
int main(int argc, char** argv) {
    string name;
    int id, sick, vac, upt;
    
    cout << "Input employees first name: ";
    cin >> name;
    cout << "What is " << name << "'s Employee ID?: ";
    cin >> id;
    cout << "How much sick time has " << name << " taken?: ";
    cin >> sick;
    cout << "How much vacation time has " << name << " taken?: ";
    cin >> vac;
    cout << "How much unpaid time has " << name << " taken?: ";
    cin >> upt;
   
    TimeOff emplye(name, id, sick, vac, upt);
    
    cout << "Employee #" << emplye.getId() << ", " << emplye.getName() << ", has taken " << (emplye.getSick()  + emplye.getVac() + emplye.getUPT()) << " hours of his time off!";
    
    return 0;
}

TimeOff::TimeOff(string n, int i, int j, int k, int l){
    name = n;
    id = i;
    
    setTime(maxSickDays, 40);
    setTime(maxVacation, 240);
    setTime(maxUnpaid, 80);
    
    setTime(sickTaken, j);
    setTime(vacTaken,  k);
    setTime(unpaidTaken, l);
    
}
bool valNum(int i){
    if (i > 0 && i <= 240){
        return true;
    } else return false;
}
