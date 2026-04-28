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

// Using Triple Xor
int XorDup(vector<int> &arr, int n)
{
    int ans = 0;
    // 0 to n
    for (int i = 0; i < n; i++)
    {
        ans ^= arr[i];
    }
    // 1 to n
    for (int i = 1; i < n; i++)
        ans ^= arr[i];
    return ans;
}

// Using Hashing
int MapDup(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;
    for (auto &i : arr)
        mp[i]++;
    for (auto &i : mp)
        if (i.second > 1)
            return i.first;
    return -1; // No Duplicate Found
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << XorDup(arr, n) << endl;
    cout << MapDup(arr, n);
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