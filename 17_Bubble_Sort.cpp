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

void Bubble_Sort(vi &v)
{
    int n = v.size();
    /*
        Bubble Sort Idea:
        -> Compare adjacent elements
        -> If left element is greater than right element,
           swap them
        -> After every pass, the largest unsorted element
           moves to its correct position at the end
           just like a bubble rises to the surface
    */

    // Loop for total passes
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        // Compare adjacent elements in unsorted part
        for (int j = 0; j < n - i - 1; j++)
        {
            // Swap if elements are in wrong order
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                flag = true;
            }
        }
        // If no swap happened, array is sorted
        if (!flag)
            break;
    }
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vi v(n);
    for (int &i : v)
        cin >> i;
    Bubble_Sort(v);
    for (int i : v)
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