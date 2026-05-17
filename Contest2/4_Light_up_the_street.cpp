// Problem Link: https://www.naukri.com/code360/contests/love-babbar-contest-ii/3583551/problems/14751?leftPanelTabValue=PROBLEM&customSource=studio_nav

/*
You are walking on a street of length ‘N’. You want to light up the street by installing street lights.
There are 'M' streetlights and the 'ith' streetlight can be installed at position 'Ci'.
You are also given the range of the streetlights 'R' which means that the 'ith' streetlight installed at position 'Ci' will enlighten street from 'Ci-R' to 'Ci+R'.
Output the minimum number of street lights required to light up the whole street or output -1 if it is impossible to light the whole street under the given conditions.
It is sufficient to enlighten the integer positions, it is not required to enlighten the area between two integer positions.
For example : 'N' = 8, 'M' = 2, 'C' = [1, 6], 'R' = 2. The answer for this case is 2 as we can enlighten streetlight at position 1 and streetlight at position 6. These two will enlighten the positions 1, 2, 3, 4, 5, 6, 7, 8.
Example:-
N=10, M=3
C = [2,4,7] ( The positions of the streetlights )
R = 3 ( The range of the street-lights)
The answer will be 2 as we can install the first street light at position 2 so it illuminates the street from positions from 1 to 5 and the third street light at 7 so it illuminates the street from positions from 4 to 10.
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
    Each street light at position C[i]
    covers the range:
    [ C[i] - K , C[i] + K ]
    We need to illuminate the complete street
    from position 1 to N.

    Greedy Idea:
    -> Always choose the street light that
       extends coverage as far as possible.
    -> Similar to minimum intervals required
       to cover a line segment.

    Steps:
    1. Convert every street light into
       an interval:
       left  = max(1, C[i] - K)
       right = min(N, C[i] + K)
    2. Sort intervals by left endpoint.
    3. Start covering street from position 1.
    4. Among all intervals whose
       left <= current_position,
       choose the one with maximum right.
    5. Move current_position forward.
    6. Repeat until whole street is covered.
    7. If at any point no interval can
       cover current_position,
       answer is impossible.
*/

int LightUptheStreet(int n, int k, vi &Checkpoints)
{
    // Stores all coverage intervals
    vector<pair<int, int>> intervals;
    // Create intervals for every street light
    for (int pos : Checkpoints)
    {
        int left = max(1, pos - k);
        int right = min(n, pos + k);
        intervals.push_back({left, right});
    }
    // Sort by starting point
    sort(intervals.begin(), intervals.end());
    // Current position to cover
    int curr = 1;
    // Pointer for intervals
    int i = 0;
    // Count of selected street lights
    int lights = 0;
    // Continue until whole street is covered
    while (curr <= n)
    {
        // Farthest reachable position
        int farthest = curr - 1;
        // Find best interval covering curr
        while (i < Checkpoints.size() && intervals[i].first <= curr)
            farthest = max(farthest, intervals[i++].second);
        // No interval can cover current position
        if (farthest < curr)
            return -1;
        // Use one street light
        lights++;
        // Move to next uncovered position
        curr = farthest + 1;
    }
    return lights;
}

// Your code here
void Solve()
{
    int n, m;
    cin >> n >> m;
    vi Checkpoints(m);
    for (auto &i : Checkpoints)
        cin >> i;
    int k;
    cin >> k;
    cout << LightUptheStreet(n, k, Checkpoints);
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