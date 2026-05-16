/*
================================================================================
                    SECTION 1: ARRAY (STL)
================================================================================

What is std::array?
- It's a fixed-size container that wraps C-style arrays
- Size must be known at COMPILE TIME (like regular arrays)
- Lives on STACK (not heap) - faster allocation
- Has bound checking with .at() method

Key Features:
- Fixed size (template parameter)
- Contiguous memory (like regular arrays)
- Can use STL algorithms on it
- Has iterators like other containers

When to use:
- When you know the exact size at compile time
- When you want stack allocation for small arrays
- When you want to use STL algorithms on fixed-size data

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "        ARRAY (STL)" << endl;
    cout << "==========================================" << endl;

    // ========================================================================
    // CREATING ARRAYS
    // ========================================================================

    // Method 1: Declare empty array of size 5 (all elements uninitialized)
    array<int, 5> arr1;

    // Method 2: Initialize with specific values
    array<int, 5> arr2 = {1, 2, 3, 4, 5};

    // Method 3: Initialize with all same values using fill()
    array<int, 5> arr3;
    arr3.fill(10); // Sets all elements to 10

    // Method 4: Initialize with zeros (default for primitive types)
    array<int, 5> arr4 = {}; // All elements = 0

    cout << "\n--- CREATING ARRAYS ---" << endl;
    cout << "arr2 elements: ";
    for (int x : arr2)
        cout << x << " ";
    cout << endl;

    cout << "arr3 filled with 10: ";
    for (int x : arr3)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // ACCESSING ELEMENTS
    // ========================================================================

    cout << "\n--- ACCESSING ELEMENTS ---" << endl;

    // Method 1: Using [] operator (NO bounds checking - faster but unsafe)
    // If you access invalid index, it's undefined behavior!
    cout << "arr2[0] = " << arr2[0] << endl; // Output: 1
    cout << "arr2[4] = " << arr2[4] << endl; // Output: 5

    // Method 2: Using .at() (WITH bounds checking - throws exception if out of range)
    // This is safer - use this when you're not sure about index!
    cout << "arr2.at(2) = " << arr2.at(2) << endl; // Output: 3

    // Method 3: Using front() and back() - First and last element
    cout << "First element (front): " << arr2.front() << endl; // Output: 1
    cout << "Last element (back): " << arr2.back() << endl;    // Output: 5

    // Try uncommenting to see exception:
    // cout << arr2.at(10) << endl;  // throws std::out_of_range

    // ========================================================================
    // SIZE AND CAPACITY
    // ========================================================================

    cout << "\n--- SIZE AND CAPACITY ---" << endl;

    // .size() - Returns number of elements (constant time)
    cout << "Size of arr2: " << arr2.size() << endl; // Output: 5

    // .empty() - Returns true if array is empty
    cout << "Is arr2 empty: " << (arr2.empty() ? "Yes" : "No") << endl;
    cout << "Is arr1 empty: " << (arr1.empty() ? "Yes" : "No") << endl;

    // .max_size() - Returns maximum possible size (same as size for array)
    cout << "Max size: " << arr2.max_size() << endl; // Output: 5

    // ========================================================================
    // ITERATORS
    // ========================================================================

    cout << "\n--- ITERATORS ---" << endl;

    // begin() - Points to first element
    // end() - Points to one past last element

    // Method 1: Using iterators (like pointers)
    cout << "Using iterators: ";
    for (auto it = arr2.begin(); it != arr2.end(); it++)
    {
        cout << *it << " "; // Output: 1 2 3 4 5
    }
    cout << endl;

    // Method 2: Using reverse iterators (traverse backwards)
    cout << "Using reverse iterators: ";
    for (auto it = arr2.rbegin(); it != arr2.rend(); it++)
    {
        cout << *it << " "; // Output: 5 4 3 2 1
    }
    cout << endl;

    // Method 3: Range-based for loop (modern C++ style - recommended!)
    cout << "Using range-based for: ";
    for (int x : arr2)
    {
        cout << x << " ";
    }
    cout << endl;

    // ========================================================================
    // MODIFYING ELEMENTS
    // ========================================================================

    cout << "\n--- MODIFYING ELEMENTS ---" << endl;

    // .fill() - Fill entire array with a single value
    array<int, 5> arr5 = {1, 2, 3, 4, 5};
    arr5.fill(0); // Now all elements are 0
    cout << "After fill(0): ";
    for (int x : arr5)
        cout << x << " ";
    cout << endl;

    // .swap() - Swap contents of two arrays (they must have same size and type!)
    array<int, 5> arr6 = {10, 20, 30, 40, 50};
    array<int, 5> arr7 = {1, 2, 3, 4, 5};

    cout << "Before swap - arr6[0]: " << arr6[0] << ", arr7[0]: " << arr7[0] << endl;
    arr6.swap(arr7); // Now arr6 has {1,2,3,4,5} and arr7 has {10,20,30,40,50}
    cout << "After swap - arr6[0]: " << arr6[0] << ", arr7[0]: " << arr7[0] << endl;

    // ========================================================================
    // USING STL ALGORITHMS
    // ========================================================================

    cout << "\n--- USING STL ALGORITHMS ---" << endl;

    array<int, 5> arr8 = {5, 2, 8, 1, 9};

    // sort() - Sort the array
    sort(arr8.begin(), arr8.end());
    cout << "After sort: ";
    for (int x : arr8)
        cout << x << " ";
    cout << endl;

    // reverse() - Reverse the array
    reverse(arr8.begin(), arr8.end());
    cout << "After reverse: ";
    for (int x : arr8)
        cout << x << " ";
    cout << endl;

    // find() - Find element (returns iterator)
    auto it = find(arr8.begin(), arr8.end(), 5);
    if (it != arr8.end())
    {
        cout << "Found 5 at position: " << (it - arr8.begin()) << endl;
    }

    // min_element() and max_element()
    auto minIt = min_element(arr8.begin(), arr8.end());
    auto maxIt = max_element(arr8.begin(), arr8.end());
    cout << "Min: " << *minIt << ", Max: " << *maxIt << endl;

    // ========================================================================
    // DIFFERENCE FROM C-STYLE ARRAYS
    // ========================================================================

    cout << "\n--- ARRAY vs C-STYLE ARRAYS ---" << endl;

    // C-style array: int arr[5];
    // - No bounds checking
    // - Decays to pointer when passed to functions
    // - No member functions
    // - Cannot be returned from functions directly

    // std::array:
    // - Has bounds checking with .at()
    // - Doesn't decay to pointer (safe to pass)
    // - Has many useful member functions
    // - Can be returned from functions
    // - Can be used with STL algorithms

    // Example: safe comparison
    array<int, 3> a = {1, 2, 3};
    array<int, 3> b = {1, 2, 3};

    // Can compare entire arrays!
    if (a == b)
    {
        cout << "Arrays are equal!" << endl;
    }

    // ========================================================================
    // IMPORTANT NOTES
    // ========================================================================

    cout << "\n--- IMPORTANT NOTES ---" << endl;

    // 1. Size must be known at compile time - it's a template parameter!
    //    array<int, 5> - size is 5 (cannot be changed)

    // 2. Unlike vector, array cannot grow or shrink

    // 3. Stack-allocated (for small sizes) - very fast!

    // 4. Great for small fixed-size collections where you want:
    //    - Bounds checking safety
    //    - STL algorithm compatibility
    //    - Easy iteration

    // 5. For dynamic sizes, use std::vector instead

    cout << "\n==========================================" << endl;
    cout << "        ARRAY (STL) COMPLETED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}

/*
================================================================================
                         QUICK REFERENCE
================================================================================

Creating:
    array<int, 5> arr;              // Empty
    array<int, 5> arr = {1,2,3,4,5}; // Initialized
    array<int, 5> arr{};            // Zero-initialized

Accessing:
    arr[i]        // No bounds check
    arr.at(i)     // With bounds check
    arr.front()   // First element
    arr.back()    // Last element

Size:
    arr.size()    // Number of elements
    arr.empty()   // Is empty?

Iterators:
    arr.begin(), arr.end()
    arr.rbegin(), arr.rend()

Modifiers:
    arr.fill(x)   // Fill with x
    arr.swap(arr2)// Swap contents

Algorithms:
    Works with ALL STL algorithms!
    sort, reverse, find, min_element, max_element, etc.

================================================================================
*/