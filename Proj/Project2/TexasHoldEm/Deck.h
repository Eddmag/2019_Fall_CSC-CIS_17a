/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.h
 * Author: Eddy
 *
 * Created on November 25, 2019, 5:15 PM
 */

#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>

using namespace std;

class Deck{
    private:
        Card* cards;
        char DeckSz;
        char* index;
        char cDealt;
        
    public:
        Deck();
        ~Deck();
        void displayDeck();
        char getIndex(int i);
        void setIndex(int i, int j);
        void shuffle();
        Card getCard(int i);
        void resetCardsDealt();
        char getCardsDealt();
        Card DealCard();
};
#endif /* DECK_H */
