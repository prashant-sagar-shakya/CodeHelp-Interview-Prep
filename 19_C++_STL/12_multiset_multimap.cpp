/*
================================================================================
            SECTION 12: MULTISET & MULTIMAP
================================================================================

================================================================================
                          MULTISET SECTION
================================================================================

What is std::multiset?
- Like set but ALLOWS DUPLICATES
- Elements are SORTED (ascending by default)
- All operations are O(log n)

Time Complexity:
- Insert: O(log n)
- Find: O(log n) - returns first occurrence
- Delete: O(log n)
- Count: O(log n) + O(count) to count all

Space Complexity:
- O(n) where n is total elements (including duplicates)

Key Features:
- Allows duplicate elements
- Elements always sorted
- Each element is unique in the multiset (but values can repeat)

When to use:
- When you need sorted elements with duplicates
- When you need to count occurrences
- When you need to keep multiple copies of same value

================================================================================
                          MULTIMAP SECTION
================================================================================

What is std::multimap?
- Like map but ALLOWS DUPLICATE KEYS
- Keys are SORTED (ascending by default)
- All operations are O(log n)

Time Complexity:
- Insert: O(log n)
- Find: O(log n) - returns first occurrence
- Delete: O(log n)
- Count: O(log n) + O(count)

Space Complexity:
- O(n) where n is total key-value pairs

Key Features:
- Allows duplicate keys
- Keys are always sorted
- Each key can map to multiple values

When to use:
- When you need multiple values for the same key
- When you need sorted keys with duplicates
- When you need to store multiple items per key

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "    MULTISET & MULTIMAP" << endl;
    cout << "==========================================" << endl;

    // ========================================================================
    // MULTISET
    // ========================================================================

    cout << "\n========== MULTISET ==========" << endl;

    cout << "\n--- TIME & SPACE COMPLEXITY ---" << endl;
    cout << "Insert:      O(log n)" << endl;
    cout << "Find:        O(log n)" << endl;
    cout << "Delete:      O(log n)" << endl;
    cout << "Count:       O(log n + count)" << endl;
    cout << "Space:       O(n)" << endl;

    cout << "\n--- CREATING MULTISET ---" << endl;

    // Empty multiset
    multiset<int> ms;

    // With initializer list (sorted)
    multiset<int> ms2 = {5, 2, 8, 1, 9, 2, 5, 3, 2};

    // Elements are sorted: {1, 2, 2, 2, 3, 5, 5, 8, 9}
    // Duplicates are allowed!
    cout << "Multiset elements (sorted with duplicates): ";
    for (int x : ms2)
        cout << x << " ";
    cout << endl;

    cout << "\n--- ADDING ELEMENTS ---" << endl;

    multiset<int> ms3;

    ms3.insert(10);
    ms3.insert(10);
    ms3.insert(20);
    ms3.insert(5);
    ms3.insert(20);

    // ms3 = {5, 10, 10, 20, 20} - sorted with duplicates
    cout << "After insert: ";
    for (int x : ms3)
        cout << x << " ";
    cout << endl;

    cout << "\n--- COUNTING ---" << endl;

    // count() - CAN be more than 1! (unlike set)
    cout << "Count of 10: " << ms3.count(10) << endl;   // 2
    cout << "Count of 20: " << ms3.count(20) << endl;   // 2
    cout << "Count of 100: " << ms3.count(100) << endl; // 0

    cout << "\n--- FINDING ---" << endl;

    // find() - Returns iterator to ONE occurrence
    auto it = ms3.find(10);
    if (it != ms3.end())
    {
        cout << "Found: " << *it << endl;
    }

    // NOTE: find() only returns ONE occurrence, not all!

    cout << "\n--- ERASING ---" << endl;

    multiset<int> ms4 = {10, 20, 30, 20, 40, 20};

    // erase by value - Removes ALL occurrences!
    ms4.erase(20); // Removes ALL 20s!
    // ms4 = {10, 30, 40}
    cout << "After erase(20): ";
    for (int x : ms4)
        cout << x << " ";
    cout << endl;

    // erase just one occurrence (using iterator)
    multiset<int> ms5 = {10, 20, 30, 20, 40, 20};
    it = ms5.find(20);
    if (it != ms5.end())
    {
        ms5.erase(it); // Removes only ONE 20
    }
    // ms5 = {10, 20, 30, 40, 20} - still has two 20s!
    cout << "After erase one 20: ";
    for (int x : ms5)
        cout << x << " ";
    cout << endl;

    cout << "\n--- BOUNDS ---" << endl;

    multiset<int> ms6 = {1, 3, 3, 3, 5, 7, 9};

    // lower_bound() - First >= value
    auto lb = ms6.lower_bound(3);
    // Points to first 3

    // upper_bound() - First > value
    auto ub = ms6.upper_bound(3);
    // Points to 5 (first element after all 3s)

    // equal_range() - Get all occurrences
    auto range = ms6.equal_range(3);
    cout << "All 3s: ";
    for (auto it2 = range.first; it2 != range.second; it2++)
    {
        cout << *it2 << " ";
    }
    cout << endl;

    cout << "\n--- PRACTICAL EXAMPLE ---" << endl;

    // Example: Get k smallest elements with duplicates allowed
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 5, 5};
    multiset<int> ms7(arr.begin(), arr.end());

    int k = 5;
    cout << k << " smallest elements: ";
    for (int i = 0; i < k && !ms7.empty(); i++)
    {
        cout << *ms7.begin() << " ";
        ms7.erase(ms7.begin());
    }
    cout << endl;

    // ========================================================================
    // MULTIMAP
    // ========================================================================

    cout << "\n========== MULTIMAP ==========" << endl;

    cout << "\n--- TIME & SPACE COMPLEXITY ---" << endl;
    cout << "Insert:      O(log n)" << endl;
    cout << "Find:        O(log n)" << endl;
    cout << "Delete:      O(log n)" << endl;
    cout << "Count:       O(log n + count)" << endl;
    cout << "Space:       O(n)" << endl;

    cout << "\n--- CREATING MULTIMAP ---" << endl;

    // Empty multimap
    multimap<string, int> mm;

    // With initializer list
    multimap<string, int> mm2 = {
        {"apple", 5},
        {"apple", 10},
        {"banana", 3},
        {"cherry", 7},
        {"apple", 15}};

    // Keys are sorted: {apple, apple, apple, banana, cherry}
    // Multiple values for "apple" allowed!
    cout << "Multimap elements (sorted keys, multiple values): ";
    for (auto &p : mm2)
    {
        cout << p.first << ":" << p.second << " ";
    }
    cout << endl;

    cout << "\n--- ADDING ELEMENTS ---" << endl;

    multimap<string, int> mm3;

    mm3.insert({"apple", 5});
    mm3.insert({"apple", 10}); // Another apple!
    mm3.insert({"banana", 3});
    mm3.insert({"apple", 15}); // Third apple!

    // mm3 = {apple:5, apple:10, apple:15, banana:3}
    cout << "After insert: ";
    for (auto &p : mm3)
        cout << p.first << ":" << p.second << " ";
    cout << endl;

    cout << "\n--- COUNTING ---" << endl;

    // count() - How many values for a key (CAN be > 1!)
    cout << "Count of 'apple': " << mm3.count("apple") << endl;   // 3
    cout << "Count of 'banana': " << mm3.count("banana") << endl; // 1

    cout << "\n--- FINDING ---" << endl;

    // find() - Returns iterator to ONE occurrence
    auto it2 = mm3.find("apple");
    if (it2 != mm3.end())
    {
        cout << "Found first apple: " << it2->second << endl;
    }

    // NOTE: find() only returns ONE occurrence, not all!

    cout << "\n--- GET ALL VALUES FOR KEY ---" << endl;

    // equal_range() - Get all values for a key
    auto range2 = mm3.equal_range("apple");
    cout << "All apple values: ";
    for (auto it3 = range2.first; it3 != range2.second; it3++)
    {
        cout << it3->second << " ";
    }
    cout << endl;

    cout << "\n--- ERASING ---" << endl;

    multimap<string, int> mm4 = {
        {"apple", 5},
        {"apple", 10},
        {"banana", 3}};

    // erase by key - Removes ALL entries with that key!
    mm4.erase("apple"); // Removes all apples!
    // mm4 = {banana:3}
    cout << "After erase('apple'): ";
    for (auto &p : mm4)
        cout << p.first << ":" << p.second << " ";
    cout << endl;

    // erase just one using iterator
    mm4.insert({"apple", 5});
    mm4.insert({"apple", 10});
    it2 = mm4.find("apple");
    if (it2 != mm4.end())
    {
        mm4.erase(it2); // Removes first apple only
    }
    cout << "After erase one apple: ";
    for (auto &p : mm4)
        cout << p.first << ":" << p.second << " ";
    cout << endl;

    cout << "\n--- BOUNDS ---" << endl;

    multimap<int, string> mm5 = {
        {1, "one"},
        {5, "five"},
        {10, "ten"},
        {10, "ten2"},
        {15, "fifteen"}};

    auto lb2 = mm5.lower_bound(10); // Points to first 10
    auto ub2 = mm5.upper_bound(10); // Points to 15
    cout << "Range of 10s: " << lb2->first << " to " << ub2->first << endl;

    cout << "\n--- PRACTICAL EXAMPLES ---" << endl;

    // Example 1: Multi-value dictionary
    multimap<string, string> dictionary;
    dictionary.insert({"word1", "meaning1"});
    dictionary.insert({"word1", "meaning2"});
    dictionary.insert({"word2", "meaning3"});

    cout << "Dictionary for word1: ";
    auto range3 = dictionary.equal_range("word1");
    for (auto it4 = range3.first; it4 != range3.second; it4++)
    {
        cout << it4->second << " ";
    }
    cout << endl;

    // Example 2: Grouping by category
    multimap<string, string> inventory;
    inventory.insert({"fruit", "apple"});
    inventory.insert({"fruit", "banana"});
    inventory.insert({"vegetable", "carrot"});
    inventory.insert({"fruit", "grape"});
    inventory.insert({"vegetable", "potato"});

    cout << "\nInventory by category:" << endl;
    // Need to traverse and group manually or use algorithm
    for (auto &p : inventory)
    {
        cout << p.first << ": " << p.second << endl;
    }

    // ========================================================================
    // IMPORTANT NOTES
    // ========================================================================

    cout << "\n========== IMPORTANT NOTES ==========" << endl;

    cout << "\n--- MULTISET ---" << endl;
    cout << "1. Allows duplicate elements" << endl;
    cout << "2. Elements are sorted" << endl;
    cout << "3. count() can return > 1" << endl;
    cout << "4. erase() by value removes ALL occurrences" << endl;
    cout << "5. Use when you need sorted duplicates" << endl;

    cout << "\n--- MULTIMAP ---" << endl;
    cout << "1. Allows duplicate keys" << endl;
    cout << "2. Keys are sorted" << endl;
    cout << "3. count() can return > 1" << endl;
    cout << "4. erase() by key removes ALL entries with that key" << endl;
    cout << "5. Use equal_range() to get all values for a key" << endl;
    cout << "6. Use when you need sorted keys with multiple values" << endl;

    cout << "\n--- MULTISET vs SET ---" << endl;
    cout << "set:   Unique, sorted" << endl;
    cout << "multiset: Allows duplicates, sorted" << endl;

    cout << "\n--- MULTIMAP vs MAP ---" << endl;
    cout << "map:    Unique keys, sorted" << endl;
    cout << "multimap: Allows duplicate keys, sorted" << endl;

    cout << "\n==========================================" << endl;
    cout << "    MULTISET & MULTIMAP COMPLETED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}

/*
================================================================================
                         QUICK REFERENCE - MULTISET
================================================================================

Creating:
    multiset<int> ms;               // Empty
    multiset<int> ms = {1,2,2,3};  // Initializer list

Adding:
    ms.insert(x);     // Insert (O(log n))

Counting:
    ms.count(x);      // Can be > 1! (O(log n + count))

Finding:
    ms.find(x);      // Returns iterator to ONE occurrence

Bounds:
    ms.lower_bound(x);  // First >= x
    ms.upper_bound(x); // First > x
    ms.equal_range(x); // Both bounds

Removing:
    ms.erase(x);      // Removes ALL x (O(log n + count))
    ms.erase(it);     // Removes one (O(log n))

================================================================================
                         QUICK REFERENCE - MULTIMAP
================================================================================

Creating:
    multimap<key, value> mm;               // Empty
    multimap<string, int> mm = {{"a", 1}, {"a", 2}}; // Initializer list

Adding:
    mm.insert({"key", value});   // Insert (O(log n))

Counting:
    mm.count(key);      // Can be > 1! (O(log n + count))

Finding:
    mm.find(key);       // Returns iterator to ONE occurrence

Getting all values:
    mm.equal_range(key); // Returns {lower, upper} for all values

Removing:
    mm.erase(key);      // Removes ALL entries with key (O(log n + count))
    mm.erase(it);      // Removes one (O(log n))

================================================================================
*/