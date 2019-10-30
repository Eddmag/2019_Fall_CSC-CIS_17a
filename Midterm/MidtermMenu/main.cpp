/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eddy
 *
 * Created on October 29, 2019, 9:58 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>


using namespace std;

#include "MidtermHeaders.h"

void Menu();
int getN();

int problem1();
int problem2();
int problem3();
int problem4();
int problem5();
int problem6();
int problem7();

int main(int argc, char** argv) {
    int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          default:   Menu();}
        }while(inN<8);
    return 0;
}
void Menu(){
    cout << "Edgar Magaña's Midterm" << endl 
         << "Select which problem you want to run:" << endl
         << "1.Problem 1(incomplete)" << endl
         << "2.Problem 2" << endl
         << "3.Problem 3(Missing)" << endl
         << "4.Problem 4(Missing)" << endl
         << "5.Problem 5(Missing)" << endl
         << "6.Problem 6(incomplete)" << endl
         << "7.Problem 7(Broken on migration)" << endl
         << "8. Quit" << endl;
            
}
int problem1(){
 // Declare Variables
    Customers bank;
    int cusAmt;
    cout << "How many Bank Clients?";
    cin >> cusAmt;
    bank.cliAmt = cusAmt;
    bank.roster = new Customer[bank.cliAmt];
    for (int i = 0; i < cusAmt; i++){ 
    bank.roster[i] = setInfo(bank.roster[i]);
    }
    // Prompt

    // Output    
    displayCustomerInfo(bank.roster[0]);
    
    return 0;
}
int problem2(){
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
int problem3(){}
int problem4(){}
int problem5(){}
int problem6(){
    cout << "2.875 to Hex" << endl << " multiply remainder by 16 which gives you 14 which is E in Hex so you end up with 2.E" << endl
         << "2.E to binary" << endl << " 2 is 0010 and E is 1110 in binary" << endl 
         << "0010.1110 to binary" << endl << "010 is 2 in octal, 111 is 7 in octal" << endl << endl;
    
    cout << "0.1796875 to Hex" << endl << "0.1796875 time 16 is 2.875. Multiply the remainder by 16 which comes out to 14 which is once again e"
         << endl << ".2E to binary" << endl << "2 is 0010 is binary, E is 1110 in binary" << endl
         << ".00101110 to octal" << "group in threes , 001 011 100, which is .134 in octal" << endl;

}
int problem7(){
// Declare Variables
    Primes *prime = new Primes;
    
    
    int num = 0;
    // Prompt

    // Output    
    cout << "Input an integer from 2 to 10000 to factor" << endl;
    cin >> num;

    cout <<  endl << endl;

    prime = factor(num);
  
    prntPrm(prime);
    
    delete[] prime;
    cout << "Done";
    return 0;
}


int getN(){
    int inp;
    cin >> inp;
    return inp;
}



