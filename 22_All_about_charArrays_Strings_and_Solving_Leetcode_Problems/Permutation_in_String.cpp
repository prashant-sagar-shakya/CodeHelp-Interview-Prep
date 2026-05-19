// Problem Link: https://leetcode.com/problems/permutation-in-string/description/

/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.
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
What is Permutation?
------------------------------------------------

Permutation means arranging the same characters
or elements in different possible orders.

Example:
String = "abc"

Possible permutations:
abc
acb
bac
bca
cab
cba
The characters remain the same,
only their order changes.

Logic We use:
1. Frequency Count
2. Sliding Window

Why Frequency Count?
In permutations, order does NOT matter.
Only character frequencies should match.

Example:
"ab" and "ba"
Both have:
a -> 1
b -> 1

So instead of generating all permutations, we simply compare frequencies.

1. Store frequency of s1 characters.
2. Create a sliding window in s2
   having size equal to s1.size().
3. Keep updating frequency of the current window.
4. If current window frequency becomes equal
   to s1 frequency,
   then permutation exists.
*/

bool checkInclusion(string &s1, string &s2)
{
    // If s1 is larger than s2, permutation is impossible
    if (s1.size() > s2.size())
        return false;
    // Frequency array for current window in s2
    vector<int> arr(26, 0);
    // Frequency array for s1
    vector<int> def(26, 0);

    // Store frequency of characters of s1
    for (char it : s1)
        def[it - 'a']++;

    // Size of sliding window
    int n1 = s1.size();
    // Left pointer of sliding window
    int left = 0;

    // Traverse s2
    for (int i = 0; i < s2.size(); i++)
    {
        // Add current character into window
        arr[s2[i] - 'a']++;
        // If window size becomes greater than n1, remove leftmost character
        if (i - left + 1 > n1)
            arr[s2[left++] - 'a']--;
        // When window size becomes exactly n1 then compare frequencies, if equal -> permutation found
        if (i - left + 1 == n1 && (arr == def))
            return true;
    }
    // No permutation found
    return false;
}

// Your code here
void Solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << checkInclusion(s1, s2);
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