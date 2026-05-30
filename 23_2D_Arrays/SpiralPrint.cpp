// Problem Link: https://leetcode.com/problems/spiral-matrix/

/*
Given an m x n matrix, return all elements of the matrix in spiral order.
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
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

// Approach
// Print starting Row ans Increase Starting Row
// Print Ending Col and Decrease Ending Col
// Print Ending Row and Decrease Ending row
// Print Starting Col and Increase Starting Col

vector<int> SpiralPrint(vector<vector<int>> arr)
{
    int sR = 0, sC = 0, eR = arr.size() - 1, eC = arr[0].size() - 1;
    vector<int> temp;
    while (sR <= eR && sC <= eC)
    {
        // Starting Row
        for (int j = sC; j <= eC; j++)
            temp.push_back(arr[sR][j]);
        sR++;
        // Ending Column
        for (int i = sR; i <= eR; i++)
            temp.push_back(arr[i][eC]);
        eC--;
        // Ending Row
        if (sR <= eR)
        {
            for (int j = eC; j >= sC; j--)
                temp.push_back(arr[eR][j]);
            eR--;
        }
        // Starting Column
        if (sC <= eC)
        {
            for (int i = eR; i >= sR; i--)
                temp.push_back(arr[i][sC]);
            sC++;
        }
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
    vector<int> ans = SpiralPrint(arr);
    for (int i : ans)
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