/*

Each new term in the Fibonacci sequence is generated by adding the previous 
two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed 
four million, find the sum of the even-valued terms.

*/

#include <iostream>

int fibonacci(int n);
// Precondition: input is the position value of nth number in sequence
// Postcondition: returns nth number in the sequence

int sumEvenFibonacci(int m);
// Precondition: takes max length of fibonacci sequence
// Postcondition: returns sum of all even numbers in the sequence

int main(){

    // fibonacci sequence shall not exceed four million in this problem
    int seqLength = 4000000;     // fibonacci sequence length
                                 // of the nth even number

    // Compute the sum of all even terms in the Fibonacci sequence 
    // not exceeding m.
    std::cout << std::endl << "sum of even terms under four million: "
              << sumEvenFibonacci(seqLength) << std::endl << std::endl; 
}
                
int fibonacci(int n){
    if(n==1) 
        return(1);
    if(n==2) 
        return(2);
    return (fibonacci(n-1)+fibonacci(n-2));       // For n > 2
}

int sumEvenFibonacci(int m){
    int sumEvenTerms = 0;         // sum of even numbers in sequence 
    int k = 0;                    // counter to find the position
                                  // of the nth even number
    int fib = 0;                  // element in nth position
    while(true){
        fib = fibonacci(2+3*k);   // returns even term
        if(fib > m)               // Done! No more adding.
            return(sumEvenTerms);
        sumEvenTerms = sumEvenTerms + fib;
        k += 1;
    }
}
