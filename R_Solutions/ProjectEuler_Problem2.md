## Even Fibonacci numbers

#### [Project Eluer: Problem 2](https://projecteuler.net/problem=2)

The [Fibonacci sequence](http://en.wikipedia.org/wiki/Fibonacci_number) is a 
sequence of integers having 1 as the first term, 2 as the second term, 
and the sum of the previous two terms from the third term and thereafter. The 
following are the first ten terms in the Fibonacci sequence:

$$ 1,2,3,5,8,13,21,34,55,89,... $$

It's not hard but tedious to calculate the larger terms in the Fibonacci sequence. 
Fortunately, it is very easy and natural to define a recursive function for this
purpose.


```r
# Computes the n th term of the Fibonnacci sequence. 
fibonacci <- function(n){
                if(n==1) return(1)
                if(n==2) return(2)
                return(fibonacci(n-1)+fibonacci(n-2)) # For n > 2
        }
```

The function above computes the n th term of the Fibonnacci sequence. For example, 
by calling the function with n=10, we get the 10th term of the sequence.


```r
fibonacci(10) # returns the value of the 10 th term.
```

```
## [1] 89
```

The first fifteen terms are generated in the following snippet:


```r
firstFifteenTerm <- sapply(1:15, fibonacci)
firstFifteenTerm # displays the results
```

```
##  [1]   1   2   3   5   8  13  21  34  55  89 144 233 377 610 987
```

Having gained some appreciation about the Fibonacci sequence, we're ready to 
start the game! As described in the original problem (first link on top),
our goal is to find the sum of all even Fibonacci terms not exceeding some given
number M. Now that we have the function _fibonacci_ defined, we are pretty much done
for the part in finding the largest term not exceeding M. It is left to figure 
what terms are even. Of course we can do it by checking every term in the sequence,
but we can do better. Let's step back and take a good look at the first fifteen 
terms for a moment...


```
##  [1]   1   2   3   5   8  13  21  34  55  89 144 233 377 610 987
```

Do you see some pattern here? When do you think the next even term appears in 
the sequence? How about the one after?

That's right, the even terms in the Fibonacci sequence appear in a certain
pattern. In the above example, the positions of the even terms are


```r
which(firstFifteenTerm%%2==0) # returns positions of the even terms.
```

```
## [1]  2  5  8 11 14
```

As you can see, these numbers can be expressed as $2+3k$ for $k=0,1,2,3,4,...$. 
This pattern is explained by the facts that the sum of an odd number and an even 
number is odd and that the sum of two odd numbers is even. Thus, the next even 
term occurs when $n=2+3*5=17$ and the one after occurs when $n=2+3*6=20$.

Verify:

```r
sapply(1:20, fibonacci) # generates the first twenty terms.
```

```
##  [1]     1     2     3     5     8    13    21    34    55    89   144
## [12]   233   377   610   987  1597  2584  4181  6765 10946
```


So, we only have to keep track of the even terms in the Fibonacci sequence, i.e.,
the terms with $n=2+3k$ for $k=0,1,2,3,...$ and find the largest even term not 
exceeding M as far as the goal is concerned.

We wrap up the game as follows:


```r
# Computes the sum of all even terms in the Fibonacci sequence not exceeding m.
sumEvenFibonacci <- function(m)
                    {
                        sumEvenTerms <- 0
                        k <- 0
                        while(TRUE){
                              n <- 2+3*k
                              fib <- fibonacci(n) # even term
                              if(fib > m) # Done! No more adding.
                                      return(sumEvenTerms)
                              sumEvenTerms <- sumEvenTerms + fib
                              k <- k+1
                        }
                    }
```

To play around, we can try a few values of M and verify them with the examples above.


```r
sumEvenFibonacci(5); sumEvenFibonacci(10); sumEvenFibonacci(50);
```

```
## [1] 2
```

```
## [1] 10
```

```
## [1] 44
```

Finally, we answer the specific question in the original problem:

```r
sumEvenFibonacci(4000000)
```

```
## [1] 4613732
```








