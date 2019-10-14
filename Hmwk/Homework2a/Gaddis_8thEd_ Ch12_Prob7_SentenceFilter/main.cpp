/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on October 12, 2019, 9:51 PM
 * Purpose: Filter sentences from a file and output to another file.
 */

// System Libraries
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// User Libraries

// Global Variables

// Function prototypes

int main() {
    
    // Declare Variables
    const int SIZE = 50; 
    int lineLen = 0;
    string txtLine;
    char inName[SIZE], outName[SIZE];
    
    // Prompt
    cout << "What is the name of the input file?" << endl;
    cin >> inName;
    cout << "what is the name of the output file" << endl;
    cin >> outName;
    
    // Open Files
    fstream inFile, outFile;
    inFile.open(inName, fstream::in);
    outFile.open(outName, fstream::out);
    
    // Filter Sentences
    while(getline(inFile, txtLine)){
        
        lineLen = txtLine.length();
        
        if(txtLine[0] >= 97 && txtLine[0] <= 122){
            txtLine[0] -= 32;
        }
        for (int i = 1 ; i < lineLen ; i++){
            
        if(txtLine[i] >= 65 && txtLine[i] <= 90){
            txtLine[i] += 32;
        }
        }
        outFile << txtLine << endl;
        
    };
    // Output    
    
    // Close Files
    inFile.close();
    outFile.close();
    
    // Returns
    return 0;
}

