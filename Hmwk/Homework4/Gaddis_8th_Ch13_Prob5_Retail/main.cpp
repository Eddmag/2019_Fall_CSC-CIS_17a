
/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on November 9, 2019, 3:22 PM
 * Purpose:     5. RetailItem Class
                    Write a class named RetailItem that holds data about an item in a retail store. The
                    class should have the following member variables:
                    • description . A string that holds a brief description of the item.
                    • unitsOnHand . An int that holds the number of units currently in inventory.
                    • price . A double that holds the item’s retail price.
                    Write a constructor that accepts arguments for each member variable, appropriate
                    mutator functions that store values in these member variables, and accessor functions
                    that return the values in these member variables. Once you have written the class, write
                    a separate program that creates three RetailItem objects and stores the following data
                    in them.
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Classes

class RetailItem{
private:
    string description;
    int unitsOnHand = 0;
    float price = 0.0;
public:
    RetailItem(string desc, int units , float p){
        description = desc;
        unitsOnHand = units;
        price = p;
    }
    string getDesc(){
        return description;
    }
    float getPrice(){
        return price;
    }
    int getUnits(){
        return unitsOnHand;
    }
};

int main(int argc, char** argv) {
    RetailItem jacket("Jacket" , 12 , 59.95);
    RetailItem jeans("Designer Jeans" , 40 , 34.95);
    RetailItem shirt("Shirt" , 20 , 24.95);
    
    cout << " " << setw(20) << "Description" << setw(20) << "Units" << setw(20) << "Price" << endl;
    cout << "Item #1"  << setw(20) << jacket.getDesc() << setw(20) << jacket.getUnits() << setw(20) << "$" << jacket.getPrice()<< endl;
    cout << "Item #2"  << setw(20) << jeans.getDesc() << setw(20) << jeans.getUnits() << setw(20) << "$" << jeans.getPrice() << endl;
    cout << "Item #3"  << setw(20) << shirt.getDesc() << setw(20) << shirt.getUnits() << setw(20) << "$" << shirt.getPrice() << endl;
    return 0;
}

