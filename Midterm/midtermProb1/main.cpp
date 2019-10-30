/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on October 25, 2019, 10:50 AM
 * Purpose:
 */

// System Libraries
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

// User Libraries

// Global Variables

// Function prototypes

struct Customer{
    bool isOvrDft;
    string name;
    string address;
    string accNum;
    int pAccBal;
    int accBal;
    unsigned int wthdrls;
    unsigned int deps;
};
struct Customers{
    Customer *roster;
    int cliAmt;
};
int newBalance(Customer);
Customer *newCustomers(int);
void overDraftWarning(int);
void displayCustomerInfo(Customer);
Customer setInfo(Customer);
string getInfo(string, int , bool, bool);

int main() {
    // Declare Variables
    Customers bank;
    int cusAmt;
    cout << "How many Bank Clients?";
    cin >> cusAmt;
    bank.cliAmt = cusAmt;
    bank.roster = new Customer[bank.cliAmt];
    bank.roster[0] = setInfo(bank.roster[0]);
    
    // Prompt

    // Output    
    displayCustomerInfo(bank.roster[0]);
    
    return 0;
}

Customer *newCustomers(int cusAmt ){
    Customer *cusRos;
    

    
    
    return cusRos;
}



void displayCustomerInfo(Customer cusList){
    
    cout << "Name: " << cusList.name << endl;
    cout << "Address: " <<  cusList.address << endl;
    cout << "Account number: " << cusList.accNum << endl;
    cout << "Account Balance:  " << cusList.pAccBal<< endl;
    cout << "Total Withdrawn this month: " << cusList.wthdrls << endl;
    cout << "Total deposited this month: " << cusList.deps << endl;
    
    if (cusList.isOvrDft == true){
        cout << "Your account has overdrawn! A fee of $20 has been deducted from your account!" << endl;
        cout << "Account balance before overdraft: " << cusList.accBal + 20 << endl;
    }
    
    cout << "Current account Balance:" << cusList.accBal << endl;
}
string getInfo(string info, int size, bool isLenRq, bool isMixed){
    if (isLenRq == true){
        bool numVer = false;
        do{   
            cout << "Input max length of " << size << endl;
            cin >> info;
            if (info.length() == 6 ){
                for (int i =0; i < info.length(); i++){
                    if (info[i] >= 48 && info[i] <= 57){
                        numVer = true;
                    } else {
                        numVer = false;
                        i = info.length();
                    }; 
                }
            }
        } while (info.length() != 6 || numVer == false);
    };
    if (isMixed == false){
        if (isLenRq == false){
            bool alVer = false;
            do{   
                cout << "Input max length of " << size << endl;
                getline(cin, info);
                //if (info.length() == 6 ){
                    for (int i = 0; i < info.length(); i++){
                        if (info[i] >= 65 && info[i] <= 90 || info[i] >= 97 && info[i] <= 122){
                            alVer = true;

                        } else {
                            alVer = false; 
                            i = info.length();      
                        };
                    }
                //}
            } while (alVer == false);
        }
    };
    if (isMixed == true){
        if (isLenRq == false){
            bool alVer = false;
            do{   
                cout << "Input max length of " << size << endl;
                getline(cin, info);
                //if (info.length() == 6 ){
                    for (int i = 0; i < info.length(); i++){
                        if (info[i] >= 65 && info[i] <= 90 || info[i] >= 97 && info[i] <= 122 || info[i] >= 48 && info[i] <= 57){
                            alVer = true;

                        } else {
                            alVer = false; 
                            i = info.length();      
                        };
                    }
                //}
            } while (alVer == false);
        }
    };
    
    
    return info;
}

Customer setInfo(Customer cusRos){
int acc;
    cout << "What is your name?" << endl;
        cusRos.name      = getInfo(cusRos.name, 20, false, false);
    cout << "what is your address?" << endl;
        cusRos.address   = getInfo(cusRos.address, 20, false, true);
    cout << "Input your account number: " << endl;
        cusRos.accNum    = getInfo(cusRos.accNum, 6, true, false);
    cout << "What was your balance at the beginning of the month?" << endl;
        cin >> acc;
        cusRos.pAccBal = acc;
    cout << "Input the value of all checks written this month: (Press enter after each value)" << endl;

    cout << "Input the value of all deposits made this month: (Press enter after each value)" << endl;
    return cusRos;
}