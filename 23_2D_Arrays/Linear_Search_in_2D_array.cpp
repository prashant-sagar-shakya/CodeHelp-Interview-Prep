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

vector<int> LinearSearch(int arr[][4], int target)
{
    // We can receive arrays like this too, having dynamic number of row but passing number of cols is mandatory
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            if (arr[i][j] == target)
                return {i, j};
    }
    return {-1, -1};
}

// Your code here
void Solve()
{
    int arr[3][4];

    // input
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cin >> arr[i][j];
    }
    int target;
    cin >> target;
    vi ans = LinearSearch(arr, target);
    cout << ans[0] << " " << ans[1];
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