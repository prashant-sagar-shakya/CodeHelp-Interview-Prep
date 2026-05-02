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

int Pivot(vi &v)
{
    int l = 0, r = v.size() - 1, mid = 0;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (v[mid] > v[r])
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int Search(vi &v, int l, int r, int target)
{
    int mid = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (v[mid] == target)
            return mid;
        else if (v[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1; // Not Found
}

/*

// Single Pass Approach

int Search(vi &v, int target)
{
    int l = 0, r = v.size() - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (v[mid] == target)
            return mid;

        // Left sorted part
        if (v[l] <= v[mid])
        {
            if (v[l] <= target && target < v[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        // Right sorted part
        else
        {
            if (v[mid] < target && target <= v[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}

*/

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (auto &i : v)
        cin >> i;
    int target;
    cin >> target;
    int pivot = Pivot(v);
    if (v[pivot] <= target && target <= v[n - 1])
        cout << Search(v, pivot, n - 1, target);
    else
        cout << Search(v, 0, pivot - 1, target);
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