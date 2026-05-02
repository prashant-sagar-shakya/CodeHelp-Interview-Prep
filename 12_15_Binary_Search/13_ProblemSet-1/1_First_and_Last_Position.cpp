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

int First(vi &v, int k)
{
    int l, mid = 0, r = v.size() - 1, res = -1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (v[mid] == k)
        {
            res = mid;
            r = mid - 1; // consider mid is falling currently at last element so that's why mid-1
        }
        else if (v[mid] > k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return res;
}

int Last(vi &v, int k)
{
    int l, mid = 0, r = v.size() - 1, res = -1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (v[mid] == k)
        {
            res = mid;
            l = mid + 1;
        }
        else if (v[mid] > k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return res;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (auto &i : v)
        cin >> i;
    int k;
    cin >> k;
    cout << First(v, k) << " " << Last(v, k);
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