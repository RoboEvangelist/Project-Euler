/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <iostream>

long divide_factor(long data[]);
// Precondition: gets the number of interest, and the largest factor
// Postcondition: new largest factor

int main(){

    // starting from 2 guarantees we always get prime factors only
    // and forces the program to "automatically check" if the
    // current factor can divide the number
    long data[] = {600851475143, 2};  // {number of interest, 
                                      //  maximum factor}
    std::cout << std::endl << "the maximum prime factor of " 
              << data[0];
    std::cout << " is: " << divide_factor(data) 
              << std::endl << std::endl; 
}
                
long divide_factor(long data[]){
    if (data[1] <= data[0]){         // make sure we don't pass number
        if (data[0]%data[1] == 0){  // if still divisible by factor
            data[0] = data[0] / data[1];
            divide_factor(data);
        }
        else{
            ++data[1];
            divide_factor(data);
        }
    }
    return(data[1]);                // return max prime number
}
