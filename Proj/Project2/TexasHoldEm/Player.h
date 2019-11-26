/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Eddy
 *
 * Created on November 25, 2019, 8:32 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
class Player{
    private:
        int chips;
        char playID;
        Card card1;
        Card card2;
        bool isFold;
        bool isOut;
        char token;
        
    public:
        Player();
        void setID(int i);
        char getID();
        void setCrd1(Card i);
        void setCrd2(Card i);
        Card getCrd1();
        Card getCrd2();
        void getWins(int i);
        void getBet(int i);
        void setFold(bool i);
        void setIsOut(bool i);
        bool getIsOut();
    
};

#endif /* PLAYER_H */
