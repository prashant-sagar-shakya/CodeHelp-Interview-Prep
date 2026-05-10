// Problem Link -> https://www.naukri.com/code360/contests/love-babbar-contest-l/3189127/problems/14804
/* Ninja took you to an apple store where there is 'N' number of different apples present in the store and ith apple cost 'ARR[i]' coins. It is pre-decided that you have to buy all of them. You would be given a coupon by Ninja that allows you to buy ‘M’ apples while paying only for 'M - 1' most expensive apples. Thus, you will get the cheapest apple for free. You can use the coupon once only.

Now, Ninja requested you to tell the minimum total coins required to buy all apples if the coupon is used optimally. It is necessary to use the coupon and have to select ‘M’ apples for using it.

EXAMPLE:
Input: 'N' = 5, ‘ARR’ = [5, 2, 4, 1, 3], ‘M’ = 3.
Output: 12
Explanation: We will select apples present in indices(1 based) 1, 3, and 5. So, we will get apple at index five for free. Thus, the total coins that should be paid are 5 + 2 + 4 + 1 = 12.
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

// Logic
/*
Array ko sort karo ascending order me
Coupon ke liye M apples choose karo aise: group ka minimum element maximum ho
Iska best tarika: last M elements lo (sabse mehange apples)

M = number of apples jo aap coupon use karte waqt select karoge
Un M apples me:
aap M-1 most expensive apples ka paisa doge
sabse cheapest apple FREE milega
*/

long long appleAndCoupon(int n, int m, vector<int> &arr)
{
    // M = number of apples to select when you're applying coupon
    sort(arr.begin(), arr.end());
    ll total = 0;
    for (int x : arr)
        total += x;            // Total amount to Pay
    ll freeApple = arr[n - m]; // It is the most cheapest apple in m = 3 for the case -> n= 5, m = 3, arr = [5, 2, 4, 1 ,3]
    // After Sorting -> [1, 2, 3, 4, 5] so, [3, 4, 5] Most Expensive Apples we've to minimize the cost so M = 3
    // Free Apple  = arr[n-m] --> arr[5-3] = arr[2] = 3
    return total - freeApple;
}

// Your code here
void Solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    int m;
    cin >> m;
    cout << appleAndCoupon(n, m, arr);
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