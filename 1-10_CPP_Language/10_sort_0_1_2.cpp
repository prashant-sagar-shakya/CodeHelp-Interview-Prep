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

void DNF(int *arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    // arr[mid] == 0 swap(arr[low], arr[mid]), low++, mid++
    // arr[mid] == 1 mid++
    // arr[mid] == 2 swap(arr[mid], arr[high]), high--
    while (mid <= high)
    {
        if (arr[mid] == 0)
            swap(arr[low++], arr[mid++]);
        else if (arr[mid] == 1)
            mid++;
        else if (arr[mid] == 2)
            swap(arr[mid], arr[high--]);
    }
}

// Your code here
void Solve()
{
    // Dutch National Flag Algo
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    DNF(arr, n);
    for (int i : arr)
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