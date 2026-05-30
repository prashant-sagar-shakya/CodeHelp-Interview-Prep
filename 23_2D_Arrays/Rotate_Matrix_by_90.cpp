// Problem Link: https://leetcode.com/problems/rotate-image/description/
/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
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

void rotate(vector<vector<int>> &arr)
{
    // Step 1: Transpose the matrix
    // Transpose means converting rows into columns.
    // Example:
    // 1 2 3       1 4 7
    // 4 5 6  -->  2 5 8
    // 7 8 9       3 6 9
    //
    // To transpose in-place, we swap arr[i][j] with arr[j][i].
    // We only visit the lower triangle (j < i) to avoid swapping
    // the same pair twice.

    for (int i = 0; i < arr.size(); i++) // Traverse each row
    {
        for (int j = 0; j < i; j++) // Traverse elements below diagonal
        {
            // Swap symmetric elements across the main diagonal
            // Main diagonal elements (i == j) remain unchanged.
            swap(arr[i][j], arr[j][i]);
        }
    }

    // After transpose:
    // 1 2 3       1 4 7
    // 4 5 6  -->  2 5 8
    // 7 8 9       3 6 9

    // Step 2: Reverse every row
    // Reversing each row converts the transposed matrix
    // into a 90-degree clockwise rotated matrix.
    //
    // Example:
    // 1 4 7       7 4 1
    // 2 5 8  -->  8 5 2
    // 3 6 9       9 6 3

    for (int i = 0; i < arr.size(); i++) // Traverse every row
    {
        // Reverse the current row from left to right
        reverse(arr[i].begin(), arr[i].end());
    }
}

// Your code here
void Solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    rotate(arr);
    for (auto a : arr)
    {
        for (int i : a)
            cout << i << " ";
        cout << endl;
    }
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