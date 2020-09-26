#include <bits/stdc++.h> 
using namespace std; 
int prime[1000000]; 
/*
Name: Ikechukwu Vincent Unegbu
Phone: 08064133376
Email: mr.ikunegbu@gmail.com 
Education: Physics B.Sc. (in view)
Skills: Proficient in PHP, taking C++ course for Scientific Computing and other uses 
Interests: Mathematical Modelling, Cryptography
*/
  
// Calculating primes up to n usine Seive of Eratosthenes Algorithm
void Sieve(int n) 
{ 
     
    for (int i = 1; i <= n + 1; i++) 
        prime[i] = true; 
  
    prime[1] = false; 
  
    for (int p = 2; p * p <= n; p++) { 
  
        // if a number p is not changed, then that number is a prime
        if (prime[p] == true) { 
  
            // Move to all multiples of p greater than or equal to the square of it, numbers 
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
} 
  
//a helper function checking for power of two 
bool checkPower2(int a) 
{ 
    return (a && !(a & (a - 1))); 
} 
  
//this function will check if a randomly given number is a proth number or not
bool ifProth(int n) 
{ 
  
    int k = 1; 
    while (k < (n / k)) { 
  
        
        if (n % k == 0) { 
  
           
            if (checkPower2(n / k)) 
                return true; 
        } 
  
        
        k = k + 2; 
    } 
    
    return false; 
} 
  /*
  | NOW THIS IS THE REAL DEAL! THIS FUNCTION USES EVERYTHING DONE SO FAR TO 
  |	TELL IF THE NUMBER GIVEN IS A PROTH PRIME. 
  | THIS IS THE FUNCTION THAT CHECKS WHETHER THE NUMBER SATISFIES PROTH THEOREM
  */

bool IfProth_Prime(int n) 
{ 
    // Check n for Proth Number 
    if (ifProth(n - 1)) { 
  
        // if number is prime, return true 
        if (prime[n]) 
            return true; 
        else
            return false; 
    } 
    else
        return false; 
} 
  
// code to test if our function and everything done so far is working or not.
//YOu can test the code by randomly changing the value of n below 
int main() 
{ 
    int n = 193; 
  		
  	// if number is proth number, calculate primes upto n 
    Sieve(n); 
    
        // Check n for Proth Prime: by checking if n is in the array of numbers calculated upto n 
        if (IfProth_Prime(n)==true) 
            cout << "This is a proth prime." << endl; 
           else
           cout << "Sorry this is not a proth number. Consider using Proth formula to generate your proth numbers." << endl; 
           
  
    return 0; 
} 


