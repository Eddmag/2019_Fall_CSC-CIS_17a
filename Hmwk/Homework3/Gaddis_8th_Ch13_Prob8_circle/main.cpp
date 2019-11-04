/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 *
 * Created on November 4, 2019, 12:18 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

// Classes
class Circle{
    private:
        long radius;
        long pi = 3.14159;
        
    public:
        Circle(){
            radius = 0.0;
        }
        Circle(long rad){
            radius = rad;
        }
        void setRadius(long rad){
            radius = rad;
        }
        long getRadius(){
            return radius;
        }
        long getArea(){
            return (pi * radius * radius);
        }
        long getDiameter(){
            return radius * 2;
        }
        long getCircumference(){
            return(2 * pi * radius);
        }
};
int main(int argc, char** argv) {
    long rad;
    cout << "Input the radius of a circle: " ;
    Circle circle;
    cin >> rad;
    circle.setRadius(rad);
    
    cout << "A circle with a radius of " << circle.getRadius() << " has a diameter of " << circle.getDiameter() << ", a circumference of " << circle.getCircumference() 
        <<", and an area of " << circle.getArea() << endl;
    return 0;
}

