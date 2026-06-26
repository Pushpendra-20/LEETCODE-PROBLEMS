# /*

LeetCode Problem: Count Primes
Problem Number: 204

Approach:

* Handle the edge case:

  * If n <= 2, there are no prime
    numbers less than n.

* Create a boolean array `isPrime`
  of size n and initialize all values
  to true.

* Mark 0 and 1 as non-prime.

* Apply the Sieve of Eratosthenes:

  * Iterate from 2 up to √n.
  * If the current number is prime,
    mark all of its multiples,
    starting from i², as non-prime.

* After completing the sieve,
  traverse the array and count all
  remaining prime numbers.

* Return the total count.

Why this approach?

* Every composite number has a prime
  factor less than or equal to its
  square root.
* Starting from i² avoids redundant
  work because smaller multiples have
  already been processed.

Example:

Input:
n = 10

Prime Numbers:
2, 3, 5, 7

Output:
4

Time Complexity: O(n log log n)
Space Complexity: O(n)

Where:
n = given integer

Key Concepts:

* Sieve of Eratosthenes
* Prime Numbers
* Boolean Array
* Number Theory

====================================================
*/





class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }
        return count;
    }
};
