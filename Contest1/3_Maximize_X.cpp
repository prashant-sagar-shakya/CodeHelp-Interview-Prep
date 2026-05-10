// Problem Link --> https://www.naukri.com/code360/contests/love-babbar-contest-l/3189127/problems/14463?leftPanelTabValue=PROBLEM&customSource=studio_nav

/*
You have a total of 'B' candies and ‘N’ friends each having various demands for candies. You need to find the maximum possible value ‘X’ such that you can full fill all the demands having quantity less than or equal to ‘X’ of any of the friends. More formally, the value of all demands to be full-filled should be less than or equal to X and their total sum must be less than or equal to ‘B’.

Example:-
You have 3 friends and 20 total candies.

The first friend demands [1,2,3] candies,
The second friend demands [4,2,3] candies and
The third friend demands [1,10,2] candies.

So if you choose X as 9, demands fulfilled of 1st friend are [1,2,3], total = 6, demands fulfilled of 2nd friend are [4,2,3], total = 9, and demands fulfilled of the third friend are [1,2], total = 3.

So total candies used is 6+9+3=18 which is less than B(20). So X=9 is possible. (You have to find the maximum such value of X).
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

/*
We need to find the maximum value X such that:
    sum of all demands <= X  <= B

Observation:
If some X is valid,
then every smaller value is also valid.

This is a MONOTONIC property,
so we can apply Binary Search on X.
*/

int findMaxX(int n, vector<vector<int>> &arr, int b)
{
    // Find the maximum demand value
    // Binary Search range will be [0 ... maximum]
    int maximum = 0;

    for (int i = 0; i < n; i++)
    {
        // arr[i][0] stores count of demands
        for (int j = 1; j <= arr[i][0]; j++)
            maximum = max(maximum, arr[i][j]);
    }

    int st = 0;
    int end = maximum;
    // Stores final maximum valid X
    int ans = 0;

    // Binary Search on X
    while (st <= end)
    {
        int x = (st + end) / 2;
        // Total candies used for current X
        int total = 0;

        // Traverse all friends
        for (int i = 0; i < n; i++)
        {
            // Traverse all demands of current friend
            for (int j = 1; j <= arr[i][0]; j++)
            {
                // Take only those demands
                // whose value is <= current X
                if (arr[i][j] <= x)
                    total += arr[i][j];
            }
        }

        // Current X is valid
        if (total <= b)
        {
            ans = x;
            // Try to maximize X
            st = x + 1;
        }
        else
        {
            // Too many candies used
            // Reduce X
            end = x - 1;
        }
    }
    return ans;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    int b;
    cin >> b;
    cout << findMaxX(n, arr, b);
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