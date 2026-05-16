/*
================================================================================
                    SECTION 7: SET
================================================================================

What is std::set?
- Stores UNIQUE elements in SORTED order
- Implemented as Red-Black tree (balanced BST)
- All operations are O(log n)

Key Features:
- No duplicates allowed
- Elements always sorted (ascending by default)
- Cannot modify elements directly
- No random access (no [] operator)

When to use:
- When you need unique elements
- When you need elements in sorted order
- For set operations (union, intersection)
- For removing duplicates from sorted data
- For implementing dictionaries with unique keys

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "        SET" << endl;
    cout << "==========================================" << endl;

    // ========================================================================
    // CREATING SET
    // ========================================================================

    cout << "\n--- CREATING SET ---" << endl;

    // Empty set
    set<int> s1;

    // With initializer list (sorted automatically)
    set<int> s2 = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // Default ascending order
    cout << "Set elements (ascending): ";
    for (int x : s2)
        cout << x << " ";
    cout << endl;

    // Descending order
    set<int, greater<int>> s3 = {5, 2, 8, 1, 9, 3};
    cout << "Set elements (descending): ";
    for (int x : s3)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // ADDING ELEMENTS
    // ========================================================================

    cout << "\n--- ADDING ELEMENTS ---" << endl;

    set<int> s;

    // insert() - Add elements
    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(10);
    s.insert(20);
    s.insert(30); // Duplicate - will be IGNORED!

    // Set is automatically sorted: {10, 20, 30, 50, 80}
    cout << "Set elements: ";
    for (int x : s)
        cout << x << " ";
    cout << endl;

    // emplace() - Construct in place (more efficient)
    s.emplace(40);

    // insert with hint (may be faster for bulk inserts)
    s.insert(s.begin(), 5); // Hint for where to insert

    // ========================================================================
    // SEARCHING ELEMENTS
    // ========================================================================

    cout << "\n--- SEARCHING ELEMENTS ---" << endl;

    set<int> s2_copy = {10, 20, 30, 40, 50};

    // find() - Returns iterator to element (O(log n))
    auto it = s2_copy.find(30);
    if (it != s2_copy.end())
    {
        cout << "Found: " << *it << endl;
    }

    // find non-existent element
    it = s2_copy.find(35);
    if (it == s2_copy.end())
    {
        cout << "35 not found (returned end)" << endl;
    }

    // count() - Returns 0 or 1 (since no duplicates)
    cout << "Count of 30: " << s2_copy.count(30) << endl;   // 1
    cout << "Count of 100: " << s2_copy.count(100) << endl; // 0

    // ========================================================================
    // BOUND OPERATIONS
    // ========================================================================

    cout << "\n--- BOUND OPERATIONS ---" << endl;

    set<int> s3Bound = {10, 20, 30, 40, 50};

    // lower_bound() - First element >= value
    auto lb = s3Bound.lower_bound(25);
    if (lb != s3Bound.end())
    {
        cout << "Lower bound of 25: " << *lb << endl; // 30
    }

    // upper_bound() - First element > value
    auto ub = s3Bound.upper_bound(25);
    if (ub != s3Bound.end())
    {
        cout << "Upper bound of 25: " << *ub << endl; // 30
    }

    // equal_range() - Returns pair of (lower_bound, upper_bound)
    auto range = s3Bound.equal_range(30);
    cout << "Equal range of 30: first = " << *range.first
         << ", second = " << *range.second << endl;

    // Examples:
    lb = s3Bound.lower_bound(10); // Points to 10
    ub = s3Bound.upper_bound(50); // Points to end
    cout << "All elements >= 10 and <= 50: ";
    for (auto it = lb; it != ub; it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // ========================================================================
    // REMOVING ELEMENTS
    // ========================================================================

    cout << "\n--- REMOVING ELEMENTS ---" << endl;

    set<int> s4 = {10, 20, 30, 40, 50};

    // erase by value
    s4.erase(30); // Removes 30
    // s4 = {10, 20, 40, 50}

    cout << "After erase(30): ";
    for (int x : s4)
        cout << x << " ";
    cout << endl;

    // erase by iterator
    auto it2 = s4.find(20);
    if (it2 != s4.end())
    {
        s4.erase(it2); // Removes 20
    }
    // s4 = {10, 40, 50}

    cout << "After erase(20): ";
    for (int x : s4)
        cout << x << " ";
    cout << endl;

    // erase by range
    it2 = s4.begin();
    it2++;                   // Point to 40
    s4.erase(it2, s4.end()); // Remove from 40 to end

    cout << "After range erase: ";
    for (int x : s4)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // SIZE OPERATIONS
    // ========================================================================

    cout << "\n--- SIZE OPERATIONS ---" << endl;

    set<int> s5 = {1, 2, 3, 4, 5};
    cout << "Size: " << s5.size() << endl;
    cout << "Empty: " << (s5.empty() ? "Yes" : "No") << endl;
    cout << "Max size: " << s5.max_size() << endl;

    s5.clear();
    cout << "After clear - Size: " << s5.size() << endl;

    // ========================================================================
    // ITERATORS
    // ========================================================================

    cout << "\n--- ITERATORS ---" << endl;

    set<int> s6 = {5, 2, 8, 1, 9};

    // begin() - First element (smallest)
    // end() - Past last element

    cout << "Forward: ";
    for (auto it = s6.begin(); it != s6.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iterators
    cout << "Backward: ";
    for (auto it = s6.rbegin(); it != s6.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // ========================================================================
    // PRACTICAL EXAMPLES
    // ========================================================================

    cout << "\n--- PRACTICAL EXAMPLES ---" << endl;

    // Example 1: Remove duplicates from vector
    vector<int> vec = {5, 2, 8, 1, 9, 2, 5, 1, 8, 3};
    set<int> uniqueSet(vec.begin(), vec.end());
    cout << "Unique elements from vector: ";
    for (int x : uniqueSet)
        cout << x << " ";
    cout << endl;

    // Example 2: Check if two sets have common elements
    set<int> setA = {1, 2, 3, 4, 5};
    set<int> setB = {4, 5, 6, 7, 8};

    // Intersection - using set_intersection algorithm
    vector<int> intersection;
    set_intersection(setA.begin(), setA.end(),
                     setB.begin(), setB.end(),
                     back_inserter(intersection));
    cout << "Intersection: ";
    for (int x : intersection)
        cout << x << " ";
    cout << endl;

    // Union
    vector<int> unionSet;
    set_union(setA.begin(), setA.end(),
              setB.begin(), setB.end(),
              back_inserter(unionSet));
    cout << "Union: ";
    for (int x : unionSet)
        cout << x << " ";
    cout << endl;

    // Difference
    vector<int> difference;
    set_difference(setA.begin(), setA.end(),
                   setB.begin(), setB.end(),
                   back_inserter(difference));
    cout << "A - B: ";
    for (int x : difference)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // IMPORTANT NOTES
    // ========================================================================

    cout << "\n--- IMPORTANT NOTES ---" << endl;

    // 1. Always sorted (ascending by default)
    //    - Use std::greater for descending

    // 2. No duplicates - duplicate insert is ignored

    // 3. Cannot modify elements directly!
    //    - Must erase and re-insert

    // 4. No random access - can't use []

    // 5. Time Complexity:
    //    - All operations: O(log n)

    // 6. Use when:
    //    - Need sorted output
    //    - Need unique elements
    //    - Need set operations

    // 7. For faster O(1) lookups, use unordered_set

    cout << "\n==========================================" << endl;
    cout << "        SET COMPLETED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}

/*
================================================================================
                         QUICK REFERENCE
================================================================================

Creating:
    set<int> s;                       // Empty, ascending
    set<int, greater<int>> s;        // Descending order
    set<int> s = {3, 1, 4, 1, 5};    // Initializer list

Adding:
    s.insert(x);     // Insert (O(log n))
    s.emplace(x);    // Construct in place

Searching:
    s.find(x);       // Returns iterator (O(log n))
    s.count(x);      // Returns 0 or 1 (O(log n))

Bounds:
    s.lower_bound(x);  // First element >= x
    s.upper_bound(x);  // First element > x
    s.equal_range(x);  // Returns {lower, upper}

Removing:
    s.erase(x);      // Remove by value (O(log n))
    s.erase(it);     // Remove at iterator (O(log n))
    s.clear();       // Remove all

Size:
    s.size();        // Number of elements
    s.empty();       // Is empty?

Iterators:
    s.begin(), s.end()
    s.rbegin(), s.rend()

Algorithms:
    Works with STL algorithms
    set_union, set_intersection, set_difference

Time Complexity:
    All operations: O(log n)

================================================================================
*/