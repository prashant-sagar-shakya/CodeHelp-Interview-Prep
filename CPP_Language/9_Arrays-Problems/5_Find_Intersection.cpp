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

// Find Intersection
vector<int> Intersection(int *arr1, int *arr2, int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    vector<int> res;
    while (i < n1 && j < n2)
    {
        if (arr1[i] == arr2[j])
        {
            res.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
            j++;
    }
    return res;
}

// Your code here
void Solve()
{
    int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1];
    int arr2[n2];
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];
    vector<int> res = Intersection(arr1, arr2, n1, n2);
    for (int i : res)
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