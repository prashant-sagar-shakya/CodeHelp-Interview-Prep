/*
========================================================================================
                          CONCEPT: MODULAR FACTORIAL (N! % P)
========================================================================================
Computing the factorial of a number modulo a prime 'P' (N! % P) is a fundamental
task in number theory and competitive programming.

1. Case 1: N >= P
   If N is greater than or equal to the modulo P (where P is prime), then N! contains P
   as one of its factors (e.g., N! = 1 * 2 * ... * P * ... * N).
   Therefore, N! % P will always be 0.

2. Case 2: N < P and N is small (e.g., N <= 10^7)
   We can calculate N! % P directly in O(N) time by running a simple loop from 1 to N,
   multiplying the numbers and taking modulo P at each step.

3. Case 3: N is very close to P (i.e., P - N is small, e.g., P - N <= 10^5)
   If N is slightly smaller than P, a direct O(N) loop is too slow (especially if P is large,
   like 10^9). We can optimize this using Wilson's Theorem.

   - Wilson's Theorem states that for any prime P:
         (P - 1)! === -1 (mod P)   which is equivalent to  P - 1 (mod P)

   - We can rewrite (P - 1)! as:
         (P - 1)! = N! * (N + 1) * (N + 2) * ... * (P - 1)

   - Substituting this into Wilson's Theorem:
         N! * (N + 1) * (N + 2) * ... * (P - 1) === -1 (mod P)

   - Let Product = (N + 1) * (N + 2) * ... * (P - 1) % P.
     Then:
         N! * Product === -1 (mod P)
         N! === -1 * (Product)^(-1) (mod P)
            === (P - 1) * modInverse(Product) % P

   - We can compute the "Product" in O(P - N) time and its modular inverse in O(log P) time.
     This reduces the time complexity from O(N) to O(P - N + log P), which is extremely fast!
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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Helper function to calculate (base^exp) % MOD in O(log exp) time
ll power(ll base, ll exp, ll mod)
{
    ll res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Helper function to find modular multiplicative inverse using Fermat's Little Theorem
// a^(-1) === a^(P - 2) (mod P) where P is prime
ll modInv(ll n, ll p) { return power(n, p - 2, p); }

// Function to calculate N! % P when P - N is small (using Wilson's Theorem)
// Time Complexity: O(P - N + log P)
ll solveWilson(ll n, ll p)
{
    // If N is close to P, we calculate the product of elements from (N + 1) to (P - 1)
    ll prod = 1;
    for (ll i = n + 1; i < p; i++)
        prod = (prod * i) % p;

    // N! = -1 * (prod)^(-1) % p
    // In modulo arithmetic, -1 is represented as (p - 1).
    ll inv = modInv(prod, p);
    ll ans = ((p - 1) * inv) % p;
    return ans;
}

// Function to calculate N! % P using simple iteration
// Time Complexity: O(N)
ll solveIter(ll n, ll p)
{
    ll ans = 1;
    for (ll i = 2; i <= n; i++)
        ans = (ans * i) % p;
    return ans;
}

// Your code here
void Solve()
{
    // We want to calculate N! % P where P is a prime number.
    ll n, p;
    cin >> n >> p;

    cout << "--- Calculating " << n << "! % " << p << " ---" << endl;

    // CASE 1: If N >= P, N! contains P as a factor, so result is 0
    if (n >= p)
    {
        cout << "Case 1: N >= P. Since N! contains the prime P as a factor, the remainder is: 0" << endl;
        return;
    }

    // CASE 2: If N is very close to P (e.g., P - N <= 10^5), we use Wilson's Theorem optimization
    if (p - n <= 100000)
    {
        ll ans = solveWilson(n, p);
        cout << "Case 2: P - N is small (" << p - n << "). Using Wilson's Theorem." << endl;
        cout << "Result: " << ans << endl;
    }
    // CASE 3: If P - N is large, we compute directly using iteration
    else
    {
        ll ans = solveIter(n, p);
        cout << "Case 3: P - N is large. Using Direct O(N) Iteration." << endl;
        cout << "Result: " << ans << endl;
    }
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
   - Hum kisi number N ka factorial modulo a prime number P (yaani N! % P) nikal rahe hain.
   - Humne teen alag-alag mathematical cases handle kiye hain bina kisi underscore variable names ke.

2. KAISE KAR RAHE HAIN?
   - **Case 1 (N >= P)**:
     - Jab N, P se bada ya barabar ho, tab factorial me P term pehle se maujood hota hai. Isliye directly remainder `0` return karte hain.
   - **Case 2 (P - N <= 10^5) (Wilson's Theorem)**:
     - Jab N aur P bohot close hain, tab Wilson's Theorem use karte hain: `(P-1)! === -1 (mod P)`.
     - Hum range `[N+1, P-1]` ka loop chalakar product `prod` calculate karte hain.
     - Fir is pure term ka modular inverse `modInv(prod, p)` nikalte hain.
     - Final formula: `ans = ((p - 1) * inv) % p`.
   - **Case 3 (Normal iteration)**:
     - Gap bada hone par `solveIter` call karte hain jo `O(N)` loop chala kar simple calculations deta hai.

3. KYA CONCEPT THA (STRUCTURED WAY MEIN)?
   - Wilson's theorem and Modular inverse optimizations ko use kiya hai.
   - Variables human-style aur bilkul simple rakhe hain: `prod`, `ans`, `inv`, `modInv`, `solveWilson`, `solveIter`.
========================================================================================
*/