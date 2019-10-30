/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on October 27, 2019, 12:41 PM
 * Purpose:
 */

// System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// User Libraries

// Global Variables


// Data structures

struct Employees{
    //unsigned int nSize;
    
    string emFName;
    string emLName;
    float hrsWrkd;
    float payRate;
    float grsPy;
    char grsPyAl[5];
    
};
struct Staff{
    Employees *employee;
    int emAmt;
};

// Function prototypes
void processEmployeeInfo(Employees &, int);
void processPaycheck (Employees &);
void printPaycheck (Staff, Employees);

int main() {
    // Declare Variables
    Staff staff;
    
    
    
    cout << "How many Employees do you need to do payroll for?" << endl;
    cin >> staff.emAmt;
    
    staff.employee = new Employees[staff.emAmt];
    
    for(int i = 0 ; i < staff.emAmt; i++){
        processEmployeeInfo(staff.employee[i], i);
        processPaycheck(staff.employee[i]);
    }
   
    
    for (int i = 0; i < staff.emAmt; i++){
        printPaycheck(staff, staff.employee[i]);
    }
            
    
    // Prompt

    // Output    
    return 0;
}

void processEmployeeInfo(Employees &emplyee, int emNum){
    bool error;
    error = false;
    cout << "What is the name of employee #" << emNum + 1 << "?" << endl;
    cin >> emplyee.emFName >> emplyee.emLName;
    do{ 
       
        if (error == true){
            cout << "ERROR: Gross pay can not be less than zero or greater than or equal to $100,000" << endl;
        }
        
        do{
            cout << "How many hours did " << emplyee.emFName << " work? (Can not be negative!)" << endl;  
            cin >> emplyee.hrsWrkd;
        }while(emplyee.hrsWrkd <= 0);
        
        do{
            cout << "What is " << emplyee.emFName << "'s payrate?(Can not be negative!)" << endl;
            cin >> emplyee.payRate;
        }while(emplyee.payRate <= 0);
        
        if (emplyee.payRate * emplyee.hrsWrkd > 99999 || emplyee.payRate * emplyee.hrsWrkd < 1){
            error = true;
        }
    }while (emplyee.payRate * emplyee.hrsWrkd > 99999);

}
void processPaycheck (Employees &emp){
    for(int i = 0 ; i < 5 ; i++){
    emp.grsPyAl[i]= 48;
    }
    emp.grsPy = emp.hrsWrkd * emp.payRate;
    int chAmt = static_cast<int>(emp.grsPy);
    
  
  
    while ( chAmt  > 0  ){
        if (chAmt > 9999){
            emp.grsPyAl[0]++;
            chAmt -= 10000;   
        } else if (chAmt > 999){
                emp.grsPyAl[1]++;
                chAmt -= 1000;          
            }else if (chAmt > 99){
                    emp.grsPyAl[2]++;
                    chAmt -= 100;         
                } else if (chAmt > 9){
                        emp.grsPyAl[3]++;

                        chAmt -= 10;
                    } else if (chAmt > 0){
                            emp.grsPyAl[4]++;
                            chAmt -= 1;          
                        }
        
       
    }
    
    
}
void printPaycheck(Staff roster, Employees emplyee){
    cout << setfill ('_') << setw(120) << '_'<< endl ;
    cout << endl << "Magaña Inc." << endl;
    cout << "1234 Fake St." << endl  << "Riverside, CA 92501" << endl  << endl << endl << endl;
    cout << "   Pay to the" << endl << "     order of: " << emplyee.emFName  << " " << emplyee.emLName << setfill (' ')  << setw(80) << "$" 
         << fixed << setprecision(2) << emplyee.grsPy << endl << endl; 
    cout << setw(20); 
    for (int i = 0; i < 5; i++){
        switch (emplyee.grsPyAl[i] - 48) {
            case 0:
                if (emplyee.grsPy == 0){
                    cout << "Zero";
                }
                if (i == 4 && emplyee.grsPyAl[i - 1] - 48 == 1 && emplyee.grsPyAl[i] - 48  == 0){
                    cout << "Ten";
                }
                break;
            case 1:
                if (i  == 4  && (emplyee.grsPyAl[i - 1] - 48 >= 2 || i == 4 && emplyee.grsPyAl[i - 1] - 48 == 0)){
                    
                        cout << "One" ;
                    
                }
                if (i == 2 ){
                    cout << "One";
                }
                if (i == 1 && emplyee.grsPyAl[i - 1] - 48 != 0){
                    cout << "One";
                }
                
                
                break;
            case 2:
                if (i  < 3 && i > 0 || i == 4  ){
                    if ((i == 4 || i == 1) && (emplyee.grsPyAl[i - 1] - 48 > 1 || emplyee.grsPyAl[i - 1] - 48 == 0 )){
                        cout << "Two";
                    }
                }
                if(i == 3  || i == 0) {
                    if(emplyee.grsPyAl[i + 1] - 48 != 0 ){
                    cout << " Twenty-";
                    } else cout << " Twenty";
                }
                
                break;
            case 3:
                if (i  < 3 && i > 0 || i == 4 && emplyee.grsPyAl[i - 1] - 48 >= 1){
                    if (emplyee.grsPyAl[i - 1] - 48 != 1 ){
                        cout << "Three";
                    }
                }
                if(i == 3 || i == 0) {
                    cout << "Thirty-";
                }
                if (i == 4 || i == 1){
                    if (emplyee.grsPyAl[i - 1] - 48 == 1 ){
                            cout << "Thir";
                    }
                }
                break;
            case 4:
                if (i  < 3 && i > 0 || i == 4){
                cout << "Four";
                }
                if(i == 3 || i == 0) {
                    cout << "Forty-";
                }
                break;
            case 5:
                if (i  < 3 && i > 0 || i == 4){
                cout << "Five";
                }
                if(i == 3 || i == 0) {
                    cout << "Fifty";
                
                }
                break;
            case 6:
                if (i  < 3 && i > 0 || i == 4){
                cout << "Six";
                }
                if(i == 3 || i == 0) {
                    cout << "Sixty-";
                }
                break;
            case 7:
                if (i  < 3 && i > 0 || i == 4 ){
                cout << "Seven";
                }
                if(i == 3 || i == 0) {
                    cout << "Seventy-";
                }
                break;
            case 8:
                if (i  < 3 && i > 0 || i == 4 ){
                cout << "Eight";
                }
                if(i == 3 || i == 0) {
                    cout << "Eighty-";
                }
                break;
            case 9:
                if (i  < 3 && i > 0 || i == 4 ){
                cout << "Nine"; 
                }
                if(i == 3 || i == 0) {
                    cout << "Ninety-";
                   
                }
                break;
        }
        
        switch (i){
            case 0:

                break;
            case 1:
                if (emplyee.grsPyAl[i] - 48  > 2 && emplyee.grsPyAl[i - 1] - 48 == 1 ){
                    cout << "teen";
                }
                 if (emplyee.grsPyAl[i - 1] - 48 == 1 && emplyee.grsPyAl[i] - 48  == 2){
                    
                    cout << " Twelve";
                }
                if (emplyee.grsPyAl[i - 1] - 48 == 1 && emplyee.grsPyAl[i] - 48  == 1){
                    
                    cout << " Eleven";
                }
                if (emplyee.grsPyAl[i] - 48 != 0 || emplyee.grsPyAl[i - 1] - 48 != 0){
                cout << " Thousand ";
                }
                break;
            case 2:
                if (emplyee.grsPyAl[i] - 48 != 0){
                    
                    
                cout << " Hundred ";
                }
                break;
            case 3:
                
                break;
            case 4:
                if (emplyee.grsPyAl[i] - 48  > 2 && emplyee.grsPyAl[i - 1] - 48 == 1 ){
                    cout << "teen";
                }
                 if (emplyee.grsPyAl[i - 1] - 48 == 1 && emplyee.grsPyAl[i] - 48  == 2){
                    
                    cout << "Twelve";
                }
                if (emplyee.grsPyAl[i - 1] - 48 == 1 && emplyee.grsPyAl[i] - 48  == 1){
                    
                    cout << "Eleven";
                }
                break;
            
        }
        
    }
    cout << " Dollars and Zero cents" << endl  << endl << endl  << endl << "     Signature: "<< setfill ('_') << setw(60)  << '_' << endl
         << endl  << setw(120) << '_' << endl ;
    
} 