/*
Leetcode Problem 204: Count Primes
----------------------------------
Given an integer n, return the number of prime numbers that are strictly less than n.

Approach (Sieve of Eratosthenes):
---------------------------------
- Initialize a boolean array isPrime of size n to true.
- Mark 0 and 1 as non-prime.
- For each i from 2 to sqrt(n):
    - If i is prime, mark all multiples of i starting from i*i as non-prime.
- Count the number of true values in isPrime and return.

Time Complexity:  O(n log log n)  - Sieve of Eratosthenes
Space Complexity: O(n)            - Boolean array of size n
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return count(isPrime.begin(), isPrime.end(), true);
    }
};

// Example usage
int main() {
    int n = 10;
    cout << "Number of primes less than " << n << ": " << Solution().countPrimes(n) << endl;
    return 0;
}
