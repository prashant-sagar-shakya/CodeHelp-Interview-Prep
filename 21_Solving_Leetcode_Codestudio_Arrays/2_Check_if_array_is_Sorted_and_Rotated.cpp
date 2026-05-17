// Problem Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
/*
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.
There may be duplicates in the original array.
Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.
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

bool check(vector<int> &nums)
{
    vector<int> v;
    int cnt = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] <= nums[i + 1])
            cnt++;
        else
            break;
    }
    for (int i = cnt + 1; i < nums.size(); i++)
        v.push_back(nums[i]);
    for (int i = 0; i <= cnt; i++)
        v.push_back(nums[i]);
    for (auto i : v)
        cout << i << " ";
    for (int i = 0; i < nums.size() - 1; i++)
        if (v[i] > v[i + 1])
            return false;
    return true;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vi nums(n);
    for (auto &i : nums)
        cin >> i;
    cout << check(nums);
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