/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on November 13, 2019, 2:27 PM
 * Purpose:     1. Numbers Class
                        Design a class Numbers that can be used to translate whole dollar amounts in the range
                        0 through 9999 into an English description of the number. For example, the number
                        713 would be translated into the string seven hundred thirteen , and 8203 would be
                        translated into eight thousand two hundred three . The class should have a single integer
                        member variable:
                        int number;
                        and a static array of string objects that specify how to translate key dollar amounts
                        into the desired format. For example, you might use static strings such as
                        string lessThan20[20] = {"zero", "one", ..., "eighteen", "nineteen"};
                        string hundred = "hundred";
                        string thousand = "thousand";
                        The class should have a constructor that accepts a nonnegative integer and uses it to
                        initialize the Numbers object. It should have a member function print() that prints
                        the English description of the Numbers object. Demonstrate the class by writing a main
                        program that asks the user to enter a number in the proper range and then prints out
                        its English description.
 */

#include <iostream>
#include <string>
using namespace std;

// Classes

class Numbers{
    private:
        int numSize = 0;
        int number = 0;
        
        
        string *al = new string[4];
    public:
        Numbers(int i){
            number = i;
            numSize = setSize();
            setAlphabetic(al);
            print();
            delStr();
        }
        void print();
        int setSize();
        string *setAlphabetic( string *);
        void delStr(){
            delete al;
        }
};
int main(int argc, char** argv) {
    int i;
    
    do{
    cout << "Input a number between 0 and 9999 and I will write it out alphabetically" << endl;
        cin >> i ;
        if (i < 0 || i > 9999 ){
            cout << "Not a valid number! Try Again" << endl;
        }
    } while (i < 0 || i > 9999 );
    Numbers num(i);
    
    return 0;
}

int Numbers::setSize(){
    
    if (number > 1000){
        return 4;
    } else if (number > 100){
            return 3;
        } else if (number > 10){
                return 2;
            } else if (number > 1){
                    return 1;
                }
}

string* Numbers::setAlphabetic(string *alpha){
    
    int thous = 0, huns = 0, tens = 0, ones = 0; 
    
    if (numSize == 4){
        while (number - 1000 >= 0){
            number -= 1000;
            thous ++;
        }
    }
    if (numSize >= 3){
        while (number - 100 >= 0){
            number -= 100;
            huns ++;
        }
    }
    if (numSize >= 2){
        if (number >= 20){
            
            while (number - 10 >= 0){
                number -= 10;
                tens ++;
            }
        }
    }
    if (numSize >= 1){
        while (number - 1 >= 0){
            number -= 1;
            ones ++;
        }
    }
    switch (thous){
        case 1: alpha[0] = "One";
            break;
        case 2: alpha[0] = "Two";
            break;
        case 3: alpha[0] = "Three";
            break;
        case 4: alpha[0] = "Four";
            break;
        case 5: alpha[0] = "Five";
            break;
        case 6: alpha[0] = "Six";
            break;
        case 7: alpha[0] = "Seven";
            break;
        case 8: alpha[0] = "Eight";
            break;
        case 9: alpha[0] = "Nine";
            break;
        
        default: break; 
        
    }
    switch (huns){
        case 1: alpha[1] = "One";
            break;
        case 2: alpha[1] = "Two";
            break;
        case 3: alpha[1] = "Three";
            break;
        case 4: alpha[1] = "Four";
            break;
        case 5: alpha[1] = "Five";
            break;
        case 6: alpha[1] = "Six";
            break;
        case 7: alpha[1] = "Seven";
            break;
        case 8: alpha[1] = "Eight";
            break;
        case 9: alpha[1] = "Nine";
            break;
        
        default: break; 
        
    }
    switch (tens){
        case 1: 
            break;
        case 2: alpha[2] = "Twenty";
            break;
        case 3: alpha[2] = "Thirty";
            break;
        case 4: alpha[2] = "Fourty";
            break;
        case 5: alpha[2] = "Fifty";
            break;
        case 6: alpha[2] = "Sixty";
            break;
        case 7: alpha[2] = "Seventy";
            break;
        case 8: alpha[2] = "Eighty";
            break;
        case 9: alpha[2] = "Ninety";
            break;
        
        default: break; 
        
    }
    switch (ones){
        case 0 : alpha[3] = "Zero";
            break;
        case 1 : alpha[3] = "One";
            break;
        case 2: alpha[3] = "Two";
            break;
        case 3: alpha[3] = "Three";
            break;
        case 4: alpha[3] = "Four";
            break;
        case 5: alpha[3] = "Five";
            break;
        case 6: alpha[3] = "Six";
            break;
        case 7: alpha[3] = "Seven";
            break;
        case 8: alpha[3] = "Eight";
            break;
        case 9: alpha[3] = "Nine";
            break;
        case 10 : alpha [3] = "Ten";
            break;
        case 11 : alpha [3] = "Eleven";
            break;
        case 12 : alpha [3] = "Twelve";
            break;
        case 13 : alpha [3] = "Thirteen";
            break;
        case 14 : alpha [3] = "Fourteen";
            break;
        case 15 : alpha [3] = "Fifteen";
            break;
        case 16 : alpha [3] = "Sixteen";
            break;
        case 17 : alpha [3] = "Seventeen";
            break;
        case 18 : alpha [3] = "Eighteen";
            break;
        case 19 : alpha [3] = "Nineteen";
            break;
            
        default: break; 
        
    }
   
    
    return alpha;
}
void Numbers::print(){
    if (numSize == 4){
        cout << al[0] << " thousand "; 
    }  
    if (numSize >= 3){
        cout << al[1] << " hundred ";
    } 
    if (numSize >= 2){
        cout << al[2] << " ";
    } 
    if (numSize >= 1){
        cout << al[3] << endl;
    }
}