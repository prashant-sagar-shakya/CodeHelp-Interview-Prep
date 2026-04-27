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
#define endl '\n'

const ll MOD = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Reverse of a number
ll reverse(ll n)
{
    ll res = 0;
    while (n != 0)
    {
        int last = n % 10;
        res = res * 10 + last;
        n /= 10;
    }
    return res;
}

// Your code here
void Solve()
{
    // convert to binary
    ll x, i = 0, res = 0;
    cin >> x;
    long long n = x;
    while (n != 0)
    {
        int bit = n & 1;
        n >>= 1;
        res = bit * pow(10, i) + res;
        i++;
    }
    cout << res << endl;
    cout << reverse(x) << endl;

    // Binary to Decimal
    int j = 0, ans = 0;
    while (x != 0)
    {
        int last = x % 10;
        ans = ans + pow(2, j) * last;
        x /= 10;
        j++;
    }
    cout << ans << endl;
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