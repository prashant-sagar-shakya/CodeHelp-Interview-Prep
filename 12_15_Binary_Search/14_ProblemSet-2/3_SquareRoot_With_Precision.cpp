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

int RootInt(int n)
{
    ll l = 0, r = n / 2;
    ll mid = 0, ans = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        ll sq = mid * mid;
        if (sq == n)
            return mid;
        else if (sq < n)
        {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
    return ans;
}

double morePrecision(int n, int Precision, int tempSol)
{
    double factor = 1;
    double ans = tempSol;
    for (int i = 0; i < Precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j += factor)
            ans = j;
    }
    return ans;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    int Int = RootInt(n);
    int digits_after_decimal;
    cin >> digits_after_decimal;
    cout << morePrecision(n, digits_after_decimal, Int);
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