/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: Eddy
 * 
 * Created on November 25, 2019, 8:32 PM
 */

#include "Player.h"


Player::Player(){
    chips = 1000;
    isFold = 0;
    isOut = 0;
    token = 0;
    
}
void Player::setID(int i){
    playID = (i);
}
char Player::getID(){
    return playID;
}
void Player::setCrd1(Card i){ 
    card1 = i;
    card1.setVal(card1.getVal()+49);
    
    if (static_cast<int>(card1.getVal()) == 58){
            card1.setVal(84);
        }else if (static_cast<int>(card1.getVal()) == 59){
                card1.setVal(74);
            }else if (static_cast<int>(card1.getVal()) == 60){
                    card1.setVal(81);
                }else if (static_cast<int>(card1.getVal()) == 61){
                    card1.setVal(75);
                    };
}
void Player::setCrd2(Card i){
    card2 = i;
    card2.setVal(card2.getVal()+49);
    
    if (static_cast<int>(card2.getVal()) == 58){
            card2.setVal(84);
        }else if (static_cast<int>(card2.getVal()) == 59){
                card2.setVal(74);
            }else if (static_cast<int>(card2.getVal()) == 60){
                    card2.setVal(81);
                }else if (static_cast<int>(card2.getVal()) == 61){
                    card2.setVal(75);
                    };
}
Card Player::getCrd1(){
    return card1;
}
Card Player::getCrd2(){
    return card2;
}
void Player::getWins(int i){
    chips += i;
}
void Player::getBet(int i){
    chips -= i;
}
int Player::getBet(){
    int tChips = chips;

    switch(token){
        case 1:
            if (chips >= 100){
            chips -= 100;
            return 100;
            } else if (chips > 0){
                chips = 0;
                return tChips;

            }
            break;
        case 2:
            if (chips >= 200){
            chips -= 200;
            return 200;
            }else if (chips > 0){
                chips = 0;
                return tChips;
            }
            break;
        default:
            return 0;
            break;
    }
}
void Player::setFold(bool i){
    isFold = i;
}
void Player::setIsOut(bool i){
    isOut = i;
}
bool Player::getIsOut(){
    return isOut;
}
void Player::setTkn(char c){
    token = c;
};
char Player::getTkn(){
    return token;
};
void Player::rotateTkn(){
    token++;
    if (token > 3){
        token = 0;
    }
}
int Player::getChips(){
    return chips;
}