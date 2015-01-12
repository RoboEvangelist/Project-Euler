/*

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

*/

#include <iostream>
#include <math.h>

long divide_factor(long data[]);
// Precondition: Input is number of interest, and the largest factor
// Postcondition: Returns new largest factor

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
    if (data[1] <= data[0]){        // make sure we don't pass number
        if (data[0]%data[1] == 0){  // if still divisible by factor
            data[0] = data[0] / data[1];
        }
        else{
            // after divisions by two have been maxed out,
            // every other division from there on will be done
            // by numbers that are not divisible by 2. So it's
            // safe to assume we can just increase to factor + 2
            // in order to skip any number that has 2 as factor
            if (data[1] == 2)
                ++data[1];
            else
                data[1] = data[1] + 2;
        }
        divide_factor(data);    // keep dividing till mod != 0
    }
    return(data[1]);                // return max prime number
}
