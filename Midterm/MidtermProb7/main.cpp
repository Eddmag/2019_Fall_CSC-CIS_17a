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
    prime->nPrimes = 48;
    
    Primes tprime;
    tprime.nPrimes = 50;
    
    tprime.prime = new Prime[5];
    tprime.prime[0].prime = 5;
    tprime.prime[0].power = 2 + 48;
    tprime.prime[1].prime = 3;
    tprime.prime[1].power = 9 + 48;
    
    // Prompt

    // Output    
    prntPrm(&tprime);
    cout << endl << endl;;
    prime = factor(8);
    prntPrm(prime);
    
    
    delete tprime.prime;
    return 0;
}

Primes *factor(int num){
    Primes *primeNum = new Primes;
    int count = 0;
    
   
    for (int i = 2; i < 10; i++){
        while (num % i == 0 && num >= 0){
            cout << num << endl;

                num /= i;
                primeNum->nPrimes++;
                primeNum->prime[count].prime = i;
                primeNum->prime[count].power ++;

        }
        count++;
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