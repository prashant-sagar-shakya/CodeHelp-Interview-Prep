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

/*
(a mod m)+(b mod m)  mod m=a+b  mod m
(a mod m)−(b mod m)  mod m=a−b  mod m
(a mod m)⋅(b mod m)  mod m=a⋅b  mod m
*/

// Fast Exponentation/Binary Exponentation
/*
A^b -> if b is even -> (A^(b/2))^2 and if b is odd (A^(b/2))^2 * A
*/

long long binExp(long long a, long long b)
{
    // Stores the final answer
    long long ans = 1;
    while (b)
    {
        // If the current bit of exponent is 1, multiply the answer by the current base
        if (b & 1)
            ans *= a;
        // Square the base for the next bit
        a *= a;
        // Move to the next bit of the exponent
        b >>= 1;
    }

    return ans;
}
// Your code here
void Solve()
{
    ll a, b;
    cin >> a >> b;
    cout << binExp(a, b);
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