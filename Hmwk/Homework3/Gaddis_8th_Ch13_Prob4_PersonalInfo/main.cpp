
/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * purpose :            4. Personal Information Class
                                Design a class that holds the following personal data: name, address, age, and phone
                                number. Write appropriate accessor and mutator functions. Demonstrate the class by
                                writing a program that creates three instances of it. One instance should hold your information,
                                and the other two should hold your friends’ or family members’ information.
 *
 * Created on November 3, 2019, 3:44 PM
 */
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
// Declare class
class Person{
    private:  // Declare private variables
        int age ;
        string phoneNm, name, address;
    public: // declare public member functions
        void setInfo(int, string, string, string);
        void display();
        
};
int main(int argc, char** argv) {
    //Initialize 3 instances of person
    Person self;
    Person friend1, friend2;
    
    // set info for the 3 instances
    self.setInfo(26, "(909)555-4215" , "Edgar Magaña", "123 Fake St.");
    friend1.setInfo(68 , "(951)555-2521" , "John Goodman", "632 Field Rd.");
    friend2.setInfo(29 , "(951)555-8943" , "John Doe" , "251 5th St.");
    
    
    // have class display info
    self.display();
    friend1.display();
    friend2.display();
    
    return 0;
}
void Person::setInfo(int a , string pn, string nm , string add){ // store info
    age = a;
    phoneNm = pn;
    name = nm;
    address = add;
}

void Person::display(){ // cout info
    cout << "Name: " << name << endl
         << "Age: " << age << endl
         << "Phone Number: " << phoneNm << endl
         << "Address: " << address << endl << endl; 
    
}
