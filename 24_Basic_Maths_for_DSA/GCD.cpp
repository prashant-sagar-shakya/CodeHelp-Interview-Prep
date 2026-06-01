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

// lcm(a, b) * gcd(a, b) = a * b

// Iterative
ll gcd(ll a, ll b)
{
    while (b)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Recursive
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// Your code here
void Solve()
{
    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b);
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