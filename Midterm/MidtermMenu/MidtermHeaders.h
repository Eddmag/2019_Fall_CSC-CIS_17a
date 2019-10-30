/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MidtermHeaders.h
 * Author: Edgar Magana
 *
 * Created on October 29, 2019, 10:32 PM
 */
#include <string>

using namespace std;
       

#ifndef MIDTERMHEADERS_H
#define MIDTERMHEADERS_H



#ifdef __cplusplus
extern "C" {
#endif


struct sales{
    
    char divName[10];
    int qtrSale[];
    
};

struct Prime{
	unsigned short prime;
	unsigned char power;
};
struct Primes{
	unsigned char nPrimes;
	Prime *prime;
};

struct Employees{
    //unsigned int nSize;
    
    std::string emFName;
    std::string emLName;
    float hrsWrkd;
    float payRate;
    float grsPy;
    char grsPyAl[5];
    
};
struct Staff{
    Employees *employee;
    int emAmt;
};

// Prob 1

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
    cout << "What is your first name?" << endl;
        cusRos.name      = getInfo(cusRos.name, 20, false, false);
    cout << "what is your address? (No Space)(incompleteFeature)" << endl;
        cusRos.address   = getInfo(cusRos.address, 20, false, true);
    cout << "Input your account number: " << endl;
        cusRos.accNum    = getInfo(cusRos.accNum, 6, true, false);
    cout << "What was your balance at the beginning of the month? (Last completed feature)" << endl;
        cin >> acc;
        cusRos.pAccBal = acc;
    cout << "Input the value of all checks written this month: (Press enter after each value)" << endl;
    
    cout << "Input the value of all deposits made this month: (Press enter after each value)" << endl;
    return cusRos;
}

// Prob 2
void processEmployeeInfo(Employees &, int);
void processPaycheck (Employees &);
void printPaycheck (Staff, Employees);

void processEmployeeInfo(Employees &emplyee, int emNum){
    bool error;
    error = false;
    cout << "What is the first and last name of employee #" << emNum + 1 << "?" << endl;
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

//Prob 7

Primes *factor(int); // Input an integer, return all prime factors
void prntPrm(Primes *);  // Output all prime factors

Primes *factor(int inNum){
    Primes *primeNum = new Primes;
    primeNum->prime->power = 48;
    
    int count = 0;
    int num = inNum;
    primeNum->nPrimes = 48;
    
    for (int i = 2; (i) < 5001; i++){     
        if (num % i == 0 && i != num){
        primeNum->prime[count].power = 48;
        primeNum->nPrimes++;
            while (num % i == 0 && i != num){
                primeNum->prime[count].prime = i;
                primeNum->prime[count].power ++;     
                num = num / i;      
            }
            count++;
        }                      
    }

    if (num > 1 && num != inNum && num == primeNum->prime[count - 1].prime){
        num-= num;        
        primeNum->prime[count - 1 ].power++;
                
   } 
    if (num > 1 && num != inNum ){
                primeNum->nPrimes++;
                primeNum->prime[count].prime =num;
                primeNum->prime[count].power = 49;          
    }
    return primeNum;  
}

void prntPrm(Primes *prime){
    int sum = 0;
    for (int i = 0; i < prime->nPrimes - 48 ; i++){
        for (int j = 0; j < prime->prime[j].power ; j++){  
            sum *= prime->prime[i].prime;
        }
    }
    for (int i = 0; i < prime->nPrimes - 48 ; i++){
       cout << prime->prime[i].prime << "^" << prime->prime[i].power;
       if (i < prime->nPrimes - 48 - 1  )
           cout << "*";
    }
    cout << " "; 
}








#ifdef __cplusplus
}
#endif

#endif /* MIDTERMHEADERS_H */

