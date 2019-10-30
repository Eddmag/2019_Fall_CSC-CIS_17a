/* 
 * File:   main.cpp
 * Author: Edgar Magaña
 * Created on October 28, 2019, 7:59 PM
 * Purpose:
 */

// System Libraries
#include <iostream>
using namespace std;

// User Libraries

// Global Variables

struct Prime{
	unsigned short prime;
	unsigned char power;
};
struct Primes{
	unsigned char nPrimes;
	Prime *prime;
};
// Function prototypes

Primes *factor(int); // Input an integer, return all prime factors
void prntPrm(Primes *);  // Output all prime factors

int main() {
    // Declare Variables
    Primes *prime = new Primes;
    
    
    int num = 0;
    // Prompt

    // Output    
    cout << "Input an integer from 2 to 10000 to factor" << endl;
    cin >> num;

    cout <<  endl << endl;

    prime = factor(num);
  
    prntPrm(prime);
    
    delete[] prime;
    cout << "Done";
    return 0;
}

Primes *factor(int inNum){
    Primes *primeNum = new Primes;
    primeNum->prime->power = 48;
    
    int count = 0;
    int num = inNum;
    primeNum->nPrimes = 48;
    
    for (int i = 2; (i) < 5001; i++){     
        if (num % i == 0 && i != num){
        primeNum->prime[count].power = 48;
        primeNum->nPrimes++;
            while (num % i == 0 && i != num){
                primeNum->prime[count].prime = i;
                primeNum->prime[count].power ++;     
                num = num / i;      
            }
            count++;
        }                      
    }

    if (num > 1 && num != inNum && num == primeNum->prime[count - 1].prime){
        num-= num;        
        primeNum->prime[count - 1 ].power++;
                
   } 
    if (num > 1 && num != inNum ){
                primeNum->nPrimes++;
                primeNum->prime[count].prime =num;
                primeNum->prime[count].power = 49;          
    }
    return primeNum;  
}

void prntPrm(Primes *prime){
    int sum = 0;
    for (int i = 0; i < prime->nPrimes - 48 ; i++){
        for (int j = 0; j < prime->prime[j].power ; j++){  
            sum *= prime->prime[i].prime;
        }
    }
    for (int i = 0; i < prime->nPrimes - 48 ; i++){
       cout << prime->prime[i].prime << "^" << prime->prime[i].power;
       if (i < prime->nPrimes - 48 - 1  )
           cout << "*";
    }
    cout << " "; 
}