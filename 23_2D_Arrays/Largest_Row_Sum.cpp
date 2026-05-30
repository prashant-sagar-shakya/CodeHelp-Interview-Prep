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

int LargestRowSum(vector<vector<int>> arr)
{
    int maxi = INT_MIN, Row_number = -1; // 0-based indexing
    for (int i = 0; i < arr[0].size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < arr.size(); j++)
            sum += arr[i][j];
        if (sum > maxi)
        {
            maxi = sum;
            Row_number = i;
        }
    }
    cout << "Largest row index with max sum is " << Row_number << endl;
    return maxi;
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
    cout << LargestRowSum(arr);
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