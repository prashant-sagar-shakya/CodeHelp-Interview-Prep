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
    /*
    int arr[10] = {2, 4, 5}; // 40 bytes if memory -> 10 * sizeof(int)
    // arr always represent address of first memory block of array
    cout << "Address of first memory block is " << arr << endl;
    // We can also use & for finding address
    cout << "Again! address of first memory block is " << &arr[0] << endl;

    // *arr -> used to dereference a value from array
    cout << *arr << endl;
    // *arr + 1 -> First derefence it then add
    // *(arr+1) -> First increase then deference

    // arr[i] = *(arr + i) is as same as i[arr] = *(arr + i)
    */

    /*
     int temp[10] = {1, 2, 3, 4, 5};
     cout << "size of temp array: " << sizeof(temp) << endl;
     cout << "1st: " << sizeof(*temp) << endl;
     cout << "2nd: " << sizeof(&temp) << endl;
     int *ptr = &temp[0];
     cout << "Size of pointer: " << sizeof(ptr) << endl;
     cout << "Size of value: " << sizeof(*ptr) << endl;
     cout << "Size of pointer: " << sizeof(&ptr) << endl;
    */

    /*
    int a[20] = {1, 2, 3, 5};
    // Address only -> Same thing
    cout << &a[0] << endl;
    cout << &a << endl;
    cout << a << endl;

    int *p = &a[0];
    cout << &p << endl;

    // The content of symbol table can't be changed
    */

    int arr[10];
    // ERROR
    // *arr=arr+1

    int *ptr = &arr[0];
    cout << ptr << endl;
    ptr = ptr + 1;
    cout << ptr << endl;

    char ch[6] = "abcde";
    cout << ch << endl; // It will print the entire string, it will sttoped at null character
    char *c = &ch[0];
    cout << c << endl; // It will print the entire string
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