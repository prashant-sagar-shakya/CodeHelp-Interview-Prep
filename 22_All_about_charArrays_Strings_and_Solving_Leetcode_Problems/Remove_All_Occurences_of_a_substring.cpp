// Problem Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/solutions/6386401/remove-all-occurrences-of-a-substring-by-wd1d/

/*
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.
A substring is a contiguous sequence of characters in a string.
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

string removeOccurrences(string &s, string &part)
{
    // Step 1:
    // Continue loop until 'part' is no longer present in string 's'
    while (s.find(part) != string::npos)
    {

        // Step 2:
        // Find index of first occurrence of substring 'part'
        size_t part_start_index = s.find(part);

        // Step 3:
        // Remove the substring from string
        //
        // s.substr(0, part_start_index)
        // -> Takes characters before 'part'
        //
        // s.substr(part_start_index + part.length())
        // -> Takes characters after 'part'
        //
        // Both parts are concatenated to form new string
        s = s.substr(0, part_start_index) +
            s.substr(part_start_index + part.length());
    }

    // Step 4:
    // Return final modified string
    return s;
}

// One more Optimal Solution using STL functions
/*
string removeOccurrences(string s, string part)
{

    // Step 1:
    // Continue loop until:
    // - string is not empty
    // - substring 'part' exists in string 's'
    while (s.length() > 0 && s.find(part) < s.length())
    {

        // Step 2:
        // Find index where 'part' first occurs
        int index = s.find(part);

        // Step 3:
        // Remove substring starting from 'index'
        //
        // erase(start_index, number_of_characters)
        //
        // Example:
        // s = "daabcbaabcbc"
        // part = "abc"
        //
        // erase(2, 3)
        // removes "abc"
        s.erase(index, part.length());
    }

    // Step 4:
    // Return final modified string
    return s;
}
*/

// Your code here
void Solve()
{
    string s, part;
    cin >> s >> part;
    cout << removeOccurrences(s, part);
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