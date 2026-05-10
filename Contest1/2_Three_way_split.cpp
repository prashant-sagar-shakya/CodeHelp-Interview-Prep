// Problem Link --> https://www.naukri.com/code360/contests/love-babbar-contest-l/3189127/problems/15017?leftPanelTabValue=PROBLEM&customSource=studio_nav
/*
Ninja has an array 'ARR' consisting of 'N' integers. Your primary work is to split it into three parts so that each integer is a component of a single part only. Each part must be a consecutive contiguous subsegment of the original array and can also be empty. So, the sum of each part is denoted as 'S1', 'S2' and 'S3'. Ninja made the problem even harder by declaring a condition that 'S1' must be equal to 'S3' and 'S1' must be the maximum possible amongst all possible ways.

The sum of the empty subsegment is 0.

EXAMPLE:
Input: 'N' = 5, ‘ARR’ = [5, 2, 4, 1, 4].
Output: 5
Explanation: We will split the array as [5], [2, 4] and [1, 4]. Thus, the maximum sum of the first part will be 5 and equal to the third part.
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
We want to split the array into 3 contiguous parts:
    [ S1 ] [ S2 ] [ S3 ]

such that:
    sum(S1) == sum(S3)
and this common sum is maximum possible.

Use two pointers:
    i -> starts from left
    j -> starts from right
Maintain:
    left_sum  -> sum from left side
    right_sum -> sum from right side
At every step:
    - Expand the side having smaller sum
    - Because only the smaller side can catch up
Whenever:
    left_sum == right_sum
we found a valid split.
Store this value as answer.

TIME COMPLEXITY: O(N) because each pointer moves at most N times.
*/

int maxEqualSum(vector<int> &arr)
{
    int n = arr.size();
    // Store size of array
    int i = 0, j = n - 1;
    // Two pointers:
    // i starts from beginning
    // j starts from end

    int left_sum = 0, right_sum = 0;
    // Stores prefix sum from left
    // Stores suffix sum from right

    int ans = 0;
    // Stores maximum equal sum found

    while (i <= j)
    {
        // If left sum is smaller (or equal),
        // expand the left side
        if (left_sum <= right_sum)
        {
            left_sum += arr[i]; // Add current left element
            i++;                // Move left pointer forward
        }
        else
        {
            // Otherwise expand the right side
            right_sum += arr[j]; // Add current right element
            j--;                 // Move right pointer backward
        }
        // If both sums become equal,
        // we found a valid partition
        if (left_sum == right_sum)
            ans = left_sum; // Store maximum equal sum
    }
    return ans;
    // Return maximum possible equal sum
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    cout << maxEqualSum(arr);
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