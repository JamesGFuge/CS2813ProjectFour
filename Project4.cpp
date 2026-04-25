// Coding Assignment 4 - C++ Template

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <tuple>

using namespace std;


// Step 1: Prime counting using trial division
int count_primes_trial(int N) {

    int count = 0;

    for (int k = 2; k <= N; k++) {

        bool is_prime = true;

        // Check divisibility from 2 up to sqrt(k)
        for (int i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            count++;
        }
    }

    return count;
}


// Step 2: Sieve of Eratosthenes (Fill-in)
int count_primes_sieve(int N) {

    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; i++) {

        if (is_prime[i]) {

            // Mark multiples of i as not prime, starting from i*i
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }

        }
    }

    int count = 0;

    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) count++;
    }

    return count;
}


// Step 3: Extended Euclidean Algorithm
tuple<long long, long long, long long> extended_gcd(long long a, long long b) {

    // Base case: b = 0
    if (b == 0) {
        return make_tuple(a, 1, 0);
    }
    
    // Recursive case
    auto [g, x1, y1] = extended_gcd(b, a % b);
    long long x = y1;
    long long y = x1 - (a / b) * y1;
    return make_tuple(g, x, y);
}


// Step 4: Modular inverse
long long mod_inverse(long long a, long long m) {

    auto [g, x, y] = extended_gcd(a, m);
    
    // If gcd(a, m) != 1, no modular inverse exists
    if (g != 1) {
        return -1;
    }
    
    // Return x mod m, ensuring positive result
    return (x % m + m) % m;
}


// Helper function to print modular inverse
void print_inverse(long long inv) {

    if (inv == -1) {
        cout << "None";
    } else {
        cout << inv;
    }
}


int main() {

    ifstream fin("input.txt");

    if (!fin) {
        cerr << "Error: could not open input.txt" << endl;
        return 1;
    }

    int N;
    long long a, m;

    fin >> N;
    fin >> a;
    fin >> m;

    fin.close();

    // Step 1
    int trial_count = count_primes_trial(N);

    // Step 2
    int sieve_count = count_primes_sieve(N);

    // Step 3 + 4
    auto [g, x, y] = extended_gcd(a, m);
    long long inv = mod_inverse(a, m);

    // Output
    cout << "Prime Count (Trial Division) = " << trial_count << endl;
    cout << "Prime Count (Sieve) = " << sieve_count << endl;
    cout << "gcd(a, m) = " << g << endl;

    cout << "Modular Inverse = ";
    print_inverse(inv);
    cout << endl;

    return 0;
}