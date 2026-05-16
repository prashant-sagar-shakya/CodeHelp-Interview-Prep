/*
================================================================================
                    SECTION 10: UNORDERED SET
================================================================================

What is std::unordered_set?
- Hash table implementation of set
- Stores UNIQUE elements (like set)
- But NOT sorted - elements are in random order
- O(1) average time for insert, find, delete

Time Complexity (Average Case):
- Insert: O(1) average
- Find: O(1) average
- Delete: O(1) average
- Iterator: O(n)

Time Complexity (Worst Case):
- All operations: O(n) when hash collisions occur

Space Complexity:
- O(n) for elements + O(buckets) for internal structure

Key Features:
- Hash table based - uses hash function to store elements
- No sorting - elements are in arbitrary order
- O(1) average operations (O(n) worst case)
- No duplicates allowed

When to use:
- When you DON'T need sorted order
- When you need FAST lookups (O(1) average)
- For large datasets where speed matters
- When you just need unique elements without order

Difference from set:
- set: O(log n) operations, SORTED order
- unordered_set: O(1) average, NOT sorted

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "        UNORDERED SET" << endl;
    cout << "==========================================" << endl;

    cout << "\n--- TIME & SPACE COMPLEXITY ---" << endl;
    cout << "Insert (avg):   O(1)" << endl;
    cout << "Insert (worst): O(n)" << endl;
    cout << "Find (avg):     O(1)" << endl;
    cout << "Find (worst):   O(n)" << endl;
    cout << "Delete (avg):   O(1)" << endl;
    cout << "Delete (worst): O(n)" << endl;
    cout << "Space:          O(n + buckets)" << endl;

    // ========================================================================
    // CREATING UNORDERED SET
    // ========================================================================

    cout << "\n--- CREATING UNORDERED SET ---" << endl;

    // Empty unordered set (default hash, std::equal_to)
    unordered_set<int> us1;

    // With initializer list
    unordered_set<int> us2 = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // Elements are NOT sorted (random/undefined order)
    cout << "Elements (NOT sorted): ";
    for (int x : us2)
        cout << x << " ";
    cout << endl;

    // With custom hash and equality
    unordered_set<string, hash<string>, equal_to<string>> us3;

    // ========================================================================
    // ADDING ELEMENTS
    // ========================================================================

    cout << "\n--- ADDING ELEMENTS ---" << endl;

    unordered_set<int> us;

    // insert() - O(1) average
    us.insert(50);
    us.insert(30);
    us.insert(80);
    us.insert(10);
    us.insert(20);
    us.insert(30); // Duplicate - will be IGNORED!

    cout << "Elements: ";
    for (int x : us)
        cout << x << " ";
    cout << endl;

    // emplace() - More efficient, constructs in place
    us.emplace(40);

    // insert with hint (tries to use position as hint)
    us.insert(us.begin(), 5);

    // ========================================================================
    // SEARCHING ELEMENTS
    // ========================================================================

    cout << "\n--- SEARCHING ELEMENTS ---" << endl;

    unordered_set<int> us2_copy = {10, 20, 30, 40, 50, 60, 70};

    // find() - O(1) average
    auto it = us2_copy.find(30);
    if (it != us2_copy.end())
    {
        cout << "Found: " << *it << endl;
    }

    // find non-existent
    it = us2_copy.find(35);
    if (it == us2_copy.end())
    {
        cout << "35 not found" << endl;
    }

    // count() - Returns 0 or 1
    cout << "Count of 30: " << us2_copy.count(30) << endl;
    cout << "Count of 100: " << us2_copy.count(100) << endl;

    // contains() - C++20 (check if key exists)
    // cout << "Contains 30: " << us2_copy.contains(30) << endl;

    // ========================================================================
    // REMOVING ELEMENTS
    // ========================================================================

    cout << "\n--- REMOVING ELEMENTS ---" << endl;

    unordered_set<int> us3_copy = {10, 20, 30, 40, 50};

    // erase by value - O(1) average
    us3_copy.erase(30);
    cout << "After erase(30): ";
    for (int x : us3_copy)
        cout << x << " ";
    cout << endl;

    // erase by iterator
    auto it2 = us3_copy.find(20);
    if (it2 != us3_copy.end())
    {
        us3_copy.erase(it2);
    }
    cout << "After erase(iterator): ";
    for (int x : us3_copy)
        cout << x << " ";
    cout << endl;

    // clear() - Remove all
    us3_copy.clear();

    // ========================================================================
    // SIZE OPERATIONS
    // ========================================================================

    cout << "\n--- SIZE OPERATIONS ---" << endl;

    unordered_set<int> us4 = {1, 2, 3, 4, 5};
    cout << "Size: " << us4.size() << endl;
    cout << "Empty: " << (us4.empty() ? "Yes" : "No") << endl;

    // max_size() - Very large number
    cout << "Max size: " << us4.max_size() << endl;

    // bucket_count() - Number of buckets
    cout << "Bucket count: " << us4.bucket_count() << endl;

    // load_factor() - How full the hash table is
    cout << "Load factor: " << us4.load_factor() << endl;

    // ========================================================================
    // REHASHING
    // ========================================================================

    cout << "\n--- REHASHING ---" << endl;

    unordered_set<int> us5;
    cout << "Initial bucket count: " << us5.bucket_count() << endl;

    // Insert elements
    for (int i = 0; i < 10; i++)
    {
        us5.insert(i * 10);
    }
    cout << "After inserting 10 elements - bucket count: " << us5.bucket_count() << endl;

    // reserve() - Pre-allocate buckets
    us5.reserve(100); // Reserve for at least 100 elements
    cout << "After reserve(100) - bucket count: " << us5.bucket_count() << endl;

    // rehash() - Resize to specific number of buckets
    us5.rehash(50);
    cout << "After rehash(50) - bucket count: " << us5.bucket_count() << endl;

    // ========================================================================
    // ITERATING
    // ========================================================================

    cout << "\n--- ITERATING ---" << endl;

    unordered_set<int> us6 = {5, 2, 8, 1, 9};

    // Note: Order is NOT guaranteed to be consistent
    cout << "Elements (order may vary): ";
    for (int x : us6)
    {
        cout << x << " ";
    }
    cout << endl;

    // Range-based for
    cout << "Using range-based for: ";
    for (auto it = us6.begin(); it != us6.end(); it++)
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
    unordered_set<int> uniqueSet(vec.begin(), vec.end());
    vector<int> uniqueVec(uniqueSet.begin(), uniqueSet.end());

    cout << "Unique from vector: ";
    for (int x : uniqueVec)
        cout << x << " ";
    cout << endl;

    // Example 2: Check if two arrays have common elements
    unordered_set<int> setA = {1, 2, 3, 4, 5};
    vector<int> vecB = {4, 5, 6, 7, 8};
    bool hasCommon = false;

    for (int x : vecB)
    {
        if (setA.find(x) != setA.end())
        {
            hasCommon = true;
            break;
        }
    }
    cout << "Has common elements: " << (hasCommon ? "Yes" : "No") << endl;

    // Example 3: Tracking visited items
    unordered_set<string> visited;
    vector<string> sequence = {"start", "a", "b", "a", "c", "start", "end"};

    for (const string &s : sequence)
    {
        if (visited.find(s) == visited.end())
        {
            visited.insert(s);
            cout << "First visit: " << s << endl;
        }
    }

    // ========================================================================
    // IMPORTANT NOTES
    // ========================================================================

    cout << "\n--- IMPORTANT NOTES ---" << endl;

    // 1. Order is NOT guaranteed:
    //    - Elements are in arbitrary order
    //    - Order can change after modifications
    //    - Don't rely on iteration order!

    // 2. Hash Collisions:
    //    - Average case: O(1)
    //    - Worst case: O(n) (when many collisions)
    //    - Good hash function prevents worst case

    // 3. Unordered vs Set:
    //    - Use unordered_set when:
    //      * You don't need sorted output
    //      * You have large datasets
    //      * You need fastest performance
    //    - Use set when:
    //      * You need sorted output
    //      * You need ordered operations like lower_bound

    // 4. Memory:
    //    - More memory than vector but less than map
    //    - Bucket count affects memory

    cout << "\n==========================================" << endl;
    cout << "        UNORDERED SET COMPLETED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}

/*
================================================================================
                         QUICK REFERENCE
================================================================================

Creating:
    unordered_set<int> us;              // Empty
    unordered_set<int> us = {1,2,3};    // Initializer list
    unordered_set<string> us;          // Strings

Adding:
    us.insert(x);     // Insert (O(1) avg)
    us.emplace(x);    // Construct in place (O(1) avg)

Searching:
    us.find(x);       // Returns iterator (O(1) avg)
    us.count(x);      // Returns 0 or 1 (O(1) avg)
    // us.contains(x); // C++20, returns bool

Removing:
    us.erase(x);      // Remove by value (O(1) avg)
    us.erase(it);     // Remove by iterator (O(1) avg)
    us.clear();       // Remove all

Size:
    us.size();        // Number of elements
    us.empty();       // Is empty?

Hash Control:
    us.bucket_count();    // Number of buckets
    us.load_factor();     // Load factor
    us.reserve(n);        // Reserve buckets for n elements
    us.rehash(n);         // Resize to n buckets

Iterators:
    us.begin(), us.end()  // Unordered iteration

Time Complexity:
    Average:  O(1)
    Worst:    O(n) (hash collisions)

Space Complexity:
    O(n + buckets)

================================================================================
*/