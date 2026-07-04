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

// Your code here
void Solve()
{
    int num = 5;
    cout << num << endl;
    // Address of operator - &
    cout << "Address of num is " << &num << endl;

    // Pointers are used to store addresses
    int *ptr = &num; // *ptr can store the address of a variable
    // * is dereference operator used to dereference the value of a pointer

    cout << ptr << endl;
    cout << "Value is: " << *ptr << endl;
    // size of pointer is always 8 bytes

    /*
    // It will not execue because there is no any existance of zero memory, It is segmentation fault
    int *pointer = 0;
    cout << *pointer << endl;
    */

    /*
    int i = 5;
    int *q = &i;
    cout << q << endl;
    cout << *q << endl;

    int *p= 0;
    // reassigning the address
    p = &i;

    cout << p << endl;
    cout << *p << endl;
    */

    int n = 5;
    int a = n;
    cout << "n before a++: " << n << endl;
    a++;
    // No effect on n
    cout << "n after a++: " << n << endl;

    int *p = &n;
    cout << "Before *p++: " << n << endl;
    (*p)++;
    cout << "After *p++: " << n << endl;

    // Copying a pointer
    int *q = p;
    cout << p << " - " << q << endl;
    cout << *p << " - " << *q << endl;

    // Important Concept
    int i = 3;
    int *t = &i;
    // cout << (*t)++ << endl; // bracket is not must but recommended practice
    *t = *t + 1;
    cout << *t << endl;
    cout << "Before: " << t << endl;
    t = t + 1;
    cout << "After: " << t << endl;
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