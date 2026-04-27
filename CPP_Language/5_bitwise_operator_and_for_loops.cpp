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

// Your code here
void Solve()
{
    // Bitwise AND &
    // Biwise OR |
    // Bitwise NOT ~
    // Bitwise XOR ^
    int a = 5;
    // cout << ~a << endl; // ~x means -(x+1)
    // Left Shift << -> meaning a<<x it will be a * (2^x)
    // Right Shift >> -> meaning a>>x it will be a/(2^x)
    // Padding in case of positive number for left and right shit will be with zero only
    // But for -ve numbers it is compiler dependent
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