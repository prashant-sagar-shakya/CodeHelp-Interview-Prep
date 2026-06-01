// Problem Link: https://leetcode.com/problems/count-primes/description/
/*
Given an integer n, return the number of prime numbers that are strictly less than n.
Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0
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

int countPrimes(int n)
{

    // Assume every number is prime initially
    vector<bool> isprime(n + 1, true);

    // Stores the count of prime numbers less than n
    int count = 0;
    isprime[0] = isprime[1] = false; // marking 0 and 1 as non-prime
    // Traverse till sqrt(n)
    // Any composite number beyond this will have a smaller factor already processed
    for (int i = 2; i * i < n; i++)
    {
        // Process only if current number is prime
        if (isprime[i])
        {
            // Mark all multiples of i as non-prime
            // Start from i*i because smaller multiples have already been marked by smaller factors
            for (int j = i * i; j < n; j += i)
                isprime[j] = false;
        }
    }

    // Count all numbers still marked as prime
    for (int i = 2; i < n; i++)
        if (isprime[i])
            count++;

    return count;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    cout << countPrimes(n);
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