// Problem Link: https://www.geeksforgeeks.org/problems/product-of-primes5328/1
/*
Given two numbers L and R (inclusive) find the product of primes within this range. Print the product modulo 109+7. If there are no primes in that range you must print 1.

Examples:
Input: L = 1, R = 10
Output: 210
Explaination: The prime numbers are 2, 3, 5 and 7.

Input: L = 1, R = 20
Output: 9699690
Explaination: The primes are 2, 3, 5, 7, 11, 13, 17 and 19.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define endl '\n'

const ll MOD = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Logic of Segmented Sieve
// Normal Sieve -> Find helper primes till sqrt(R)
// Segmented Sieve -> Use those primes to eliminate
// composites only inside the range [L, R]

// Normal Sieve of Eratosthenes -> Returns all prime numbers till sqrt(R)
vector<int> Sieve(int R)
{
    // Initially assume all numbers are prime
    vector<bool> isPrime(R + 1, true);
    // Stores all prime numbers till sqrt(R)
    vector<int> primes;
    // 0 and 1 are not prime
    isPrime[0] = isPrime[1] = false;

    // Mark multiples of every prime as non-prime
    for (int i = 2; i * i <= R; i++)
        if (isPrime[i])
            for (int j = i * i; j <= R; j += i)
                isPrime[j] = false;

    // Collect all primes till sqrt(R)
    for (int i = 2; i <= R; i++)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

// Segmented Sieve -> Returns all prime numbers in the range [L, R]
vector<long long> segmentedSieve(long long L, long long R)
{
    // Generate all helper primes till sqrt(R)
    vector<int> primes = Sieve(sqrt(R));

    // Segment array representing numbers from L to R
    // segment[0] -> L
    // segment[1] -> L + 1
    // ...
    // segment[i - L] -> i
    vector<bool> segment(R - L + 1, true);

    // Use helper primes to mark composites in [L, R]
    for (auto p : primes)
    {
        // Find first multiple of p inside [L, R]
        long long start = max(1LL * p * p, ((L + p - 1) / p) * 1LL * p);

        // Mark all multiples of p as non-prime
        for (long long j = start; j <= R; j += p)
            segment[j - L] = false;
    }

    // Handle special cases
    // 0 and 1 are not prime
    if (L == 0)
    {
        segment[0] = false;
        if (R >= 1)
            segment[1] = false;
    }
    else if (L == 1)
        segment[0] = false;

    // Collect all prime numbers from [L, R]
    vector<long long> rangePrimes;

    cout << "Prime Numbers from Range " << L << " to " << R << ": ";
    for (long long i = L; i <= R; i++)
        if (segment[i - L])
        {
            cout << i << " ";
            rangePrimes.push_back(i);
        }
    cout << endl;

    return rangePrimes;
}

// Returns product of all primes in [L, R]
long long primeProduct(long long L, long long R)
{
    // Get all prime numbers in the range
    vector<long long> primes = segmentedSieve(L, R);
    // If no prime exists, answer remains 1
    long long ans = 1;

    // Multiply all primes and take modulo
    for (auto prime : primes)
        ans = (ans * (prime % MOD)) % MOD;

    return ans;
}

// Your code here
void Solve()
{
    int L, R;
    cin >> L >> R;
    cout << primeProduct(L, R);
}

// Driver code
int main()
{
    fastio();
    int t = 1;
    // cin >> t;
    while (t--)
        Solve();
    return 0;
}