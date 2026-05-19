// Problem Link: https://www.naukri.com/code360/problems/replace-spaces_1172172?leftPanelTabValue=PROBLEM

/*
You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 50
0 <= |STR| <= 100
Where ‘|STR|’ is the length of a particular string including spaces.
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

string replaceSpaces(string &s)
{
    int spaceCount = 0;

    // Step 1:
    // Count total number of spaces present in string
    for (int i = 0; i < s.length(); i++)
        if (s[i] == ' ')
            spaceCount++;
    // Store original length of string
    int oldLength = s.length();

    // Step 2:
    // Resize string to make space for extra characters
    // Every ' ' becomes "@40"
    // 1 character -> 3 characters
    // So, extra 2 characters required for each space
    s.resize(oldLength + spaceCount * 2);
    // i -> points to original string end
    int i = oldLength - 1;
    // j -> points to new resized string end
    int j = s.length() - 1;

    // Step 3:
    // Traverse string from back side
    // This avoids overwriting characters
    while (i >= 0)
    {
        // If current character is space
        if (s[i] == ' ')
        {
            // Replace space with "@40"
            s[j--] = '0';
            s[j--] = '4';
            s[j--] = '@';
        }
        else
            s[j--] = s[i]; // Copy normal character
        // Move to previous character
        i--;
    }
    // Return modified string
    return s;
}

// Your code here
void Solve()
{
    string s;
    getline(cin, s);
    cout << replaceSpaces(s);
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