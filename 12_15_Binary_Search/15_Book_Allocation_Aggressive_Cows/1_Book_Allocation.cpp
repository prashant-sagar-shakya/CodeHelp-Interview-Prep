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

bool isPossible(vector<int> &arr, int k, int mid)
{
    int studentCount = 1, pageSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (pageSum + arr[i] <= mid)
            pageSum += arr[i];
        else
        {
            studentCount++;
            if (studentCount > k || arr[i] > mid)
                return false;
            pageSum = arr[i];
        }
    }
    return true;
}
int BookAllocation(vector<int> &arr, int k)
{
    if (k > arr.size())
        return -1;
    int l = *max_element(arr.begin(), arr.end()), r = accumulate(arr.begin(), arr.end(), 0), ans = -1;

    // IsPossible -> Store mid in ans -> r = mid -1
    // Not Possible -> l = mid + 1

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (isPossible(arr, k, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

//  Same Problem -> https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (int &i : v)
        cin >> i;
    int m; // Number of students
    cin >> m;
    cout << BookAllocation(v, m);
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