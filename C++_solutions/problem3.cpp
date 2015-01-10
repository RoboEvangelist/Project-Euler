/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <iostream>

long divide_factor(long number_and_factor[]);
// Precondition: gets the number of interest, and the largest factor
// Postcondition: returns the number of interes, and the new largest factor

int main(){

    // {number of interest, maximum factor}
    long number_and_factor[] = {600851475143, 2};
    std::cout << std::endl << "the maximum prime factor is of " 
              << number_and_factor[0]
              << " is: " << divide_factor(number_and_factor) 
              << std::endl << std::endl; 
}
                
long divide_factor(long number_and_factor[]){
//    if(n==1) 
//        return(1);
//    if(n==2) 
//        return(2);
    return(number_and_factor[1]);       // For n > 2
}
