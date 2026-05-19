// Problem Link: https://leetcode.com/problems/valid-palindrome/description/

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
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

bool Valid_Palindrome(string &s)
{
    if (s.length() == 1)
        return true;
    string str = ""; // A new string to store processed string
    for (int i = 0; i < s.length(); i++)
        if (isalnum(s[i])) // isalnum is the function to check whether the charater is a number of a character rather than special characters like this if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
            str += s[i];
    transform(str.begin(), str.end(), str.begin(), ::toupper); // Transforming the string to uppercase and storing in same str string

    // Checking Palindrome
    int i = 0, j = str.length() - 1;
    while (i < j)
    {
        if (str[i++] != str[j--])
            return false;
    }
    return true;
}

// One more Optimal Soluion using alnum
/*
bool isPalindrome(string s)
{
    // Left pointer starts from the beginning
    int i = 0;
    // Right pointer starts from the end
    int j = s.length() - 1;

    // Continue until both pointers cross each other
    while (i <= j)
    {
        // -------------------------------------------------
        // SKIP NON-ALPHANUMERIC CHARACTERS FROM LEFT
        // -------------------------------------------------
        // isalnum(ch) checks whether the character is:
        // - a letter (A-Z or a-z)
        // - or a digit (0-9)
        //
        // Examples:
        // isalnum('A') -> true
        // isalnum('7') -> true
        // isalnum(' ') -> false
        // isalnum(',') -> false
        //
        // If current character is NOT alphanumeric,
        // move the left pointer forward.
        //
        while (i <= j && !isalnum(s[i]))
            i++;

        // -------------------------------------------------
        // SKIP NON-ALPHANUMERIC CHARACTERS FROM RIGHT
        // -------------------------------------------------
        // Same logic for the right side.
        //
        while (j >= i && !isalnum(s[j]))
            j--;

        // -------------------------------------------------
        // EDGE CASE
        // -------------------------------------------------
        // If the string contains only special characters,
        // pointers may cross after skipping.
        //
        // Example:
        // "!!!"
        //
        // Such a string is considered a palindrome.
        //
        if (i > j)
            return true;

        // -------------------------------------------------
        // COMPARE CHARACTERS
        // -------------------------------------------------
        // tolower(ch) converts a character into lowercase.
        //
        // This makes comparison case-insensitive.
        //
        // Example:
        // 'A' and 'a' should be treated as equal.
        //
        // tolower('A') -> 'a'
        //
        if (tolower(s[i]) != tolower(s[j]))
            return false;

        // -------------------------------------------------
        // MOVE BOTH POINTERS
        // -------------------------------------------------
        // Characters matched, so move inward.
        //
        i++;
        j--;
    }

    // If the loop finishes without mismatch,
    // the string is a palindrome.
    //
    return true;
}
*/

// Your code here
void Solve()
{
    string s;
    getline(cin, s);
    cout << boolalpha << Valid_Palindrome(s);
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