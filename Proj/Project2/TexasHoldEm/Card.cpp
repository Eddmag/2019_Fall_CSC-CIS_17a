/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Card.cpp
 * Author: Eddy
 * 
 * Created on November 25, 2019, 5:06 PM
 */

#include "Card.h"

char Card::getVal(){
            return value;
}
char Card::getSuit(){
            return suit;
}
        
void Card::setVal(int i){
            i -= 48;
            value = i;
}
void Card::setSuit(int i){
            i -= 48;
            suit = i;
}