/*
================================================================================
                    SECTION 11: UNORDERED MAP
================================================================================

What is std::unordered_map?
- Hash table implementation of map
- Stores KEY-VALUE PAIRS (like map)
- Keys are UNIQUE but NOT sorted
- O(1) average time for insert, find, delete

Time Complexity (Average Case):
- Insert: O(1) average
- Find: O(1) average
- Delete: O(1) average
- Access by key: O(1) average

Time Complexity (Worst Case):
- All operations: O(n) when hash collisions occur

Space Complexity:
- O(n) for elements + O(buckets) for internal structure

Key Features:
- Hash table based - uses hash function for keys
- No sorting - keys are in arbitrary order
- O(1) average operations (O(n) worst case)
- Keys must be unique (no duplicates)

When to use:
- When you DON'T need sorted keys
- When you need FAST lookups (O(1) average)
- For large datasets where speed matters
- When you just need key-value pairs without order

Difference from map:
- map: O(log n) operations, SORTED keys
- unordered_map: O(1) average, NOT sorted keys

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "        UNORDERED MAP" << endl;
    cout << "==========================================" << endl;

    cout << "\n--- TIME & SPACE COMPLEXITY ---" << endl;
    cout << "Access (avg):     O(1)" << endl;
    cout << "Access (worst):   O(n)" << endl;
    cout << "Insert (avg):    O(1)" << endl;
    cout << "Insert (worst):  O(n)" << endl;
    cout << "Delete (avg):    O(1)" << endl;
    cout << "Delete (worst):  O(n)" << endl;
    cout << "Space:           O(n + buckets)" << endl;

    // ========================================================================
    // CREATING UNORDERED MAP
    // ========================================================================

    cout << "\n--- CREATING UNORDERED MAP ---" << endl;

    // Empty unordered map (key: string, value: int)
    unordered_map<string, int> um1;

    // With initializer list
    unordered_map<string, int> um2 = {
        {"apple", 5},
        {"banana", 3},
        {"cherry", 7}};

    // Keys are NOT sorted (random/undefined order)
    cout << "Elements (NOT sorted by key): ";
    for (auto &p : um2)
    {
        cout << p.first << ":" << p.second << " ";
    }
    cout << endl;

    // With custom hash and equality
    unordered_map<string, int, hash<string>, equal_to<string>> um3;

    // ========================================================================
    // INSERTING ELEMENTS
    // ========================================================================

    cout << "\n--- INSERTING ELEMENTS ---" << endl;

    unordered_map<string, int> um;

    // Method 1: insert() with pair or initializer_list
    um.insert({"apple", 5});
    um.insert({"banana", 3});
    um.insert({"cherry", 7});

    // Method 2: Using [] operator (creates key if not exists!)
    um["date"] = 4; // Creates new entry
    um["elderberry"] = 8;
    um["apple"] = 10; // Updates existing value (was 5, now 10)

    // Method 3: Using .at() (throws if key doesn't exist)
    try
    {
        int val = um.at("banana");
        cout << "banana = " << val << endl;
    }
    catch (const exception &e)
    {
        cout << "Key not found" << endl;
    }

    // Method 4: emplace() - construct in place (more efficient)
    um.emplace("fig", 6);

    // Method 5: insert with hint
    um.insert(um.begin(), {"grape", 9});

    cout << "All elements: ";
    for (auto &p : um)
    {
        cout << p.first << ":" << p.second << " ";
    }
    cout << endl;

    // ========================================================================
    // ACCESSING ELEMENTS
    // ========================================================================

    cout << "\n--- ACCESSING ELEMENTS ---" << endl;

    unordered_map<string, int> um2_copy = {{"one", 1}, {"two", 2}, {"three", 3}};

    // Method 1: Using [] (BE CAREFUL - creates key if not exists!)
    cout << "um2_copy[\"one\"] = " << um2_copy["one"] << endl; // 1
    // If key doesn't exist, it CREATES a new entry with value 0!

    // Method 2: Using .at() (throws exception if not found)
    try
    {
        cout << "um2_copy.at(\"two\") = " << um2_copy.at("two") << endl;
    }
    catch (...)
    {
        cout << "Key not found" << endl;
    }

    // Method 3: Using find() - returns iterator
    auto it = um2_copy.find("three");
    if (it != um2_copy.end())
    {
        cout << "Found: " << it->first << " = " << it->second << endl;
    }

    // Method 4: Using count() - check if key exists
    cout << "Count of 'one': " << um2_copy.count("one") << endl;
    cout << "Count of 'hundred': " << um2_copy.count("hundred") << endl;

    // Method 5: Using contains() - C++20
    // cout << "Contains 'one': " << um2_copy.contains("one") << endl;

    // ========================================================================
    // ITERATING
    // ========================================================================

    cout << "\n--- ITERATING ---" << endl;

    unordered_map<string, int> um4 = {
        {"apple", 5}, {"banana", 3}, {"cherry", 7}, {"date", 4}};

    // Range-based for (most common)
    cout << "Using range-based for: ";
    for (auto &p : um4)
    {
        cout << p.first << ":" << p.second << " ";
    }
    cout << endl;

    // Using iterators
    cout << "Using iterators: ";
    for (auto it = um4.begin(); it != um4.end(); it++)
    {
        cout << it->first << "=" << it->second << " ";
    }
    cout << endl;

    // ========================================================================
    // REMOVING ELEMENTS
    // ========================================================================

    cout << "\n--- REMOVING ELEMENTS ---" << endl;

    unordered_map<string, int> um5 = {
        {"apple", 5}, {"banana", 3}, {"cherry", 7}, {"date", 4}};

    // erase by key - O(1) average
    um5.erase("banana");
    cout << "After erase('banana'): ";
    for (auto &p : um5)
        cout << p.first << ":" << p.second << " ";
    cout << endl;

    // erase by iterator
    auto it2 = um5.find("cherry");
    if (it2 != um5.end())
    {
        um5.erase(it2);
    }
    cout << "After erase(iterator): ";
    for (auto &p : um5)
        cout << p.first << ":" << p.second << " ";
    cout << endl;

    // clear() - remove all
    um5.clear();

    // ========================================================================
    // SIZE OPERATIONS
    // ========================================================================

    cout << "\n--- SIZE OPERATIONS ---" << endl;

    unordered_map<string, int> um6 = {{"a", 1}, {"b", 2}, {"c", 3}};
    cout << "Size: " << um6.size() << endl;
    cout << "Empty: " << (um6.empty() ? "Yes" : "No") << endl;

    // Bucket operations
    cout << "Bucket count: " << um6.bucket_count() << endl;
    cout << "Load factor: " << um6.load_factor() << endl;

    // ========================================================================
    // HASH CONTROL
    // ========================================================================

    cout << "\n--- HASH CONTROL ---" << endl;

    unordered_map<int, int> um7;

    // reserve() - Pre-allocate buckets
    um7.reserve(100);
    cout << "After reserve(100) - bucket count: " << um7.bucket_count() << endl;

    // rehash() - Resize buckets
    um7.rehash(50);
    cout << "After rehash(50) - bucket count: " << um7.bucket_count() << endl;

    // ========================================================================
    // PRACTICAL EXAMPLES
    // ========================================================================

    cout << "\n--- PRACTICAL EXAMPLES ---" << endl;

    // Example 1: Word Frequency Counter
    vector<string> words = {"apple", "banana", "apple", "cherry", "banana", "apple"};
    unordered_map<string, int> freq;

    for (const string &word : words)
    {
        freq[word]++;
    }

    cout << "Word frequencies: ";
    for (auto &p : freq)
    {
        cout << p.first << ":" << p.second << " ";
    }
    cout << endl;

    // Example 2: Phonebook
    unordered_map<string, string> phonebook;
    phonebook["Alice"] = "123-456-7890";
    phonebook["Bob"] = "987-654-3210";
    phonebook["Charlie"] = "555-555-5555";

    string name = "Alice";
    if (phonebook.find(name) != phonebook.end())
    {
        cout << name << "'s number: " << phonebook[name] << endl;
    }

    // Example 3: Grouping by category
    unordered_map<string, vector<string>> groups;
    vector<pair<string, string>> items = {
        {"fruit", "apple"},
        {"fruit", "banana"},
        {"vegetable", "carrot"},
        {"fruit", "grape"},
        {"vegetable", "potato"}};

    for (auto &p : items)
    {
        groups[p.first].push_back(p.second);
    }

    cout << "Groups: " << endl;
    for (auto &p : groups)
    {
        cout << p.first << ": ";
        for (string &s : p.second)
            cout << s << " ";
        cout << endl;
    }

    // ========================================================================
    // IMPORTANT NOTES
    // ========================================================================

    cout << "\n--- IMPORTANT NOTES ---" << endl;

    // 1. Keys are NOT sorted:
    //    - Order is arbitrary/random
    //    - Use map if you need sorted keys

    // 2. [] vs .at():
    //    - [] creates key if not exists
    //    - .at() throws if not exists (safer)

    // 3. Performance:
    //    - Average case: O(1)
    //    - Worst case: O(n) (hash collisions)
    //    - Good hash function prevents worst case

    // 4. Unordered vs Map:
    //    - Use unordered_map when:
    //      * You don't need sorted keys
    //      * You have large datasets
    //      * You need fastest performance
    //    - Use map when:
    //      * You need sorted keys
    //      * You need ordered operations

    cout << "\n==========================================" << endl;
    cout << "        UNORDERED MAP COMPLETED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}

/*
================================================================================
                         QUICK REFERENCE
================================================================================

Creating:
    unordered_map<key_type, value_type> um;           // Empty
    unordered_map<string, int> um = {{"a", 1}, {"b", 2}}; // Initializer

Inserting:
    um.insert({"key", value});   // Insert pair (O(1) avg)
    um["key"] = value;           // Insert/update (O(1) avg) - CREATES if not exists!
    um.at("key") = value;        // Update only (O(1) avg) - THROWS if not exists
    um.emplace("key", value);    // Construct in place (O(1) avg)

Accessing:
    um["key"];          // Returns value (O(1) avg) - CREATES if not exists!
    um.at("key");       // Returns value (O(1) avg) - THROWS if not exists
    um.find("key");     // Returns iterator (O(1) avg)
    um.count("key");    // Returns 0 or 1 (O(1) avg)
    // um.contains("key"); // C++20

Removing:
    um.erase("key");      // Remove by key (O(1) avg)
    um.erase(it);        // Remove by iterator (O(1) avg)
    um.clear();          // Remove all

Size:
    um.size();        // Number of elements
    um.empty();       // Is empty?

Hash Control:
    um.bucket_count();    // Number of buckets
    um.load_factor();     // Load factor
    um.reserve(n);        // Reserve for n elements
    um.rehash(n);         // Resize to n buckets

Iterators:
    um.begin(), um.end()  // Unordered iteration

Time Complexity:
    Average:  O(1)
    Worst:    O(n) (hash collisions)

Space Complexity:
    O(n + buckets)

================================================================================
*/