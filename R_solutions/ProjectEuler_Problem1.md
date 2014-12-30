## Multiples of 3 and 5

#### [Project Eluer: Problem 1](https://projecteuler.net/problem=1)

To find all the multiples of 3 or 5 below some number, we can first 
separately list the multiples of each number and then form a unique set from the
combined lists.

For example, we want to find all the multiples of 3 or 5 below 37, we first list
the multiples of 3 that are below 37 which are
$$3,6,9,12,\underline{15},18,21,24,27,\underline{30},33,36$$
and the multiples of 5 that are below 37 which are
$$ 5,10,\underline{15},20,25,\underline{30},35, $$
and then combine the two sets above, with the repeated numbers included only once.
That gives us the result:
$$ 3,5,6,9,10,12,\underline{15},18,20,21,24,25,27,\underline{30},33,35,36. $$
Before we move on, let's take a moment to think about what type of numbers gets 
repeated and what doesn't...

Our goal this time is to find the sum of all the multiples of 3 or 5 below some
number M. Taking the example above, this could be accomplished by summing up all
the numbers in the last list above. If we have the computer does the job for us,
then this is how the code looks like :


```r
sum <- 0
for(i in 1:37){
        if(i%%3==0 || i%%5==0) # TRUE when i is either a multiple of 3 or 5.
                sum <- sum + i
}
sum
```

```
## [1] 329
```
Verify:

```r
# Sums up all the numbers in the last list above.
sum(c(3,5,6,9,10,12,15,18,20,21,24,25,27,30,33,35,36))
```

```
## [1] 329
```

This is nice and straight-forward but can take a long time for the computations 
if M is a large number. Maybe, just maybe, we can capture the term-by-term summing
in a formula if there is some pattern in the number to follow? The numbers in the
last list seem all over the place; however, if we look at the first two lists, 
there is a fixed difference between each number in each of the lists! "What do 
these patterns have to do with coming up with a formula?", you may ask. I think the 
story about Gauss, one of the greatest mathematicians, in the following might 
give us some clue.

[http://www.americanscientist.org/issues/pub/gausss-day-of-reckoning](http://www.americanscientist.org/issues/pub/gausss-day-of-reckoning)

Story time's over, let's come back to coming up with a formula that captures the 
summing. Note that since each term in the first list,

$$ 3,6,9,12,15,18,21,24,27,30,33,36 $$

is a multiple of 3, it can be thought of as 3 times 1,2,... 11,12. Hence,
the sum of all numbers in the first list

$$ 3+6+9+12+15+18+21+24+27+30+33+36 $$

equals

$$ 3*(1+2+3+4+5+6+7+8+9+10+11+12). $$

Gauss's method allows the sum to be expressed as

$$ 3* \dfrac{(1+12)*12}{2}. $$

Similarly, the sum of the numbers in the second list can be expressed as

$$ 5* \dfrac{(1+7)*7}{2}. $$

As we have seen earlier, the third list of numbers is pretty much the first two 
lists put together, except the repeated numberes are included only once. 
Therefore, the sum of the numbers in the third list is the sum of the numbers 
in the first list plus the sum of the numbers in the second list. So far so good?
NOOOO! When we add the sums of the first two lists, we have the numbers 15 and 30
each added twice. To resolve this, we subtract the repeated numbers from the sum
of sums, i.e.,

$$ Answer = 3* \dfrac{(1+12)*12}{2} + 5* \dfrac{(1+7)*7}{2} - 15 - 30 $$

or equivalently,

$$ Answer = 3* \dfrac{(1+12)*12}{2} + 5* \dfrac{(1+7)*7}{2} - (15+30). $$

Coming back to the earliest question: what type of numbers gets repeated? The 
answer is the common multiples of 3 and 5.

By this logic, given any number M, the sum of all the multiples of 3 or 5 below M is 

$$ 3* \dfrac{(1+A)*A}{2} + 5* \dfrac{(1+B)*B}{2} - (15+30+...+C), $$

where

A = the greatest integer such that 3*A < M,

B = the greatest integer such that 5*B < M, and

C = the largest common multiple of 3 and 5 that is less than M.

Since each number in $ (15+30+...+C) $ is a multiple of 15, the lowest 
common multiple of 3 and 5, the above formula can be further simplified:

$$ 3* \dfrac{(1+A)*A}{2} + 5* \dfrac{(1+B)*B}{2} - (15+30+...+C) $$

$$ = 3* \dfrac{(1+A)*A}{2} + 5* \dfrac{(1+B)*B}{2} - 15*(1+2+...+ \dfrac{C}{15}) $$

$$ = 3* \dfrac{(1+A)*A}{2} + 5* \dfrac{(1+B)*B}{2} - 15* \dfrac{(1+\frac{C}{15})*\frac{C}{15}}{2}. $$

On a finally step, we replace the fraction $\frac{C}{15}$ with the integral 
expression D (why is it legal?)

$$ = 3* \dfrac{(1+A)*A}{2} + 5* \dfrac{(1+B)*B}{2} - 15* \dfrac{(1+D)*D}{2}. $$

Up to this point, we have come up with an algorithm that is loop-free and calculates 
the sum of all the multiples of 3 or 5 below some arbitrary number M. We will now
turn it into a program.


```r
sumMultiples <- function(m){
                        # Subtracts 1 from m to ensure the bounding condition.
                        A <- as.integer((m-1)/3) # the greatest integer such that 3*A <= M
                        B <- as.integer((m-1)/5) # the greatest integer such that 5*B <= M
                        D <- as.integer((m-1)/15) # the greatest integer such that 15*D <= M
                        answer <- 3*(1+A)*A/2 + 5*(1+B)*B/2 - 15*(1+D)*D/2
                        answer
                }
```

Check:

```r
sumMultiples(37) # We got 329 for the answer earlier. 
```

```
## [1] 329
```

```r
sumMultiples(10) # Is 23 from Project Euler Problem 1's example.
```

```
## [1] 23
```
... mate. Bingo, we got the program! To wrap it up, we find the sum of all the 
multiples of 3 or 5 below 1000 -- the answer to the original posted question:

```r
sumMultiples(1000)
```

```
## [1] 233168
```

Thank you for reading this blog. Even though this time we are free to select the
bound M, it isn't the case for the pair 3 and 5. In a soon future, we will attemp
 a program that allows the user to use any arbitrary triples for the inputs.

