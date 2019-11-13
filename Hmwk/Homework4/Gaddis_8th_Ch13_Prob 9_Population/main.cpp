/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on November 12, 2019, 11:08 PM
 * Purpose:     9. Population
                        In a population, the birth rate and death rate are calculated as follows:
                        Birth Rate = Number of Births ÷ Population
                        Death Rate = Number of Deaths ÷ Population
                        For example, in a population of 100,000 that has 8,000 births and 6,000 deaths per
                        year, the birth rate and death rate are:
                        Birth Rate = 8,000 ÷ 100,000 = 0.08
                        Death Rate = 6,000 ÷ 100,000 = 0.06
                        Design a Population class that stores a population, number of births, and number of
                        deaths for a period of time. Member functions should return the birth rate and death
                        rate. Implement the class in a program.
                        Input Validation: Do not accept population figures less than 1, or birth or death numbers
                        less than 0.
 * 
 */
// system libraries
#include <iostream>
#include <iomanip>
using namespace std;

// user libraries

// classes
class Population{
    private:
        int population;
        int births;
        int deaths;
        float bRate;
        float dRate;
    public:
        void setPopulation(int i){
            population = i;
        }
        void setBirths(int i){
            births = i;
        }
        void setDeaths(int i){
            deaths = i;
        }
        float getBirthRate(){
            bRate = (static_cast<float>(births) / static_cast<float>(population));
            
            return bRate;
        }
        float getDeathRate(){
            dRate = (static_cast<float>(deaths) / static_cast<float>(population));
            
            return dRate;
        }
};

bool validate(int i);

int main(int argc, char** argv) {
    Population pop;
    int i = 0;
    cout << "Let's calculate the birth and death rate of a population!" << endl
         << "What is the size of the population?" << endl ;
    cin >> i;
    
    while (validate(i) == false){
        cout << "Can not be a negative value. try again!" << endl;
        cin >> i;
    };
    
    pop.setPopulation(i);
    
    cout << "What is the amount of births this year?" << endl;
    cin >> i;
    
    while (validate(i) == false){
        cout << "Can not be a negative value. try again!" << endl;
        cin >> i;
    };

    pop.setBirths(i);
    
    cout << "What is the amount of deaths this year?" << endl;
    cin >> i;
    
    while (validate(i) == false){
        cout << "Can not be a negative value. try again!" << endl;
        cin >> i;
    };

    pop.setDeaths(i);
    
    cout << "The current birthrate is : " << setprecision(5) << pop.getBirthRate() << endl;
    cout << "The current deathrate is : " << pop.getDeathRate() << endl;
    
    return 0;
}

bool validate(int i){
    if (i > 0){
        return true;
    } else return false;
}