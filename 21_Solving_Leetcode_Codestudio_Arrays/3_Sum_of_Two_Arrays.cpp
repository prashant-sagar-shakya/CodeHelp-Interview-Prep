// Problem Link: https://www.naukri.com/code360/problems/sum-of-two-arrays_893186

/*
You are given two numbers 'A' and 'B' in the form of two arrays (A[] and B[]) of lengths 'N' and 'M' respectively, where each array element represents a digit. You need to find the sum of these two numbers and return this sum in the form of an array.

Note:
1. The length of each array is greater than zero.
2. The first index of each array is the most significant digit of the number. For example, if the array A[] = {4, 5, 1}, then the integer represented by this array is 451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to return {7, 9, 6}.
3. Both numbers do not have any leading zeros in them. And subsequently, the sum should not contain any leading zeros.
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

/*
    Logic:
    -> We perform addition from right to left,
       just like normal mathematical addition.
    -> Use two pointers:
       i -> last index of first array
       j -> last index of second array
    -> Maintain a carry variable to store overflow.

    -> For every step:
       1. Start sum with carry
       2. Add current digit from first array if available
       3. Add current digit from second array if available
       4. Store last digit of sum in answer
       5. Update carry
    -> Continue until:
       - both arrays are completely traversed
       - and no carry remains
    -> Since digits are added from back to front,
       reverse the answer at the end.
*/

vi findArraySum(vi &a, int m, vi &b, int n)
{
    // Stores carry generated during addition
    int carry = 0;
    // Pointers for last index of first and second array
    int i = m - 1, j = n - 1;
    // Vector to store final answer
    vi ans;

    // Continue until all digits and carry are processed
    while (i >= 0 || j >= 0 || carry)
    {
        // Start current sum with carry
        int sum = carry;
        // Add digit from first array if available
        if (i >= 0)
            sum += a[i--];
        // Add digit from second array if available
        if (j >= 0)
            sum += b[j--];
        // Store current digit
        ans.push_back(sum % 10);
        // Update carry
        carry = sum / 10;
    }
    // Reverse to get correct order
    reverse(ans.begin(), ans.end());
    return ans;
}

// Your code here
void Solve()
{
    int m, n;
    cin >> m >> n;
    vi a(m), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;
    vi res = findArraySum(a, m, b, n);
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