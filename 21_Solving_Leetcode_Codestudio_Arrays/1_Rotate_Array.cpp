// Problem Link: https://leetcode.com/problems/rotate-array/
/*
Given an integer array v, rotate the array to the right by k steps, where k is non-negative.
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

void Rotate(vi &v, int k)
{
    k = k % v.size();
    reverse(v.begin(), v.end() - k);
    reverse(v.end() - k, v.end());
    reverse(v.begin(), v.end());
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
    Rotate(v, k);
    for (auto i : v)
        cout << i << " ";
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