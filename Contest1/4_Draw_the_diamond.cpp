// Problem Link --> https://www.naukri.com/code360/contests/love-babbar-contest-l/3189127/problems/16513?leftPanelTabValue=PROBLEM&customSource=studio_nav

/*
You have to print a regular grid pattern of 'R' rows and 'C' columns with a diamond-like shape of size 'S' in each cell of the grid. The diamond shape will contain ‘/’ and ‘\’ characters to represent the borders of the diamond and ‘o’ (small ‘o’ alphabet) to represent the space inside the diamond and ‘e’(small ‘e’ alphabet) to represent the rest of the space of diamond.

For example:

e/\e
/oo\
\oo/
e\/e

The above diagram represents a grid of 1 Row and 1 Column and a diamond of size 2 in its single cell(i.e. each side of the diamond has length 2).
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
Each diamond has:
    height = 2*S
    width  = 2*S

We build the diamond row by row.

TOP HALF:
    '/'  -> left boundary
    '\'  -> right boundary
    'o'  -> inside diamond
    'e'  -> outside diamond

BOTTOM HALF:
    Mirror image of top half.

Then repeat the same diamond:
    - C times horizontally
    - R times vertically
*/
void printTheDiamond(int r, int c, int s)
{
    int totalRows = 2 * s;

    // Repeat for each grid row
    for (int gridRow = 0; gridRow < r; gridRow++)
    {
        // Traverse rows of one diamond
        for (int i = 0; i < totalRows; i++)
        {
            // Print C diamonds horizontally
            for (int gridCol = 0; gridCol < c; gridCol++)
            {
                // Traverse columns of one diamond
                for (int j = 0; j < 2 * s; j++)
                {
                    // ---------------- TOP HALF ----------------
                    if (i < s)
                    {
                        int leftSlash = s - i - 1;
                        int rightSlash = s + i;

                        if (j == leftSlash)
                            cout << '/';
                        else if (j == rightSlash)
                            cout << '\\';
                        else if (j > leftSlash && j < rightSlash)
                            cout << 'o';
                        else
                            cout << 'e';
                    }

                    // ---------------- BOTTOM HALF ----------------
                    else
                    {
                        int leftSlash = i - s;
                        int rightSlash = 3 * s - i - 1;

                        if (j == leftSlash)
                            cout << '\\';
                        else if (j == rightSlash)
                            cout << '/';
                        else if (j > leftSlash && j < rightSlash)
                            cout << 'o';
                        else
                            cout << 'e';
                    }
                }
            }

            cout << '\n';
        }
    }
}

// Your code here
void Solve()
{
    int r, c, s;
    cin >> r >> c >> s;
    printTheDiamond(r, c, s);
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