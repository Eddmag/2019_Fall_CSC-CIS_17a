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
    playerList[0].setCrd1(deck.getCard(deck.getIndex(0)));
    playerList[0].setCrd2(deck.getCard(deck.getIndex(1)));


}
void Table::refreshDisplay(){
    for (int i = 0; i < tabLen; i++){

        for (int j = 0; j < tabWid; j++){

            display[j][i] = ' ' ;

        }

    }

    setCardDisp(playerList[0].getID(), playerList[0].getCrd1(), playerList[0].getCrd2());

}
void Table::setCardDisp(char p, Card c1, Card c2){
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
    display[40][22] = c1.getVal() +49;
    display[44][18] = c1.getVal() +49;

    switch(suit1){
        case 0:
            display[44][19] = 'S';
            display[40][21] = 'S';
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
    display[49][22] = c2.getVal() + 49;
    display[53][18] = c2.getVal() + 49;

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
    cout << playerList[0].getCrd1().getVal()+49 << endl;
    cout << playerList[0].getCrd2().getVal()+49;
}