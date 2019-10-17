/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on October 13, 2019, 11:54 PM
 * Purpose:
 */

// System Libraries
#include <iostream>
#include <fstream>
using namespace std;

// User Libraries

// Global Variables

// Function prototypes
void arrayToFile(char [], int &, const int);

int main() {
    // Declare Variables
    
    const int SIZE = 20;
    char fName[SIZE];
    int ary[SIZE] ={2 , 5, 6 };
    int *aryPtr;
    aryPtr = ary;
    // Prompt
    arrayToFile(fName, *aryPtr, SIZE);
    
    // Output    
    return 0;
}
void arrayToFile(char fName[], int &array, const int SIZE ){
    fstream file;
    
    file.open(fName, ios::binary);
    
    file.read(reinterpret_cast<char*> fName[], sizeof(fName[])) << endl;
    
    file.close(fName);
}
