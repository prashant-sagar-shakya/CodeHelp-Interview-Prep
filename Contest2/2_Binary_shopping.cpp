// Problem Link: https://www.naukri.com/code360/contests/love-babbar-contest-ii/3583551/problems/15566?leftPanelTabValue=PROBLEM&customSource=studio_nav

/*
Bob is out to buy a binary string of size ‘N’. The shopkeeper gave him an integer ‘P’, a binary string ‘S’ and defined its cost as :
Cost = S[0] * (P^0) + S[1] * (P^1) + S[2] * (P^2) … S[N - 1] * (P^(n-1))
Since Bob was an old customer, the shopkeeper allowed him to do exactly two operations on this string to make its cost as low as possible.
In each operation, Bob can select any index and flip its bit, i.e if it was ‘0’ it will become ‘1’ or vice versa. Bob can select a single index multiple times.
Help Bob find the final string with minimum possible cost after performing exactly two operations on the given string.
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
    Logic: Minimize String
    Cost = S[0] * P^0 +
           S[1] * P^1 +
           ...
           S[n-1] * P^(n-1)
    We must perform EXACTLY two flips.

    Case 1: P == 0
    -> Only index 0 contributes to cost.
    -> Cost becomes:
       S[0]
    -> To minimize:
       final S[0] should be 0.
    -> Remaining operation can be done
       on same index twice or elsewhere.

    Case 2: P == 1
    -> Every position contributes equally.
    -> Cost = number of 1s.
    -> Best strategy:
       remove maximum possible 1s.
    -> If at least two 1s:
          flip two 1s -> 0
    -> If exactly one 1:
          one 1 removed,
          one 0 must become 1
          final count unchanged
    -> If no 1:
          flip same bit twice

    Case 3: P > 1
    -> Higher indices contribute more.
    -> Best strategy:
       flip highest indexed 1s to 0.

*/

string binaryShopping(string S, int P)
{
    int n = S.size();
    // Case 1: P == 0
    if (P == 0)
    {
        // Make first bit 0
        if (S[0] == '1')
        {
            S[0] = '0';
            // Second operation:
            // flip same index again then back
            S[0] = '0';
        }
        return S;
    }
    // Store positions of all 1s
    vi ones;

    for (int i = 0; i < n; i++)
        if (S[i] == '1')
            ones.push_back(i);
    // Case 2 and 3:
    // At least two 1s
    if (ones.size() >= 2)
    {
        // Remove highest indexed 1
        S[ones.back()] = '0';
        // Remove second highest indexed 1
        S[ones[ones.size() - 2]] = '0';
    }
    // Exactly one 1
    else if (ones.size() == 1)
    {
        // Remove existing 1
        S[ones[0]] = '0';
        // One more operation compulsory
        // Add 1 at minimum cost position
        S[0] = '1';
    }
    // No 1 present
    // Flip same bit twice -> unchanged
    return S;
}

// Your code here
void Solve()
{
    int n, P;
    cin >> n >> P;
    string S;
    cin >> S;
    cout << binaryShopping(S, P);
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