
/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 *
 * Created on November 12, 2019, 9:46 PM
 * Purpose:     6. Inventory Class
                        Design an Inventory class that can hold information and calculate data for items in a
                        retail store’s inventory. The class should have the following private member variables:
                        Variable Name Description
                        itemNumber An int that holds the item’s item number.
                        quantity An int for holding the quantity of the items on hand.
                        cost A double for holding the wholesale per-unit cost of the item
                        totalCost A double for holding the total inventory cost of the item (calculated
                        as quantity times cost ).
                        The class should have the following public member functions:
                        Member Function Description
                        Default Constructor Sets all the member variables to 0.
                        Constructor #2 Accepts an item’s number, cost, and quantity as arguments.
                        The function should copy these values to the appropriate
                        member variables and then call the setTotalCost function.
                        setItemNumber Accepts an integer argument that is copied to the
                        itemNumber member variable.
                        setQuantity Accepts an integer argument that is copied to the quantity
                        member variable.
                        setCost Accepts a double argument that is copied to the cost
                        member variable.
                        setTotalCost Calculates the total inventory cost for the item ( quantity
                        times cost ) and stores the result in totalCost .
                        getItemNumber Returns the value in itemNumber .
                        getQuantity Returns the value in quantity .
                        getCost Returns the value in cost .
                        getTotalCost Returns the value in totalCost .
                        Demonstrate the class in a driver program.
                        Input Validation: Do not accept negative values for item number, quantity, or cost.
 */

#include <cstdlib>
#include <iostream>
using namespace std;



//  classes

class Inventory{
    private:
        int itemNumber;
        int quantity;
        float cost;
        float totalCost;
        
    public:
        void setTotalCost(){
            totalCost = cost * quantity;
        };
        void setItemNumber(int num){
            itemNumber = num;
        };
        void setQuantity(int qua){
            quantity = qua;
        };
        void setCost(float c){
            cost = c;
        };
        int getItemNumber(){
            return itemNumber;
        };
        int getQuantity(){
            return quantity;
        };
        float getCost(){
            return cost;
        };
        float getTotalCost(){
            return totalCost;
        };
        Inventory(){
            itemNumber = 0;
            quantity = 0;
            cost = 0.0;
            totalCost = 0.0;
        }
        Inventory(int num, int quan, float c){
            itemNumber = num;
            quantity = quan;
            cost = c;
            setTotalCost();
        }
        
    
};

// functions
bool validate(int i);
bool validate(float i);

int main(int argc, char** argv) {
    int iN, q , c;
    
    cout << "Let's calculate the total value of an item in your inventory." << endl;
    Inventory item;
    cout << "What is the item number?" << endl;
    cin >> iN;
    while (validate(iN) == false){
        cout << "Can not be a negative value. try again!" << endl;
        cin >> iN;
    };
    item.setItemNumber(iN);
    cout << "How many of item #" << item.getItemNumber() << " do you have?" << endl;
    cin >> q;
    while (validate(q) == false){
        cout << "Can not be a negative value. try again!" << endl;
        cin >> q;
    };
    item.setQuantity(q);
    cout << "What is the cost of item #" << item.getItemNumber() << "?" << endl;
    cin >> c;
    while (validate(c) == false){
        cout << "Can not be a negative value. try again!" << endl;
        cin >> c;
    };
    item.setCost(c);
    item.setTotalCost();
    
    cout << "The total cost for item #" << item.getItemNumber() << " is : $" << item.getTotalCost() << endl;
    Inventory tItem(525, 20 ,3.25);
    
   
    cout << endl << "There are also currently " << tItem.getQuantity() << " of Item # " << tItem.getItemNumber()<< " in stock. They cost " << tItem.getCost() 
         << " individually for a total of " << tItem.getTotalCost() << endl;
    
    return 0;
}
bool validate(int i){
    if (i > 0){
        return true;
    } else return false;
}
bool validate(float i){
    if (i > 0.0){
        return true;
    } else return false;
}