// Problem Link: https://www.naukri.com/code360/contests/love-babbar-contest-ii/3583551/problems/14871?leftPanelTabValue=PROBLEM&customSource=studio_nav

/*
You are given an array of integers(ARR) and Q queries.
Query Type-> X: Find the largest index IND such that ARR[1] & ARR[2] & …...ARR[IND] >=X
For each query, your task is to find out the largest index IND such that the bitwise and of elements in the array ARR from index 1 to IND is greater than equal to X.
Example:-
ARR = [3,7,9,16]
Q = 2
Query 1-> 2
Query 2-> 3
Answer for the first query is 2. (3 & 7 = 3 >= 2).
Answer for the second query is 3 (3 & 7 & 9 >= 1).
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

#include <bits/stdc++.h>
using namespace std;

/*
    Logic:
    We need to answer queries:
    Find the largest index IND such that:
    ARR[1] & ARR[2] & ... & ARR[IND] >= X

    Important Observation:
    Prefix AND is monotonic decreasing.
    Why?
    Because:
    a & b <= a
    As we include more elements,
    bits can only turn OFF, never ON.
    So:
    prefixAND[1] >= prefixAND[2] >= prefixAND[3] ...

    Step 1:
    Precompute prefix AND array.
    prefix[i] =
    arr[0] & arr[1] & ... & arr[i]

    Step 2:
    For every query X:
    Find the largest index where:
    prefix[i] >= X

    Since prefix array is monotonic decreasing,
    we can use Binary Search.
*/

vi bitwiseAnd(vi &arr, vi &queries)
{
    // Stores prefix AND values
    vi prefix(arr.size());
    // First prefix AND is first element itself
    prefix[0] = arr[0];
    // Compute prefix AND array
    for (int i = 1; i < arr.size(); i++)
        prefix[i] = prefix[i - 1] & arr[i];
    // Stores answers for all queries
    vi ans;
    // Process each query
    for (int x : queries)
    {
        int low = 0;
        int high = arr.size() - 1;
        // Stores largest valid index
        int res = -1;
        // Binary Search
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // Valid prefix AND
            if (prefix[mid] >= x)
            {
                res = mid;
                // Try finding larger index
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        // Convert 0-based to 1-based index
        ans.push_back(res + 1);
    }
    return ans;
}

// Your code here
void Solve()
{
    int n, q;
    cin >> n >> q;
    vi arr(n), queries(q);
    for (int &i : arr)
        cin >> i;
    for (int &i : queries)
        cin >> i;
    vi res = bitwiseAnd(arr, queries);
    for (int i : res)
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