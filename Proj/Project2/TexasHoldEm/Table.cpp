/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.cpp
 * Author: Eddy
 * 
 * Created on November 25, 2019, 8:39 PM
 */

#include "Table.h"

Table::Table(){
    tabWid = 80;
    tabLen = 25;
    display = new unsigned char*[tabWid];
    river = new Card[5];
    
    for (int i = 0; i < tabWid; ++i){
      display[i] = new unsigned char[tabLen];
    }

    playerList = new Player[4];
    for (int i = 0; i < 4; i++){
        playerList[i].setID(i);
    }
}
Table::~Table(){
    delete[] playerList;

    for (int i = 0; i < tabWid; ++i){
        delete [] display[i];
    } 
    delete [] display;
    
    delete [] river;
}

void Table::shuffleDeck(){
    deck.shuffle();
}
void Table::displayDeck(){
    deck.displayDeck();
}

Player Table::getPlayer(char i){
    return playerList[i];
}
char Table::getPlayerID(char i){
    return playerList[i].getID();
}
void Table::startPlay(){
    //shuffleDeck();
    playerList[0].setIsOut(1);
    playerList[1].setIsOut(1);
    playerList[2].setIsOut(1);
    playerList[3].setIsOut(1);
    DealTable();


}

void Table::DealTable(){
    if (playerList[0].getIsOut() != 0){
    playerList[0].setCrd1(deck.DealCard());
    }
    if (playerList[1].getIsOut() != 0){
    playerList[1].setCrd1(deck.DealCard());
    }
    if (playerList[2].getIsOut() != 0){
    playerList[2].setCrd1(deck.DealCard());
    }
    if (playerList[3].getIsOut() != 0){
    playerList[3].setCrd1(deck.DealCard());
    }
    if (playerList[0].getIsOut() != 0){
    playerList[0].setCrd2(deck.DealCard());
    }
    if (playerList[1].getIsOut() != 0){
    playerList[1].setCrd2(deck.DealCard());
    }
    if (playerList[2].getIsOut() != 0){
    playerList[2].setCrd2(deck.DealCard());
    }
    if (playerList[3].getIsOut() != 0){
    playerList[3].setCrd2(deck.DealCard());
    }
    
    for (int i = 0; i < 5; i++){
        river[i] = deck.DealCard();
    }
}
void Table::setDisplay(){
    for (int i = 0; i < tabLen; i++){
        for (int j = 0; j < tabWid; j++){
            display[j][i] = ' ' ;
        }
    }
    setPlayerDisplay(playerList[0].getID(), playerList[0].getCrd1(), playerList[0].getCrd2());
    if (playerList[1].getIsOut() != 0){
        setFoeDisplay(playerList[1]);
    }
    if (playerList[2].getIsOut() != 0){
    setFoeDisplay(playerList[2]);
    }
    if (playerList[3].getIsOut() != 0){
    setFoeDisplay(playerList[3]);
    }
    setRiverDisplay();
}
void Table::setRiverDisplay(){
    for(int k = 0; k < 5;k++){
        int mul = 12 * k;
        
        for (int i = 10; i < 15; i++ ){
            display[12+mul][i] = '|';
        }
        for (int i = 10; i < 15; i++ ){
            display[18+mul][i] = '|';
        }
        for (int j = 13 + mul; j < 18 + mul; j ++){
                display[j][9] = '_';

        }
        for (int j = 13 + mul; j < 18 + mul ; j ++){
                display[j][15] = '-';

            }
        if(river[k].isUp()== false){
            for (int i = 10 ; i < 15 ; i++ ){
                for (int j = 13 + mul; j < 18+ mul; j++){
                    display[j][i] = '0';
                }
            }
        }
        if(river[k].isUp()== true){
            for (int i = 10 ; i < 15 ; i++ ){
                for (int j = 13 + mul; j < 18+ mul; j++){
                    display[j][i] = ' ';
                }
            }
        }
        display[13 + mul][14] = river[k].getVal()+ 49;
    }
}
void Table::setFoeDisplay(Player a ){
    int mul = 0;
    if (a.getID() == 2 ){
        mul = 30 ;
    }
    if (a.getID() == 3 ){
        mul = 58 ; 
    }
    
    // Card 1
    for (int i = 1; i < 6; i++ ){
        display[2+mul][i] = '|';
    }
    for (int i = 1; i < 6; i++ ){
        display[8+mul][i] = '|';
    }
    for (int j = 3+mul; j < 8 + mul; j ++){
            display[j][0] = '_';

    }
    for (int j = 3+ mul; j < 8 + mul; j ++){
            display[j][6] = '-';

        }
    if(a.getCrd1().isUp()== false){
        for (int i = 1; i < 6 ; i++ ){
            for (int j = 3+ mul; j < 8 + mul; j++){
                display[j][i] = '0';
            }
        }
    }
    if(a.getCrd1().isUp()== true){
        for (int i = 1; i < 6 ; i++ ){
            for (int j = 3+ mul; j < 8 + mul; j++){
                display[j][i] = ' ';
            }
        }
    }
    //card 2
    for (int i = 1; i < 6; i++ ){
        display[11+mul][i] = '|';
    }
    for (int i = 1; i < 6; i++ ){
        display[17+mul][i] = '|';
    }
    for (int j = 12+mul; j < 17 + mul; j ++){
            display[j][0] = '_';
    }
    for (int j = 12+mul; j < 17 + mul; j ++){
            display[j][6] = '-';
        }
    
    if(a.getCrd2().isUp()== false){
        for (int i = 1; i < 6; i++ ){
            for (int j = 12 + mul; j < 17 + mul; j ++){
                display[j][i] = '0';

            }
        }
    }
    
}

void Table::setPlayerDisplay(char p, Card c1, Card c2){
    char suit1= c1.getSuit();
    char suit2= c2.getSuit();
    // Card 1   
    for (int i = 18; i < 23; i++ ){
        display[39][i] = '|';
    }
    for (int i = 18; i < 23; i++ ){
        display[45][i] = '|';
    }
    for (int j = 40; j < 45; j ++){
            display[j][17] = '_';

    }
    for (int j = 40; j < 45; j ++){
            display[j][23] = '-';

        }
    for (int i = 18; i < 23; i++ ){
        for (int j = 40; j < 45; j ++){
            display[j][i] = ' ';

        }
    }
    display[40][22] = c1.getVal();
    display[44][18] = c1.getVal();

    switch(suit1){
        case 0:
            display[44][19] = 'S';
            display[40][21] = 'S';
            break;
        case 1:
            display[44][19] = 'H';
            display[40][21] = 'H';
            break;
        case 2:
            display[44][19] = 'C';
            display[40][21] = 'C';
            break;
        case 3:
            display[44][19] = 'D';
            display[40][21] = 'D';
            break;
    }


    // Card 2
    for (int i = 18; i < 23; i++ ){
        display[48][i] = '|';
    }
    for (int i = 18; i < 23; i++ ){
        display[54][i] = '|';
    }
    for (int j = 49; j < 54; j ++){
            display[j][17] = '_';

    }
    for (int j = 49; j < 54; j ++){
            display[j][23] = '-';

        }
    for (int i = 18; i < 23; i++ ){
        for (int j = 49; j < 54; j ++){
            display[j][i] = ' ';

        }

    }
    // set card values
    display[49][22] = c2.getVal();
    display[53][18] = c2.getVal();

    // set card suit

    switch(suit2){
        case 0:
            display[49][21] = 'S';
            display[53][19] = 'S';
            break;
        case 1:
            display[49][21] = 'H';
            display[53][19] = 'H';
            break;
        case 2:
            display[49][21] = 'C';
            display[53][19] = 'C';
            break;
        case 3:
            display[49][21] = 'D';
            display[53][19] = 'D';
            break;
    }

}

void Table::displayTable(){
    cout << " --------------------------------------------------------------------------------" << endl;
    cout << '|' << "                        Edgar's Texas Hold'Em                                   |" << endl;
    cout << " --------------------------------------------------------------------------------" << endl;


    for (int i = 0; i < tabLen; i++){
        cout << "|";
        for (int j = 0; j < tabWid; j++){

            cout << display[j][i] ;

        }

        cout << "|" << endl;
    }

    cout << " --------------------------------------------------------------------------------" << endl;
    //cout << playerList[0].getCrd1().getVal() << endl;
    //cout << playerList[0].getCrd2().getVal() << endl;
    //cout << static_cast<int>(playerList[0].getCrd1().getVal()) << " " << static_cast<int>(playerList[0].getCrd2().getVal()); 
}