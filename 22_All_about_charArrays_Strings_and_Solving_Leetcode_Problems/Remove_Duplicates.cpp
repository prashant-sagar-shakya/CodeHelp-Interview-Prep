// Problem Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

/*
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define endl '\n'

const ll MOD = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
Logic:

We use the original string itself like a stack.
Idea:
- Keep adding characters one by one.
- If current character becomes same
  as previous character,
  remove both.
*/

string removeDuplicates(string &s)
{
    // i behaves like stack top pointer
    int i = 0;
    // Length of string
    int n = s.length();
    // j traverses the original string
    for (int j = 0; j < n; ++j, ++i)
    {
        // Put current character at stack position
        s[i] = s[j];
        // If current character and previous character are same, remove both
        if (i > 0 && s[i - 1] == s[i])
            i -= 2; // Remove duplicate pair
    }
    // Return final valid part of string
    return s.substr(0, i);
}

// Your code here
void Solve()
{
    string s;
    cin>>s;
    cout << removeDuplicates(s);
}

// Driver code
int main() {
    fastio();
    int t = 1;
    // cin >> t;
    while (t--) Solve();
    return 0;
}