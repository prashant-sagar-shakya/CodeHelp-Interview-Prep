// Problem Link: https://www.naukri.com/code360/problems/modular-exponentiation_1082146

/*
You are given a three integers 'X', 'N', and 'M'. Your task is to find ('X' ^ 'N') % 'M'. A ^ B is defined as A raised to power B and A % C is the remainder when A is divided by C.
Detailed explanation ( Input/output format, Notes, Images )

Sample Input 1 :
2
3 1 2
4 3 10
Sample Output 1 :
1
4
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

int modularExponentiation(int x, int n, int m)
{
    // Stores the final answer
    int res = 1;

    while (n)
    {
        // If the current bit of exponent is 1 (n is odd), include the current power of x in the answer
        if (n & 1)
            res = (1LL * res * (x % m)) % m;

        // Move from:
        // x^(1) -> x^(2) -> x^(4) -> x^(8) -> ... by squaring the current base
        x = (1LL * (x % m) * (x % m)) % m;

        // Remove the current bit and move to the next bit
        // Equivalent to: n = n / 2
        n >>= 1;
    }

    // Final value of (x^n) % m
    return res;
}

// Your code here
void Solve()
{
    int x, n, m;
    cin >> x >> n >> m;
    cout << modularExponentiation(x, n, m);
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