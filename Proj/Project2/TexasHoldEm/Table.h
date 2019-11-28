/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.h
 * Author: Eddy
 *
 * Created on November 25, 2019, 8:39 PM
 */

#ifndef TABLE_H
#define TABLE_H
#include "Player.h"
class Table{
    private:
        Deck deck;
        Player* playerList;
        unsigned char tabLen;
        unsigned char tabWid ;
        unsigned char** display;
        Card* river;
        int turn;
        
    public:
        Table();
        ~Table();
        
        void DealTable();
        void shuffleDeck();
        void displayDeck();
        Player getPlayer(char i);
        char getPlayerID(char i);
        void startPlay();
        void setDisplay();
        void displayTable();
        void setRiverDisplay();
        void setPlayerDisplay(char p, Card c1, Card c2);
        void setFoeDisplay(Player a);
        void checkRank();
        void setGeneralInfo();
        void intAppend(char, char, int);
        
};

#endif /* TABLE_H */

