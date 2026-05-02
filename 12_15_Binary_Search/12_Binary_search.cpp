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

// Only applies on monotonic functions -> Either in increasing or decreasing order
int BinSearch(vi &v, int target)
{
    int low = 0, high = v.size() - 1, mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2; // Updating mid
        if (v[mid] == target)
            return mid;
        else if (v[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1; // Not found
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (auto &i : v)
        cin >> i;
    int target;
    cin >> target;
    cout << BinSearch(v, target);
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