/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Purpose: 3. Car Class
                    Write a class named Car that has the following member variables:
                    • yearModel . An int that holds the car’s year model.
                    • make . A string that holds the make of the car.
                    • speed . An int that holds the car’s current speed.
                   
                    In addition, the class should have the following constructor and other member functions.
                    • Constructor. The constructor should accept the car’s year model and make as arguments.
                    These values should be assigned to the object’s yearModel and make member
                    variables. The constructor should also assign 0 to the speed member variables.
                    • Accessor. Appropriate accessor functions to get the values stored in an object’s
                    yearModel , make , and speed member variables.
                    • accelerate . The accelerate function should add 5 to the speed member variable
                    each time it is called.
                    • brake . The brake function should subtract 5 from the speed member variable each
                    time it is called.
                    Demonstrate the class in a program that creates a Car object, and then calls the
                    accelerate function five times. After each call to the accelerate function, get
                    the current speed of the car and display it. Then, call the brake function five times.
                    After each call to the brake function, get the current speed of the car and display it.
 *
 * Created on November 3, 2019, 4:20 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

// Classes
class Car{
    private:
        int yearModel, speed;
        string make;
    public:
        Car(string mk, int mkYr);
        int getYear(){
            return yearModel;
        };
        int getSpeed(){
            return speed;
        }
        string getMake(){
            return make;
        }
        void accelerate();
        void brake();
};

int main(int argc, char** argv) {
    // Initialize Car class
    Car prius("Toyota", 2015);
    //display car state
    cout << "The " << prius.getYear() << " " << prius.getMake() << " is sitting at " << prius.getSpeed() << " MPH!" << endl;
    
    for (int i = 0; i < 5; i++){ // Accelerate loop
        prius.accelerate();
         cout << "The " << prius.getYear() << " " << prius.getMake() << " has accelerated to " << prius.getSpeed() << " MPH!" << endl;
    }
     for (int i = 0; i < 5; i++){ // Brake loop
        prius.brake();
         cout << "The " << prius.getYear() << " " << prius.getMake() << " has decelerated to " << prius.getSpeed() << " MPH!" << endl;
    }
    return 0;
}

Car::Car(string mk, int mkYr){ // constructor for Car class 
    speed = 0;
    make = mk;
    yearModel = mkYr;
}
void Car::accelerate(){ // add 5 to speed 
    speed += 5;
}
void Car::brake(){  // subtract 5 to speed
    speed -= 5;
}