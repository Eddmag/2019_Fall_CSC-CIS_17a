/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on November 22, 2019, 3:34 PM
 * Purpose: Project to show concepts learned in second half of CSC-17A
 * 
 */
// system libraries

using namespace std;

// user libraries
#include "Table.h"

// classes
int main(int argc, char** argv) {
    cout << " " << setw(4) << "|" << setw(3) << "|" << setw(10) << "|" << endl;
    cout << " " << setw(4) << "|" << setw(3) << "|" << setw(10) << "|" << endl;
    cout << " " << setw(4) << "|" << setw(3) << "|" << setw(10) << "|" << endl;
    cout << " " << setw(4) << "|" << "♠" << "|" << setw(10) << "|" << endl;
    cout << " " << setw(4) << "\\" << setw(1) << "9" << setw(2) << "\\" << "________" << "/" << endl;
    srand(unsigned(time(0)));
    
    Table table;
    cout <<"Display" << endl;
    table.displayDeck();
    cout << "Shuffling" << endl;
    table.shuffleDeck();
    table.displayDeck();
    
    table.startPlay();
    
    
   
    return 0;
}

