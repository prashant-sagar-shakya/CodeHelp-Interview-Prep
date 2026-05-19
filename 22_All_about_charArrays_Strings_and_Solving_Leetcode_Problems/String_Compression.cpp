// Problem Link: https://leetcode.com/problems/string-compression/description/

/*
Given an array of characters chars, compress it using the following algorithm:
Begin with an empty string s. For each group of consecutive repeating characters in chars:
If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
After you are done modifying the input array, return the new length of the array.
You must write an algorithm that uses only constant extra space.
Note: The characters in the array beyond the returned length do not matter and should be ignored.
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
    This function performs string compression on the given character array.

    Compression Rule:
    - Consecutive repeating characters are replaced with:
            character + frequency

    Example:
    Input:
        ['a','a','b','b','c','c','c']
    Output Array:
        ['a','2','b','2','c','3']
    Returned Length:
        6

    Important:
    - Compression is done in-place.
    - Only the compressed length is returned.
    - If a character appears only once,
      frequency is NOT added.

    Approach:
    Use two pointers:
    1. i
       -> Traverses original array
       -> Finds groups of same characters
    2. res
       -> Stores compressed result position

    Steps:
    - Count consecutive repeating characters.
    - Store the character once.
    - If frequency > 1:
          convert frequency into string
          and store each digit separately.
    - Move to next group.
*/

int compress(vector<char> &chars)
{
    // Pointer to traverse original array
    int i = 0;
    // Pointer to store compressed result
    int res = 0;

    // Traverse entire character array
    while (i < chars.size())
    {
        // Initially assume current character appears once
        int groupLength = 1;
        // Count consecutive same characters
        while (i + groupLength < chars.size() && chars[i + groupLength] == chars[i])
            groupLength++;
        // Store current character in compressed array
        chars[res++] = chars[i];
        // If character appears more than once
        if (groupLength > 1)
        {
            // Convert frequency into string
            // Example: 12 -> "12"
            for (char c : to_string(groupLength))
            chars[res++] = c; // Store each digit separately
        }
        // Move to next group of characters
        i += groupLength;
    }
    // Return compressed length
    return res;
}

// Your code here
void Solve()
{
    string s;
    cin >> s;
    vector<char> chars;
    chars.insert(chars.end(), s.begin(), s.end()); // Storing string into vector of characters
    cout << compress(chars);
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