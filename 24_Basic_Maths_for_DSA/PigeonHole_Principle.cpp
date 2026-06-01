/*
========================================================================================
                      CONCEPT: PIGEONHOLE PRINCIPLE (PHP)
========================================================================================
The Pigeonhole Principle is a simple yet extremely powerful mathematical concept.

1. Basic Statement:
   If 'n' items (pigeons) are put into 'm' containers (pigeonholes), and n > m,
   then at least one container must contain more than one item.

2. Generalized Statement:
   If 'n' items are distributed into 'm' containers, then at least one container
   must contain at least ceil(n / m) items.
   Similarly, at least one container must contain at most floor(n / m) items.

3. Application in DSA (Subarray Sum Divisible by N):
   Given an array of size N, we want to prove and find a non-empty subarray whose
   sum is divisible by N.

   Proof using Pigeonhole Principle:
   - Let's compute the prefix sums of the array: S_1, S_2, S_3, ..., S_N.
   - There are exactly N prefix sums.
   - If any S_i % N == 0, then the subarray [0...i] is divisible by N.
   - If none of the prefix sums are divisible by N, then the remainders of these
     N prefix sums modulo N must lie in the range [1, N-1].
   - The range [1, N-1] has only N-1 possible values (pigeonholes).
   - But we have N prefix sums (pigeons).
   - By the Pigeonhole Principle, at least two prefix sums must have the exact same
     remainder modulo N. Let these be S_i and S_j (where i < j), meaning:
         S_i % N == S_j % N
     This implies:
         (S_j - S_i) % N == 0
   - Since S_j - S_i represents the sum of the subarray from index i+1 to j,
     the subarray [i+1...j] is guaranteed to have a sum divisible by N.
   - Thus, a solution is guaranteed to ALWAYS exist!
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

// Your code here
void Solve()
{
    // We are solving the "Subarray Sum Divisible by N" problem using Pigeonhole Principle.
    // This function will read N, then an array of N integers, and find a subarray divisible by N.

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // seen will store the first index where a particular remainder modulo N occurred.
    // Since remainders can range from 0 to N-1, the size of the vector is N.
    // We initialize all values with -1 to indicate that no remainder has been seen yet.
    vector<int> seen(n, -1);

    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        // Step 1: Accumulate the sum of elements from start to index i.
        sum += a[i];

        // Step 2: Calculate the remainder modulo N.
        // In C++, the % operator can yield negative results for negative numbers.
        // To handle negative numbers properly, we use the formula: ((sum % N) + N) % N.
        ll rem = ((sum % n) + n) % n;

        // Step 3: Check if the remainder is 0.
        // If remainder is 0, it means the sum of elements from index 0 to i is perfectly divisible by N.
        if (rem == 0)
        {
            cout << "Subarray divisible by N found from index 0 to " << i << endl;
            cout << "Subarray elements: ";
            for (int k = 0; k <= i; k++)
                cout << a[k] << " ";
            cout << endl;
            return; // We found the subarray, so we can exit.
        }

        // Step 4: Check if we have seen this remainder before.
        // If seen[rem] is not -1, it means the same remainder occurred at some previous index 'j'.
        // By Pigeonhole Principle:
        // Sum(0...i) % N == rem  AND  Sum(0...j) % N == rem
        // => (Sum(0...i) - Sum(0...j)) % N == 0
        // => Sum(j+1...i) % N == 0.
        // So the subarray from index j+1 to i is divisible by N.
        if (seen[rem] != -1)
        {
            int j = seen[rem];
            cout << "Subarray divisible by N found from index " << j + 1 << " to " << i << endl;
            cout << "Subarray elements: ";
            for (int k = j + 1; k <= i; k++)
                cout << a[k] << " ";
            cout << endl;
            return; // Exit after finding the first valid subarray.
        }

        // Step 5: If this remainder is seen for the first time, record its index.
        seen[rem] = i;
    }

    // Due to Pigeonhole Principle, the code will never reach this point.
    // A valid subarray is mathematically guaranteed to exist.
    cout << "-1 (No subarray found)" << endl;
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
   - Hum ek array le rahe hain jiska size N hai (jise code me 'a' naam diya hai).
   - Hum is array ke andar ek aisi non-empty "subarray" dundh rahe hain jiska sum N se divide ho.
   - Pigeonhole Principle (PHP) ka use karke hum guaranteed solution find kar rahe hain.

2. KAISE KAR RAHE HAIN?
   - Hum ek `seen` naam ka vector banate hain size N ka, jise -1 se initialize karte hain.
     Yeh vector remainder ke pehli baar dikhne wale index ko store karega.
   - Hum `sum` variable me prefix sum track karte hain.
   - Har index 'i' par remainder modulo N nikalte hain: `rem = ((sum % N) + N) % N`.
   - Agar `rem == 0` hai, toh 0 se lekar current index `i` tak ki subarray divisible hai, use print kar dete hain.
   - Agar `rem` pehle bhi aa chuka hai (`seen[rem] != -1`), toh iska matlab hai ki `seen[rem] + 1` se lekar
     current index `i` tak ka sum N se divisible hai. Hum use print kar dete hain.
   - Agar new remainder hai, toh `seen[rem] = i` kar dete hain.

3. KYA CONCEPT THA (STRUCTURED WAY MEIN)?
   - Pigeons: Humare paas N prefix sums hain.
   - Pigeonholes: N-1 possible remainders (1 se N-1 tak).
   - Kyunki pigeons (> N-1) humare pigeonholes (N-1) se zyada hain, isliye kam se kam do prefix sums
     ka remainder same hoga, jisse subarray sum N se divisible ban jayega.
========================================================================================
*/