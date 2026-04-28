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

bool UniqOcc(vector<int> v)
{
    unordered_map<int, int> mp1, mp2;
    for (auto &i : v)
        mp1[i]++;
    for (auto &[key, val] : mp1)
        mp2[val]++;
    for (auto &[key, val] : mp2)
        if (val != 1)
            return false;
    return true;
}

// Your code here
void Solve()
{
    // Using dual dictonary
    int n;
    cin >> n;
    vi v(n);
    for (int &i : v)
        cin >> i;
    // Unique Dict -> boolean
    cout << boolalpha << UniqOcc(v);
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