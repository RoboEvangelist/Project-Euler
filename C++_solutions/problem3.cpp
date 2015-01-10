/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <iostream>

//long divide_factor(long number_and_factor[]);
int divide_factor(int number, int factor);
// Precondition: gets the number of interest, and the largest factor
// Postcondition: returns the number of interes, and the new largest factor

int main(){

    // {number, factor}
    long number = 600851475143;    // number to get factors from
    int first_factor = 2;                // max initial factor
//    long number_and_factor[] = {600851475143, 2};
    std::cout << std::endl << "sum of even terms under four million: "
              << divide_factor << std::endl << std::endl; 
}
                
//long divide_factor(long number_and_factor[]){
int divide_factor(int number, int factor){
//    if(n==1) 
//        return(1);
//    if(n==2) 
//        return(2);
    return (factor);       // For n > 2
}
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
