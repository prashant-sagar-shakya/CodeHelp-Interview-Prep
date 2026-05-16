/*
================================================================================
                    SECTION 2: VECTOR
================================================================================

What is std::vector?
- It's a DYNAMIC array that can grow and shrink automatically
- Elements are stored in CONTIGUOUS memory (like regular arrays)
- Most commonly used STL container!

Key Features:
- Dynamic size: Can change during runtime
- Automatic memory management
- Random access in O(1) time
- Adding at end is O(1) amortized (doubles capacity when full)

Important Concepts:
- SIZE: Number of actual elements stored
- CAPACITY: Total memory allocated
- When size == capacity and we add more, it doubles capacity

When to use:
- Default choice for sequence containers
- When you don't know the size beforehand
- When you need random access
- When you frequently add elements at the end

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "        VECTOR" << endl;
    cout << "==========================================" << endl;

    // ========================================================================
    // CREATING VECTORS
    // ========================================================================

    cout << "\n--- CREATING VECTORS ---" << endl;

    // Method 1: Empty vector (size = 0, capacity = 0)
    vector<int> v1;

    // Method 2: Vector with n elements (initialized to 0)
    vector<int> v2(5); // v2 = {0, 0, 0, 0, 0}

    // Method 3: Vector with n elements, all initialized to a value
    vector<int> v3(5, 100); // v3 = {100, 100, 100, 100, 100}

    // Method 4: Initialize with values using initializer list
    vector<int> v4 = {1, 2, 3, 4, 5};

    // Method 5: Copy from another vector
    vector<int> v5 = v4;

    // Method 6: Create from array
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> v6(arr, arr + 5); // Uses pointers/iterators

    cout << "v4 = ";
    for (int x : v4)
        cout << x << " ";
    cout << endl;

    cout << "v3 (initialized to 100) = ";
    for (int x : v3)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // ADDING ELEMENTS
    // ========================================================================

    cout << "\n--- ADDING ELEMENTS ---" << endl;

    vector<int> v;

    // push_back() - Add element at the END (O(1) amortized)
    // Amortized means: most times it's O(1), but occasionally it takes longer
    // When capacity is full, it doubles the capacity
    v.push_back(10); // v = {10}
    v.push_back(20); // v = {10, 20}
    v.push_back(30); // v = {10, 20, 30}
    v.push_back(40); // v = {10, 20, 30, 40}
    v.push_back(50); // v = {10, 20, 30, 40, 50}

    cout << "After push_backs: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // emplace_back() - More efficient than push_back (constructs in place)
    v.emplace_back(60); // Slightly faster for complex objects

    // insert() - Insert element at specific position (O(n))
    // Insert single element
    v.insert(v.begin() + 2, 25); // Insert 25 at index 2
    // v = {10, 20, 25, 30, 40, 50, 60}

    // Insert multiple copies of same element
    v.insert(v.begin() + 1, 3, 15); // Insert three 15s at index 1
    // v = {10, 15, 15, 15, 20, 25, 30, 40, 50, 60}

    // Insert range from another vector
    vector<int> toInsert = {100, 200};
    v.insert(v.end(), toInsert.begin(), toInsert.end());

    cout << "After insert: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // ACCESSING ELEMENTS
    // ========================================================================

    cout << "\n--- ACCESSING ELEMENTS ---" << endl;

    vector<int> vec2 = {10, 20, 30, 40, 50};

    // Method 1: Using [] operator (NO bounds checking - like arrays)
    cout << "vec2[0] = " << vec2[0] << endl; // 10
    cout << "vec2[4] = " << vec2[4] << endl; // 50

    // Method 2: Using .at() (WITH bounds checking - throws exception)
    cout << "vec2.at(2) = " << vec2.at(2) << endl; // 30

    // Uncomment to see exception:
    // cout << vec2.at(10) << endl;  // throws std::out_of_range

    // Method 3: Using front() and back()
    cout << "Front: " << vec2.front() << endl; // 10
    cout << "Back: " << vec2.back() << endl;   // 50

    // Method 4: Using data() - Get pointer to underlying array (like C array)
    int *ptr = vec2.data();
    cout << "First element via data(): " << *ptr << endl;

    // ========================================================================
    // SIZE AND CAPACITY
    // ========================================================================

    cout << "\n--- SIZE AND CAPACITY ---" << endl;

    vector<int> vec3 = {1, 2, 3};
    cout << "Initial - Size: " << vec3.size() << ", Capacity: " << vec3.capacity() << endl;

    vec3.push_back(4);
    cout << "After 1 push - Size: " << vec3.size() << ", Capacity: " << vec3.capacity() << endl;

    vec3.push_back(5);
    vec3.push_back(6);
    vec3.push_back(7);
    vec3.push_back(8);
    cout << "After more pushes - Size: " << vec3.size() << ", Capacity: " << vec3.capacity() << endl;

    // resize() - Change the size
    vector<int> vec4 = {1, 2, 3};
    vec4.resize(5);      // Now vec4 = {1, 2, 3, 0, 0}
    vec4.resize(7, 100); // Now vec4 = {1, 2, 3, 0, 0, 100, 100}
    vec4.resize(2);      // Now vec4 = {1, 2} (truncates!)

    cout << "After resize to 2: ";
    for (int x : v4)
        cout << x << " ";
    cout << endl;

    // reserve() - Pre-allocate memory (avoid reallocations)
    vector<int> vec5;
    vec5.reserve(100); // Allocates space for 100 elements
    // Size is still 0, but capacity is 100!
    cout << "After reserve(100) - Size: " << vec5.size() << ", Capacity: " << vec5.capacity() << endl;

    // shrink_to_fit() - Reduce capacity to match size
    vec5.shrink_to_fit(); // Capacity becomes equal to size

    // ========================================================================
    // REMOVING ELEMENTS
    // ========================================================================

    cout << "\n--- REMOVING ELEMENTS ---" << endl;

    vector<int> vec6 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // pop_back() - Remove last element (O(1))
    vec6.pop_back(); // vec6 = {1, 2, 3, 4, 5, 6, 7, 8}
    vec6.pop_back();

    // erase() - Remove element(s) at specific position (O(n))
    vec6.erase(vec6.begin() + 2); // Remove element at index 2 (value 3)
    // vec6 = {1, 2, 4, 5, 6, 7, 8}

    // erase a range
    vec6.erase(vec6.begin() + 1, vec6.begin() + 4); // Remove elements from index 1 to 3
    // v6 = {1, 5, 6, 7, 8}

    // clear() - Remove all elements (size becomes 0, capacity unchanged!)
    vector<int> v7 = {1, 2, 3, 4, 5};
    cout << "Before clear - Size: " << v7.size() << ", Capacity: " << v7.capacity() << endl;
    v7.clear();
    cout << "After clear - Size: " << v7.size() << ", Capacity: " << v7.capacity() << endl;

    // empty() - Check if vector is empty
    cout << "Is v7 empty: " << (v7.empty() ? "Yes" : "No") << endl;

    // ========================================================================
    // ITERATORS
    // ========================================================================

    cout << "\n--- ITERATORS ---" << endl;

    vector<int> v8 = {10, 20, 30, 40, 50};

    // Using iterators
    cout << "Using iterators: ";
    for (auto it = v8.begin(); it != v8.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Using reverse iterators
    cout << "Reverse: ";
    for (auto it = v8.rbegin(); it != v8.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Range-based for
    cout << "Range-based: ";
    for (int x : v8)
    {
        cout << x << " ";
    }
    cout << endl;

    // ========================================================================
    // COMMON ALGORITHMS WITH VECTORS
    // ========================================================================

    cout << "\n--- COMMON ALGORITHMS ---" << endl;

    vector<int> v9 = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // sort() - Sort ascending
    sort(v9.begin(), v9.end());
    cout << "Sorted: ";
    for (int x : v9)
        cout << x << " ";
    cout << endl;

    // sort descending
    sort(v9.begin(), v9.end(), greater<int>());
    cout << "Sorted desc: ";
    for (int x : v9)
        cout << x << " ";
    cout << endl;

    // reverse()
    reverse(v9.begin(), v9.end());

    // find() - Find element
    auto it = find(v9.begin(), v9.end(), 5);
    if (it != v9.end())
    {
        cout << "Found 5 at index: " << (it - v9.begin()) << endl;
    }

    // binary_search() - Search in sorted vector (O(log n))
    sort(v9.begin(), v9.end()); // Must be sorted first!
    bool found = binary_search(v9.begin(), v9.end(), 5);
    cout << "Binary search for 5: " << (found ? "Found" : "Not found") << endl;

    // ========================================================================
    // IMPORTANT NOTES
    // ========================================================================

    cout << "\n--- IMPORTANT NOTES ---" << endl;

    // 1. Size vs Capacity:
    //    - Size = number of elements actually stored
    //    - Capacity = total memory allocated
    //    - Capacity >= Size always
    //    - When size reaches capacity, vector doubles (amortized O(1))

    // 2. When to use vector:
    //    - Default choice for almost all use cases
    //    - When you need random access (O(1))
    //    - When you mostly add/remove at the end
    //    - For small to medium sized data

    // 3. When NOT to use vector:
    //    - When you frequently insert in the middle (use list)
    //    - When you frequently insert at front (use deque)

    // 4. Memory:
    //    - Contiguous memory (cache-friendly!)
    //    - Elements are stored one after another

    cout << "\n==========================================" << endl;
    cout << "        VECTOR COMPLETED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}

/*
================================================================================
                         QUICK REFERENCE
================================================================================

Creating:
    vector<int> v;           // Empty
    vector<int> v(5);        // 5 elements, value = 0
    vector<int> v(5, 100);   // 5 elements, value = 100
    vector<int> v = {1,2,3}; // Initializer list

Adding:
    v.push_back(x);   // Add at end (O(1) amortized)
    v.emplace_back(x);// Construct in place (faster)
    v.insert(pos, x); // Insert at position (O(n))

Accessing:
    v[i];         // No bounds check
    v.at(i);      // With bounds check
    v.front();    // First element
    v.back();     // Last element

Size/Capacity:
    v.size();           // Number of elements
    v.capacity();       // Memory allocated
    v.resize(n);        // Change size
    v.reserve(n);       // Pre-allocate
    v.empty();          // Is empty?

Removing:
    v.pop_back();      // Remove last (O(1))
    v.erase(pos);      // Remove at position (O(n))
    v.clear();         // Remove all

Algorithms:
    Works with ALL STL algorithms!
    sort, reverse, find, binary_search, etc.

Time Complexity:
    Random access:      O(1)
    push_back:          O(1) amortized
    insert at end:      O(1) amortized
    insert at middle:   O(n)
    search:             O(n) (O(log n) if sorted with binary_search)

================================================================================
*/