/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on September 11, 2019, 10:54 PM
 * Purpose: Binary Search
 */

// System Libraries
#include <iostream>
#include <string>
using namespace std;

// User Libraries

// Global Variables

// Function prototypes
void PrintA(string [], int);
bool bSearch(string [], int , string );
void Sort(string [], int);

int main() {
    // Declare Variables
    const int NUM_NAMES = 20;
    string trgtNm = "Pike, Gordon";
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                            "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                            "Taylor, Terri", "Johnson, Jill",
                            "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                            "James, Jean", "Weaver, Jim", "Pore, Bob",
                            "Rutherford, Greg", "Javens, Renee",
                            "Harrison, Rose", "Setzer, Cathy",
                            "Pike, Gordon", "Holland, Beth" };
    
    
    // Output    
    Sort(names, NUM_NAMES);

 
    PrintA(names, NUM_NAMES);
    
    
    if (bSearch(names, NUM_NAMES, trgtNm) == true){
        cout << "Name Found!" << endl;
    }
    else cout << "Name NOT found!" << endl; 
    return 0;
}


void PrintA(string names[], int MAX){
    for (int i = 0; i < MAX ; i++){
        cout << names[i] << endl << endl;
    }
}

bool bSearch(string array[], int numName, string value)
{
    int first = 0,  // First array element
        last = numName -1 ,  // Last array element
        middle;  // Midpoint of search
    bool found = false;  // Flag 
    while (!found && first <= last)
    {
        middle = (first + last) / 2;  // Calculate midpoint
        if (array[middle] == value)  // If value is found at mid
        {
            return true;
        }
        else if (array[middle] > value)  // If value is in lower half
           last = last - 1;
        else
           first = first + 1;  // If value is in upper half
        
    } 
    return false;
 }  
 void Sort(string array[], int size){
    int i, index;
    string value;
 
    for(i = 0; i < size - 1; i++){
        index = i;
        value = array[i];
        for(int index = i + 1; index < size; index++){
            if (array[index] < value){
                 value = array[index];
                 index = index;
            }
        }
        array[index] = array[i];
        array[i] = value;
    }
}