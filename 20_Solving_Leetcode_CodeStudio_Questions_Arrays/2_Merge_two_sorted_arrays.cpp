// Problem Link: https://www.naukri.com/code360/problems/ninja-and-sorted-arrays_1214628?leftPanelTabValue=PROBLEM
/*
Ninja has been given two sorted integer arrays/lists ‘ARR1’ and ‘ARR2’ of size ‘M’ and ‘N’. Ninja has to merge these sorted arrays/lists into ‘ARR1’ as one sorted array. You may have to assume that ‘ARR1’ has a size equal to ‘M’ + ‘N’ such that ‘ARR1’ has enough space to add all the elements of ‘ARR2’ in ‘ARR1’.

For example:
‘ARR1’ = [3 6 9 0 0]
‘ARR2’ = [4 10]
After merging the ‘ARR1’ and ‘ARR2’ in ‘ARR1’.
‘ARR1’ = [3 4 6 9 10]
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

vector<int> ninjaAndSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
    // Write your code here.
    int i = 0, j = 0, k = 0;
    if (m == 0)
        return arr2;
    else if (n == 0)
        return arr1;
    else
    {
        vector<int> ans;
        while (i < m && j < n)
        {
            if (arr1[i] <= arr2[j])
                ans.push_back(arr1[i++]);
            else
                ans.push_back(arr2[j++]);
        }
        while (i < m)
            ans.push_back(arr1[i++]);
        while (j < n)
            ans.push_back(arr2[j++]);
        return ans;
    }
}

// Your code here
void Solve()
{
    int m, n;
    vi arr1(m), arr2(n);
    for (auto &i : arr1)
        cin >> i;
    for (auto &i : arr2)
        cin >> i;
    vi res = ninjaAndSortedArrays(arr1, arr2, m, n);
    for (auto i : res)
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