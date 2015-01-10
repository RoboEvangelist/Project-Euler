/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <iostream>

int divide_factor(int number_and_factor[]);
// Precondition: gets the number of interest, and the largest factor
// Postcondition: returns the number of interes, and the new largest factor

int main(){

    // {number, factor}
    long number_and_factor[] = {600851475143, 2};
    std::cout << std::endl << "sum of even terms under four million: "
              << std::endl << std::endl; 
}
                
//int fibonacci(int n){
//    if(n==1) 
//        return(1);
//    if(n==2) 
//        return(2);
//    return (fibonacci(n-1)+fibonacci(n-2));       // For n > 2
//}
//
//int sumEvenFibonacci(int m){
//    int sumEvenTerms = 0;         // sum of even numbers in sequence 
//    int k = 0;                    // counter to find the position
//                                  // of the nth even number
//    int fib = 0;                  // element in nth position
//    while(true){
//        fib = fibonacci(2+3*k);   // returns even term
//        if(fib > m)               // Done! No more adding.
//            return(sumEvenTerms);
//        sumEvenTerms = sumEvenTerms + fib;
//        k += 1;
//    }
//}
