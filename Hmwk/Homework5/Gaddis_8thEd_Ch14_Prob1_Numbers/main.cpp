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
        int number;
        int numSize;
        string * al;
    public:
        Numbers(int i){
            number = i;
        }
        void print(){
            for (int i = 0 ; i < numSize ; i++){
                cout << al[i];
            }
            cout << endl;
        }
};
int main(int argc, char** argv) {

    return 0;
}

