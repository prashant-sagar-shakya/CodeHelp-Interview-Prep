/*
========================================================================================
                     CONCEPT: INCLUSION-EXCLUSION PRINCIPLE (PIE)
========================================================================================
The Inclusion-Exclusion Principle (PIE) is an elegant counting technique used to find
the size of the union of multiple sets.

1. Basic Idea:
   When we add the sizes of individual sets, we overcount elements that belong to
   multiple sets (intersections). To correct this, we must subtract the sizes of
   their pairwise intersections, add back the sizes of triple intersections, and so on.

2. Mathematical Formula:
   - For 2 sets:
     |A U B| = |A| + |B| - |A n B|

   - For 3 sets:
     |A U B U C| = |A| + |B| + |C| - (|A n B| + |B n C| + |C n A|) + |A n B n C|

   - General Formula for 'k' sets:
     |U_{i=1}^k A_i| = Sum over all non-empty subsets J of {1, ..., k} of:
                       ((-1)^(|J| - 1) * |Intersection_{j in J} A_j|)

3. Classic DSA Problem Application:
   Find the number of integers in the range [1, N] that are divisible by at least
   one prime number from a given set of primes.

   - Let A_i be the set of numbers in [1, N] divisible by the i-th prime.
   - The size of A_i is floor(N / p_i).
   - The size of intersection of a subset of primes is floor(N / LCM(primes in subset)).
   - Since the elements are prime numbers, their LCM is simply their product (if product <= N).
   - Using bitmasking (from 1 to 2^K - 1), we can represent each subset:
     - Odd number of set bits (odd subset size): ADD floor(N / LCM)
     - Even number of set bits (even subset size): SUBTRACT floor(N / LCM)
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

// Helper function to calculate Greatest Common Divisor (GCD)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// Helper function to calculate Least Common Multiple (LCM) of two numbers
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

// Your code here
void Solve()
{
    // Problem: Find the count of numbers in [1, N] divisible by at least one of the given K prime numbers.
    ll n;
    int k;
    cin >> n >> k;

    vector<ll> p(k); // Stores the prime numbers (short for primes)
    for (int i = 0; i < k; i++)
        cin >> p[i];

    ll ans = 0; // Cumulative answer (short for answer)

    // There are 2^k possible subsets.
    // We loop from 1 to (1 << k) - 1 to represent all non-empty subsets using bitmask.
    // If the i-th bit of 'mask' is 1, it means the i-th prime is included in the current subset.
    int total = (1 << k);

    for (int mask = 1; mask < total; mask++)
    {
        ll currLcm = 1; // Current cumulative LCM (no underscores)
        int bits = 0;   // Count of set bits representing subset size
        bool overflow = false;

        for (int i = 0; i < k; i++)
        {
            // Check if the i-th prime is included in the current mask
            if ((mask >> i) & 1)
            {
                bits++;

                // Calculate cumulative LCM of the selected primes in the subset
                currLcm = lcm(currLcm, p[i]);

                // If the LCM exceeds N, then floor(N / LCM) will be 0.
                // We can stop processing this subset early to prevent integer overflow.
                if (currLcm > n)
                {
                    overflow = true;
                    break;
                }
            }
        }

        // If LCM is within bounds, perform Inclusion-Exclusion
        if (!overflow)
        {
            // Count of numbers in [1, N] divisible by currLcm
            ll cnt = n / currLcm;

            // If the number of elements in the subset (bits) is ODD, we ADD the count.
            // If the number of elements in the subset is EVEN, we SUBTRACT the count.
            if (bits % 2 != 0)
                ans += cnt;
            else
                ans -= cnt;
        }
    }

    cout << "Total numbers in [1, " << n << "] divisible by at least one given prime: " << ans << endl;
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
   - Hum 1 se lekar N tak ke numbers me se un numbers ka count nikal rahe hain jo primes array `p`
     ke kisi bhi prime number se divide hote hon.
   - PIE aur bitmasking ka use karke overlaps (double counting) ko remove kar rahe hain.

2. KAISE KAR RAHE HAIN?
   - Range `N` aur primes count `K` le kar primes array `p` me values store karte hain.
   - `total = 2^K` subsets consider karte hain using `mask` loop (1 se total - 1).
   - Har subset ke selected indices ke liye cumulative LCM `currLcm` nikalte hain.
   - Agar subset size `bits` ODD hai: toh `cnt = n / currLcm` ko `ans` me ADD karte hain.
   - Agar subset size `bits` EVEN hai: toh `cnt` ko `ans` se SUBTRACT karte hain.

3. KYA CONCEPT THA (STRUCTURED WAY MEIN)?
   - PIE Formula: Alternately add (odd set union) and subtract (even set intersection).
   - Variables ko human-style aur simple bina kisi underscore ke rakha hai (`p`, `ans`, `total`, `currLcm`, `bits`, `cnt`).
========================================================================================
*/