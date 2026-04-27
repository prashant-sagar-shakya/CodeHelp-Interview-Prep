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

int MAX(int *arr, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
            maxi = arr[i];
    }
    return maxi;
}

int MIN(int *arr, int n)
{
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < mini)
            mini = arr[i];
    }
    return mini;
}

int LiSearch(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

void Rev(int *arr, int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(arr[i++], arr[j--]);
    }
}

// Your code here
void Solve()
{
    // Max and Min in arays
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << MAX(arr, n) << endl;
    cout << MIN(arr, n) << endl;
    int x;
    cin >> x;
    cout << LiSearch(arr, n, x) << endl;
    Rev(arr, n);
    for (int i : arr)
        cout << i << " ";
    cout << endl;

    // ==============================More on Arrays===============================
    // Swap Alternate
    // Find Unique Element in Array
    // Find Duplicate
    // Pair Sum
    // Triplet Sum
    // Find Intersection
    // Sort 0's and 1's
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