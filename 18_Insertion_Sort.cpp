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

void Insertion_Sort(vi &v)
{
    int n = v.size();

    /*
        Insertion Sort Idea:
        -> Divide array into two parts:
           1. Sorted part
           2. Unsorted part
        -> Take one element from unsorted part
           and place it at its correct position
           in the sorted part
        -> Similar to arranging playing cards
           in hands
    */

    // Start from second element
    for (int i = 1; i < n; i++)
    {
        // Current element to insert
        int key = v[i];
        // Previous index
        int j = i - 1;
        // Shift greater elements one position ahead
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        // Place current element at correct position
        v[j + 1] = key;
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
    Insertion_Sort(v);
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