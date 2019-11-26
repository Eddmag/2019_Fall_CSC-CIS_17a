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
}
void Player::setID(int i){
    playID = (i - 48);
}
char Player::getID(){
    return playID;
}
void Player::setCrd1(Card i){
    card1 = i;
}
void Player::setCrd2(Card i){
    card2= i;
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
void Player::setFold(bool i){
    isFold = i;
}
void Player::setIsOut(bool i){
    isOut = i;
}
