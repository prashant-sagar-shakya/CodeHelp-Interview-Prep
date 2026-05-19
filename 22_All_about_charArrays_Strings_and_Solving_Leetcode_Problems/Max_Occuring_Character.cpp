// Problem Link: https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1

/*
Given a string s of lowercase alphabets. The task is to find the maximum occurring character in the string s. If more than one character occurs the maximum number of times then print the lexicographically smaller character.

Examples:
Input: s = "testsample"
Output: 'e'
Explanation: 'e' is the character which is having the highest frequency.
Input: s = "output"
Output: 't'
Explanation: 't' and 'u' are the characters with the same frequency, but 't' is lexicographically smaller.
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
    Logic:
    1. Create an array of size 26 to store frequency of characters.
       Example:
       index 0 -> 'a'
       index 1 -> 'b'
       ...
       index 25 -> 'z'
    2. Traverse the string and increase frequency count
       of each character.
    3. Traverse the frequency array to find the character
       having maximum frequency.
    4. Convert index back to character using:
           'a' + index
*/

char getMaxOccuringChar(string &s)
{
    // Array to store frequency of each character
    int count[26] = {0};
    // Traverse the string
    for (int i = 0; i < s.size(); i++)
    {
        // Convert character into index
        // Example:
        // 'a' - 'a' = 0
        // 'b' - 'a' = 1
        // 'z' - 'a' = 25
        count[s[i] - 'a']++;
    }
    // Store index of maximum frequency character
    int ansIndex = 0;
    // Initially assume first character frequency is maximum
    int freq = count[0];
    // Traverse frequency array
    for (int i = 0; i < 26; i++)
    {
        // If current frequency is greater than maximum frequency
        if (count[i] > freq)
        {
            // Update maximum frequency
            freq = count[i];
            // Store current index
            ansIndex = i;
        }
    }

    // Convert index back to character
    char ans = 'a' + ansIndex;

    return ans;
}

// Your code here
void Solve()
{
    string s;
    getline(cin, s);
    cout << getMaxOccuringChar(s);
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