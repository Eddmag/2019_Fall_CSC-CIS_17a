/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.cpp
 * Author: Eddy
 * 
 * Created on November 25, 2019, 5:15 PM
 */

#include "Deck.h"


Deck::Deck(){
    DeckSz = 52;
    index = new char[DeckSz];
    cards = new Card[DeckSz];
    for (int i = 0; i < DeckSz; i++){
            cards[i].setSuit(i / 13);
            cards[i].setVal(i % 13);
            index[i] = i;
    cDealt = 0;
    }
}
Deck::~Deck(){
    delete [] cards;
    cards = NULL;
}
void Deck::displayDeck(){

    for (int i = 0; i < DeckSz; i++){
        cout << "CARD " << i << " INDEX " << static_cast<int>(index[i]) << endl;
        cout << cards[index[i]].getSuit() + 48;
        cout << " ";
        cout << cards[index[i]].getVal() + 48;
        cout << " Int" << static_cast<int>(cards[index[i]].getVal());
        cout << endl;
    }

}
char Deck::getCardsDealt(){
    return cDealt;
}
Card Deck::DealCard(){
    cDealt++;
    return cards[getIndex(cDealt - 1)];
}
void Deck::resetCardsDealt(){
    cDealt = 0;
}
char Deck::getIndex(int i){
    return index[i];
}
void Deck::setIndex(int i, int j){
    index[i] =  j;
}
void Deck::shuffle(){
    resetCardsDealt();
    for (int i = 1 ; i <= 20 ; i++){
        for (int j = 0; j < 20 ; j++){
            unsigned char randNum = rand() % DeckSz;
            unsigned char temp = index[j];
            index[j] = index[randNum];
            index[randNum] = temp;
}
}
}
Card Deck::getCard(int i){
    return cards[i];
}