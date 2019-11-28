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
#include <cstring>
class Table{
    private:
        Deck deck;
        Player* playerList;
        unsigned char tabLen;
        unsigned char tabWid ;
        unsigned char** display;
        Card* river;
        int turnCt;
        char bB[10] = {'B','i','g',' ','B','l','i','n','d' ,'\0'};
        char sB[12] = {'S','m','a','l','l',' ','B','l','i','n','d','\0'};
        char dl[7] = {'D','e','a','l','e','r','\0'};
        int pot, minBet, order;
        
        
        
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
        void charAppend(char col , char row, char c[]);
        void switchTkn();
        void setTokens();
        
};

#endif /* TABLE_H */

