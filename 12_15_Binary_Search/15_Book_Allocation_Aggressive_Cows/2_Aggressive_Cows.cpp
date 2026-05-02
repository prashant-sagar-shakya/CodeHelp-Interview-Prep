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

bool isPossible(vi &v, int k, int mid)
{
    int cows = 1;
    int lastPos = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] - lastPos >= mid)
        {
            cows++;
            lastPos = v[i];
        }
        if (cows >= k)
            return true;
    }
    return false;
}

int AggCows(vi &v, int k)
{
    sort(v.begin(), v.end());

    // Solution Exist -> store mid in ans and l = mid + 1;
    // No Solution -> r = mid - 1;
    int l = 0;
    int r = v.back() - v[0];
    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (isPossible(v, k, mid))
        {
            ans = mid;
            l = mid + 1; // maximize distance --> Because we need largest as our solution
        }
        else
            r = mid - 1;
    }
    return ans;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (auto &i : v)
        cin >> i;
    int k;
    cin >> k;
    cout << AggCows(v, k);
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