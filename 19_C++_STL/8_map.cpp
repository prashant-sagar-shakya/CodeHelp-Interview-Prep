/*
================================================================================
                    SECTION 8: MAP
================================================================================

What is std::map?
- Stores KEY-VALUE PAIRS
- Keys are UNIQUE and SORTED
- Implemented as Red-Black tree (balanced BST)
- All operations are O(log n)

Key Features:
- Each key maps to exactly one value
- Keys are unique (no duplicates)
- Keys are always sorted
- O(log n) for insert, delete, search

Time Complexity:
- Access (by key): O(log n)
- Insert: O(log n)
- Delete: O(log n)
- Search: O(log n)

Space Complexity:
- O(n) where n is number of key-value pairs

When to use:
- When you need to associate values with keys
- For dictionary-like data structures
- For counting frequencies
- When you need sorted keys (use unordered_map if not needed)

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "        MAP" << endl;
    cout << "==========================================" << endl;

    cout << "\n--- TIME & SPACE COMPLEXITY ---" << endl;
    cout << "Access by key:     O(log n)" << endl;
    cout << "Insert key-value:  O(log n)" << endl;
    cout << "Delete by key:     O(log n)" << endl;
    cout << "Search:            O(log n)" << endl;
    cout << "Space Complexity:  O(n)" << endl;

    // ========================================================================
    // CREATING MAP
    // ========================================================================

    cout << "\n--- CREATING MAP ---" << endl;

    // Empty map (key: string, value: int)
    map<string, int> m1;

    // With initializer list
    map<string, int> m2 = {
        {"apple", 5},
        {"banana", 3},
        {"cherry", 7}};

    // Default ascending order by key
    cout << "Map elements (sorted by key): ";
    for (auto &p : m2)
    {
        cout << p.first << ":" << p.second << " ";
    }
    cout << endl;

    // Descending order
    map<string, int, greater<string>> m3;
    m3["zebra"] = 1;
    m3["apple"] = 2;
    m3["monkey"] = 3;

    cout << "Map (descending): ";
    for (auto &p : m3)
    {
        cout << p.first << ":" << p.second << " ";
    }
    cout << endl;

    // ========================================================================
    // INSERTING ELEMENTS
    // ========================================================================

    cout << "\n--- INSERTING ELEMENTS ---" << endl;

    map<string, int> m;

    // Method 1: insert() with pair or initializer_list
    m.insert({"apple", 5});
    m.insert({"banana", 3});
    m.insert({"cherry", 7});

    // Method 2: Using [] operator (creates key if not exists!)
    m["date"] = 4; // Creates new entry
    m["elderberry"] = 8;
    m["apple"] = 10; // Updates existing value (was 5, now 10)

    // Method 3: Using .at() (throws if key doesn't exist)
    try
    {
        int val = m.at("banana");
        cout << "banana = " << val << endl;
    }
    catch (const exception &e)
    {
        cout << "Key not found" << endl;
    }

    // Method 4: emplace() - construct in place (more efficient)
    m.emplace("fig", 6);

    // Method 5: insert with hint
    m.insert(m.begin(), {"grape", 9});

    cout << "All elements: ";
    for (auto &p : m)
    {
        cout << p.first << ":" << p.second << " ";
    }
    cout << endl;

    // ========================================================================
    // ACCESSING ELEMENTS
    // ========================================================================

    cout << "\n--- ACCESSING ELEMENTS ---" << endl;

    map<string, int> m2_copy = {{"one", 1}, {"two", 2}, {"three", 3}};

    // Method 1: Using [] (BE CAREFUL - creates key if not exists!)
    cout << "m2_copy[\"one\"] = " << m2_copy["one"] << endl; // 1

    // If key doesn't exist, it CREATES a new entry with value 0!
    // Uncomment to see: cout << m2_copy["unknown"] << endl; // Creates entry!

    // Method 2: Using .at() (throws exception if not found)
    try
    {
        cout << "m2_copy.at(\"two\") = " << m2_copy.at("two") << endl;
        // m2_copy.at("unknown"); // Throws exception!
    }
    catch (...)
    {
        cout << "Key not found with .at()" << endl;
    }

    // Method 3: Using find() - returns iterator
    auto it = m2_copy.find("three");
    if (it != m2_copy.end())
    {
        cout << "Found: " << it->first << " = " << it->second << endl;
    }

    // Method 4: Using count() - check if key exists
    cout << "Count of 'one': " << m2_copy.count("one") << endl;
    cout << "Count of 'hundred': " << m2_copy.count("hundred") << endl;

    // ========================================================================
    // BOUND OPERATIONS
    // ========================================================================

    cout << "\n--- BOUND OPERATIONS ---" << endl;

    map<int, string> numMap = {{1, "one"}, {5, "five"}, {10, "ten"}, {15, "fifteen"}};

    // lower_bound() - First element >= key
    auto lb = numMap.lower_bound(5);
    if (lb != numMap.end())
    {
        cout << "Lower bound of 5: " << lb->first << " -> " << lb->second << endl;
    }

    // upper_bound() - First element > key
    auto ub = numMap.upper_bound(5);
    if (ub != numMap.end())
    {
        cout << "Upper bound of 5: " << ub->first << " -> " << ub->second << endl;
    }

    // equal_range() - Returns pair of bounds
    auto range = numMap.equal_range(5);
    cout << "Equal range of 5: " << range.first->first << " to " << range.second->first << endl;

    // ========================================================================
    // ITERATING
    // ========================================================================

    cout << "\n--- ITERATING ---" << endl;

    map<string, int> strMap = {{"apple", 5}, {"banana", 3}, {"cherry", 7}, {"date", 4}};

    // Range-based for (most common)
    cout << "Using range-based for: ";
    for (auto &p : strMap)
    {
        cout << p.first << ":" << p.second << " ";
    }
    cout << endl;

    // Using iterators
    cout << "Using iterators: ";
    for (auto it = strMap.begin(); it != strMap.end(); it++)
    {
        cout << it->first << "=" << it->second << " ";
    }
    cout << endl;

    // Reverse iteration
    cout << "Reverse: ";
    for (auto it = strMap.rbegin(); it != strMap.rend(); it++)
    {
        cout << it->first << ":" << it->second << " ";
    }
    cout << endl;

    // ========================================================================
    // REMOVING ELEMENTS
    // ========================================================================

    cout << "\n--- REMOVING ELEMENTS ---" << endl;

    map<string, int> m5 = {{"apple", 5}, {"banana", 3}, {"cherry", 7}, {"date", 4}};

    // erase by key
    m5.erase("banana"); // Removes entry with key "banana"
    cout << "After erase('banana'): ";
    for (auto &p : m5)
        cout << p.first << ":" << p.second << " ";
    cout << endl;

    // erase by iterator
    auto it2 = m5.find("cherry");
    if (it2 != m5.end())
    {
        m5.erase(it2);
    }
    cout << "After erase(iterator): ";
    for (auto &p : m5)
        cout << p.first << ":" << p.second << " ";
    cout << endl;

    // erase by range
    it2 = m5.begin();
    it2++;                   // Point to second element
    m5.erase(it2, m5.end()); // Remove from second to end
    cout << "After range erase: ";
    for (auto &p : m5)
        cout << p.first << ":" << p.second << " ";
    cout << endl;

    // clear() - remove all
    m5.clear();

    // ========================================================================
    // SIZE OPERATIONS
    // ========================================================================

    cout << "\n--- SIZE OPERATIONS ---" << endl;

    map<string, int> m6 = {{"a", 1}, {"b", 2}, {"c", 3}};
    cout << "Size: " << m6.size() << endl;
    cout << "Empty: " << (m6.empty() ? "Yes" : "No") << endl;
    cout << "Max size: " << m6.max_size() << endl;

    // ========================================================================
    // PRACTICAL EXAMPLES
    // ========================================================================

    cout << "\n--- PRACTICAL EXAMPLES ---" << endl;

    // Example 1: Frequency Counter
    vector<string> words = {"apple", "banana", "apple", "cherry", "banana", "apple"};
    map<string, int> freq;

    for (const string &word : words)
    {
        freq[word]++; // Increment frequency
    }

    cout << "Word frequencies: ";
    for (auto &p : freq)
    {
        cout << p.first << ":" << p.second << " ";
    }
    cout << endl;

    // Example 2: Phonebook
    map<string, string> phonebook;
    phonebook["Alice"] = "123-456-7890";
    phonebook["Bob"] = "987-654-3210";
    phonebook["Charlie"] = "555-555-5555";

    string name = "Alice";
    if (phonebook.find(name) != phonebook.end())
    {
        cout << name << "'s number: " << phonebook[name] << endl;
    }

    // Example 3: Dictionary
    map<string, string> dictionary;
    dictionary["programming"] = "The act of writing computer code";
    dictionary["algorithm"] = "A step-by-step procedure for calculations";
    dictionary["database"] = "An organized collection of data";

    cout << "Dictionary lookup - algorithm: " << dictionary["algorithm"] << endl;

    // ========================================================================
    // IMPORTANT NOTES
    // ========================================================================

    cout << "\n--- IMPORTANT NOTES ---" << endl;

    // 1. [] operator vs .at():
    //    - [] creates key if not exists (can accidentally create)
    //    - .at() throws exception if not found (safer)

    // 2. Keys are always sorted!
    //    - Use unordered_map if you don't need sorted keys

    // 3. Each key maps to ONE value
    //    - Use multimap for multiple values per key

    // 4. Map is sorted by KEY, not by VALUE
    //    - Value doesn't affect ordering

    // 5. For O(1) operations, use unordered_map
    //    - But you'll lose sorted order

    cout << "\n==========================================" << endl;
    cout << "        MAP COMPLETED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}

/*
================================================================================
                         QUICK REFERENCE
================================================================================

Creating:
    map<key_type, value_type> m;                    // Empty
    map<string, int> m = {{"a", 1}, {"b", 2}};     // Initializer list
    map<string, int, greater<string>> m;            // Descending by key

Inserting:
    m.insert({"key", value});   // Insert pair (O(log n))
    m["key"] = value;           // Insert/update (O(log n)) - creates if not exists!
    m.at("key") = value;        // Update only (O(log n)) - throws if not exists
    m.emplace("key", value);    // Construct in place (O(log n))

Accessing:
    m["key"];          // Returns value (O(log n)) - CREATES if not exists!
    m.at("key");       // Returns value (O(log n)) - THROWS if not exists
    m.find("key");     // Returns iterator (O(log n))
    m.count("key");    // Returns 0 or 1 (O(log n))

Bounds:
    m.lower_bound(key);   // First >= key
    m.upper_bound(key);  // First > key
    m.equal_range(key);  // Both bounds

Removing:
    m.erase("key");      // Remove by key (O(log n))
    m.erase(it);        // Remove by iterator (O(log n))
    m.clear();          // Remove all

Size:
    m.size();        // Number of elements
    m.empty();       // Is empty?

Iterators:
    m.begin(), m.end()
    m.rbegin(), m.rend()

Time Complexity:
    All operations: O(log n)

Space Complexity:
    O(n) where n = number of key-value pairs

================================================================================
*/