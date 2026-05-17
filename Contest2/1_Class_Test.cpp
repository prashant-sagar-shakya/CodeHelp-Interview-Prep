// Problem Link: https://www.naukri.com/code360/contests/love-babbar-contest-ii/3583551/problems/14818

/*
Ninja recently appeared for a class test. The test was attended by ‘N’ students and the marks of each student was given in an array ‘A’.
Ninja knows that he got a rank ‘K’ among the ‘N’ students but forgot the marks achieved by him. The ranks are given according to the better marks scored by the students.
Tell the marks that must have been scored by Ninja to get a rank ‘K’.
Example :
N = 5
K = 3
A = [ 2, 5, 4, 4, 5 ]
Rank 1 and Rank 2 students get marks = 5.
Rank 3 and Rank 4 students get marks = 4.
Rank 5 student gets marks = 2.
So, Ninja must have scored 4 marks in order to achieve Rank = 3.
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

/*
    We've to find Kth Largest Element of Array
    -> Similar to Quick Sort partitioning.
    -> Choose a pivot element.
    -> Place all greater elements on left side
       because we need K-th largest element.
    -> Pivot reaches its correct position.
    -> If pivot index == k-1
       then we found the answer.
    -> Otherwise:
       search left or right half accordingly.
*/

// Partition function
int partition(vi &v, int low, int high)
{
    // Choose last element as pivot
    int pivot = v[high];
    // Index for placing greater elements
    int i = low;
    for (int j = low; j < high; j++)
    {
        // Put greater elements on left side
        if (v[j] > pivot)
            swap(v[i++], v[j]);
    }
    // Place pivot at correct position
    swap(v[i], v[high]);
    return i;
}

// Quick Select function
int quickSelect(vector<int> &v, int low, int high, int k)
{
    // Partition array
    int pivotIdx = partition(v, low, high);
    // Found K-th largest element
    if (pivotIdx == k - 1)
        return v[pivotIdx];
    // Search left side
    if (pivotIdx > k - 1)
        return quickSelect(v, low, pivotIdx - 1, k);
    // Search right side
    return quickSelect(v, pivotIdx + 1, high, k);
}

int Class_Test(vector<int> &v, int k)
{
    return quickSelect(v, 0, v.size() - 1, k);
}

/*
// Using STL

 -> Use nth_element()
    -> It rearranges the array such that:
       the element at index (k-1)
       becomes the same element that would
       appear there in sorted order.
    -> We use greater<int>()
       because we need K-th largest element.

int Class_Test(vector<int> &v, int k)
{
    // Place K-th largest element at index (k-1)
    nth_element(v.begin(), v.begin() + (k - 1), v.end(), greater<int>());
    // Return K-th largest element
    return a[k - 1];
}
*/

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    int k;
    cin >> k;
    cout << Class_Test(v, k);
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