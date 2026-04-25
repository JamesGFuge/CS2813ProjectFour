# CS2813: Project 4

## How to Run

First, compile the program with C++17 support:
```bash
cl.exe /std:c++17 /EHsc /nologo Project4.cpp
```

Place `input.txt` in the same directory and execute:
```bash
.\Project4.exe
```

## Sample Output

For the sample input (N=30, a=3, m=11):
```
Prime Count (Trial Division) = 10
Prime Count (Sieve) = 10
gcd(a, m) = 1
Modular Inverse = 4
```

## Algorithm Description

The **trial division algorithm** checks each number k from 2 to N by testing divisibility against all integers from 2 up to √k; if any divisor is found, k is not prime. The **Sieve of Eratosthenes** is more efficient: it marks multiples of each prime starting from i² (since smaller multiples were already marked by smaller primes), iterating only up to √N. The **Extended Euclidean Algorithm** is a recursive procedure that computes gcd(a, m) along with coefficients x and y satisfying ax + by = gcd(a, m); we then use the returned x as the modular inverse of a modulo m if gcd(a, m) = 1, adjusting x to be in the range [0, m) by computing (x mod m + m) mod m.
