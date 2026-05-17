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

void MoveZerosEnd(vi &v)
{
    int i = 0, j = 0;
    while (i < v.size())
    {
        if (v[i] == 0)
            i++;
        else
            swap(v[i++], v[j++]);
    }
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (auto &i : v)
        cin >> i;
    MoveZerosEnd(v);
    for (auto &i : v)
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