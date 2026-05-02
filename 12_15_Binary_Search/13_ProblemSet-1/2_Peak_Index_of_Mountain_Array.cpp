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

int Peak(vi &v)
{
    int l = 0, r = v.size() - 1, mid = 0;
    // A simple rule in BS is mid < mid + 1 --> Go right else go left
    while (l < r) // r = mid -> l<r loop and r = mid - 1 -> l<=r loop
    {
        mid = l + (r - l) / 2;
        if (v[mid] < v[mid + 1])
            l = mid + 1;
        else
            r = mid; // in case of peak element is mid then it will cause problem so end=mid
    }
    return l;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (auto &i : v)
        cin >> i;
    cout << Peak(v);
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