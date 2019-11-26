/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on November 22, 2019, 3:34 PM
 * Purpose: Project to show concepts learned in second half of CSC-17A
 * 
 */
// system libraries

using namespace std;

// user libraries
#include "Card.h"
#include "Deck.h"


// classes
class Player{
    private:
        int chips;
        char playID;
        Card card1;
        Card card2;
        bool isFold;
        bool isOut;
        
    public:
        Player(){
            chips = 1000;
            isFold = 0;
            isOut = 0;
        }
        void setID(int i){
            playID = (i - 48);
        }
        char getID(){
            return playID;
        }
        void setCrd1(Card i){
            card1 = i;
        }
        void setCrd2(Card i){
            card2= i;
        }
        Card getCrd1(){
            return card1;
        }
        Card getCrd2(){
            return card2;
        }
        void getWins(int i){
            chips += i;
        }
        void getBet(int i){
            chips -= i;
        }
        void setFold(bool i){
            isFold = i;
        }
        void setIsOut(bool i){
            isOut = i;
        }
    
};


class Table{
    private:
        Deck deck;
        Player* playerList;
        unsigned char tabLen;
        unsigned char tabWid ;
        unsigned char** display;
    public:
        Table(){
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
        ~Table(){
            delete[] playerList;
            
            for (int i = 0; i < tabWid; ++i){
                delete [] display[i];
                
            } 
            delete [] display;
        }
        
        void shuffleDeck(){
            deck.shuffle();
        }
        void displayDeck(){
            deck.displayDeck();
        }
        
        Player getPlayer(char i){
            return playerList[i];
        }
        char getPlayerID(char i){
            return playerList[i].getID();
        }
        void startPlay(){
            //shuffleDeck();
            playerList[0].setCrd1(deck.getCard(deck.getIndex(0)));
            playerList[0].setCrd2(deck.getCard(deck.getIndex(1)));

            
        }
        void refreshDisplay(){
            for (int i = 0; i < tabLen; i++){
                
                for (int j = 0; j < tabWid; j++){
                    
                    display[j][i] = ' ' ;
                   
                }
                
            }
            
            setCardDisp(playerList[0].getID(), playerList[0].getCrd1(), playerList[0].getCrd2());
            
        }
        void setCardDisp(char p, Card c1, Card c2){
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
  
        void displayTable(){
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
        
        
};

int main(int argc, char** argv) {
    cout << " " << setw(4) << "|" << setw(3) << "|" << setw(10) << "|" << endl;
    cout << " " << setw(4) << "|" << setw(3) << "|" << setw(10) << "|" << endl;
    cout << " " << setw(4) << "|" << setw(3) << "|" << setw(10) << "|" << endl;
    cout << " " << setw(4) << "|" << "♠" << "|" << setw(10) << "|" << endl;
    cout << " " << setw(4) << "\\" << setw(1) << "9" << setw(2) << "\\" << "________" << "/" << endl;
    srand(unsigned(time(0)));
    
    Table table;
    cout <<"Display" << endl;
    table.displayDeck();
    cout << "Shuffling" << endl;
    table.shuffleDeck();
    table.displayDeck();
    
    table.refreshDisplay();
    table.displayTable();
    table.startPlay();
    table.refreshDisplay();
    table.displayTable();
   
    return 0;
}

