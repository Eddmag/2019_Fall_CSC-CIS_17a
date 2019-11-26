/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Card.h
 * Author: Eddy
 *
 * Created on November 25, 2019, 5:06 PM
 */

#ifndef CARD_H
#define CARD_H



class Card{
    private:
        unsigned char value;
        unsigned char suit;
        bool face;
        
    public:
        Card();
        bool isUp();
        char getVal();
        char getSuit();
        void setVal(int i);
        void setSuit(int i);
};
#endif /* CARD_H */
