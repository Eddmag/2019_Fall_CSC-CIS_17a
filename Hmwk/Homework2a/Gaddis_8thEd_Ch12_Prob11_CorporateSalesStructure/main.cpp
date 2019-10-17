/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Edgar Magaña 
 *
 * Created on October 16, 2019, 6:38 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;



struct sales{
    
    char divName[10];
    int qtrSale[];
    
};
int main(int argc, char** argv) {
    sales north;
    sales south;
    sales east;
    sales west;
    
    for(int i = 0; i < 4; i++){
         
        
        for (int j = 0; j < 4; j++){
            cout  << "What are the sales figure for Quarter "  << (j + 1) << " of " ;
            if ( i == 0){
                cout << "North";
            }
            if ( i == 1){
                cout << "South";
            }
            if ( i == 2){
                cout << "East";
            }
            if ( i == 3){
                cout << "West";
            }
            cout << " division?" << endl;
            
            if ( i == 0){
                cin >> north.qtrSale[j] ;
            }
            if ( i == 1){
                cin >> south.qtrSale[j] ;
            }
            if ( i == 2){
                cin >> east.qtrSale[j] ;
            }
            if ( i == 3){
                cin >> west.qtrSale[j] ;
            }
            cout << north.qtrSale[j];
        }
    }
    
    
    return 0;
}

