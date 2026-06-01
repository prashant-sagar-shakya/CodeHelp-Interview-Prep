/*
========================================================================================
                         CONCEPT: CATALAN NUMBERS (C_n)
========================================================================================
Catalan numbers form a sequence of natural numbers that occur in various counting
problems in combinatorics.

1. Mathematical Definition:
   The n-th Catalan number C_n can be defined recursively as:
       C_0 = 1
       C_n = Sum_{i=0}^{n-1} (C_i * C_{n-1-i})  for n >= 1

   Or analytically using binomial coefficients (combination formula):
       C_n = [1 / (n + 1)] * (2n choose n)
           = (2n)! / [ (n + 1)! * n! ]

2. First few Catalan numbers (for n = 0, 1, 2, 3, ...):
   1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, ...

3. Classic Applications of Catalan Numbers:
   - Correct Parentheses: Number of valid expressions containing n pairs of brackets.
   - Dyck Paths: Paths from (0,0) to (2n, 0) using steps (1,1) and (1,-1) that do not
     fall below the x-axis.
   - Triangulation of Polygon: Number of ways to divide a convex polygon of n+2 vertices
     into triangles by drawing non-intersecting diagonals.
   - Binary Search Trees (BSTs): Number of structurally unique BSTs that can be formed
     with n keys.
   - Full Binary Trees: Number of full binary trees with n internal nodes (or n+1 leaves).
========================================================================================
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

// Helper function to calculate (base^exp) % MOD using binary exponentiation in O(log exp)
ll power(ll base, ll exp)
{
    ll res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % MOD; // If exponent is odd, multiply base
        base = (base * base) % MOD;   // Square the base
        exp /= 2;                     // Halve the exponent
    }
    return res;
}

// Helper function to find modular multiplicative inverse of a number using Fermat's Little Theorem.
// Valid only when MOD is a prime number (like 1e9 + 7).
// a^(-1) === a^(MOD - 2) (mod MOD)
ll modInv(ll n) { return power(n, MOD - 2); }

// Helper function to compute (n choose r) % MOD in O(r log MOD)
ll ncr(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    ll num = 1; // Numerator
    ll den = 1; // Denominator

    for (int i = 0; i < r; i++)
    {
        num = (num * (n - i)) % MOD;
        den = (den * (i + 1)) % MOD;
    }

    // Result = Numerator * (Denominator)^(-1) % MOD
    return (num * modInv(den)) % MOD;
}

// Method 1: Find C_n using the Analytical Formula C_n = [1 / (n + 1)] * (2n choose n)
// This is very fast (O(N log MOD) time) for finding a specific Catalan number C_n under prime MOD.
ll catalanFormula(int n)
{
    // C_n = (2n choose n) / (n + 1)
    ll comb = ncr(2 * n, n);
    ll inv = modInv(n + 1);
    return (comb * inv) % MOD;
}

// Method 2: Find all Catalan numbers up to N using Dynamic Programming
// Using the recurrence relation C_n = Sum_{i=0}^{n-1} (C_i * C_{n-1-i})
// This takes O(N^2) time but does not require MOD to be a prime and computes all Catalan numbers up to N.
vector<ll> catalanDP(int n)
{
    vector<ll> dp(n + 1, 0);
    dp[0] = 1; // Base case: C_0 = 1
    if (n >= 1)
        dp[1] = 1; // Base case: C_1 = 1

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // C_i = Sum_{j=0}^{i-1} (C_j * C_{i-1-j})
            dp[i] = (dp[i] + (dp[j] * dp[i - 1 - j]) % MOD) % MOD;
        }
    }
    return dp;
}

// Your code here
void Solve()
{
    // Let's demonstrate both DP and Formula methods to find Catalan Numbers.
    int n;
    cin >> n;

    cout << "--- Catalan Numbers Calculation for N = " << n << " ---" << endl;

    // 1. Calculate specific C_n using analytical formula:
    ll ans = catalanFormula(n);
    cout << "N-th Catalan Number (Using Formula): " << ans << endl;

    // 2. Calculate sequence of Catalan numbers up to N using Dynamic Programming:
    vector<ll> dp = catalanDP(n);
    cout << "Catalan Sequence from C_0 to C_" << n << " (Using DP):" << endl;
    for (int i = 0; i <= n; i++)
        cout << "C_" << i << " = " << dp[i] << endl;
}

// Driver code
int main()
{
    fastio();
    int t = 1;
    // cin >> t; // Uncomment if there are multiple test cases
    while (t--)
        Solve();
    return 0;
}

/*
========================================================================================
                       HINGLISH EXPLANATION
========================================================================================
1. KYA KAR RAHE HAIN?
   - Hum kisi value 'N' ke liye Catalan Number (C_n) calculate kar rahe hain.
   - Humne dono methods implement kiye hain:
     - Pehla method DP (Dynamic Programming) jo C_0 se lekar C_N tak ki complete list nikalta hai.
     - Dusra method combinations formula (2nCn / (n+1)) jo direct C_N nikalta hai modular inverse ke sath.

2. KAISE KAR RAHE HAIN?
   - **DP Method (O(N^2))**:
     - Hum ek array `dp` size `N+1` ka banate hain.
     - Base cases define karte hain: `dp[0] = 1` aur `dp[1] = 1`.
     - Partition logic lagakar nested loops se saare values calculate karte hain.

   - **Formula Method (O(N log MOD))**:
     - Catalan number ka direct formula hai: `C_n = (2n choose n) / (n + 1)`.
     - division by `(n + 1)` ko multiplication by `(n + 1)^(-1) % MOD` se replace karte hain using `modInv`.
     - Fermat's Little Theorem se power calculate karte hain using `power` function.

3. KYA CONCEPT THA (STRUCTURED WAY MEIN)?
   - DP Relation: C_n = Summation (C_i * C_{n-1-i}).
   - Formula: C_n = 2nCn / (n+1).
   - Variables ko humne bilkul short aur clear rakha hai bina kisi underscore ke (`dp`, `ans`, `comb`, `inv`, `ncr`, `modInv`).
========================================================================================
*/