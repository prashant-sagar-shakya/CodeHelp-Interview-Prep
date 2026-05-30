// Problem Link: https://www.naukri.com/code360/problems/print-like-a-wave_893268?leftPanelTabValue=SUBMISSION
/*
For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order, i.e., print the first column top to bottom, next column bottom to top, and so on.

For eg:-
The sine wave for the matrix:-
1 2
3 4
will be [1, 3, 4, 2].
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

vector<int> wavePrint(vector<vector<int>> arr, int m, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0) // Top to Bottom
            for (int j = 0; j < m; j++)
                temp.push_back(arr[j][i]);
        else // Bottom to Top
            for (int j = m - 1; j >= 0; j--)
                temp.push_back(arr[j][i]);
    }
    return temp;
}

// Your code here
void Solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    vector<int> ans = wavePrint(arr, m, n);
    for (auto i : ans)
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