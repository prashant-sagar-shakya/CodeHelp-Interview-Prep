/*
================================================================================
                    SECTION 4: LIST
================================================================================

What is std::list?
- Doubly linked list implementation
- Each element has pointers to next and previous
- Elements are NOT stored contiguously

Key Features:
- O(1) insertion/deletion at ANY position (given iterator)
- NO random access (can't use [])
- No contiguous memory
- Can iterate forward and backward

When to use:
- When you need frequent insertions/deletions in the middle
- When you DON'T need random access
- When you need to iterate while modifying
- For implementing other data structures

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "        LIST" << endl;
    cout << "==========================================" << endl;

    // ========================================================================
    // CREATING LIST
    // ========================================================================

    cout << "\n--- CREATING LIST ---" << endl;

    // Empty list
    list<int> lst1;

    // With size (all elements = 0)
    list<int> lst2(5);

    // With size and initial value
    list<int> lst3(5, 100); // {100, 100, 100, 100, 100}

    // With initializer list
    list<int> lst4 = {1, 2, 3, 4, 5};

    cout << "lst4 = ";
    for (int x : lst4)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // ADDING ELEMENTS
    // ========================================================================

    cout << "\n--- ADDING ELEMENTS ---" << endl;

    list<int> lst;

    // push_back() - Add at end (O(1))
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    // lst = {10, 20, 30}

    // push_front() - Add at beginning (O(1))
    lst.push_front(5);
    lst.push_front(1);
    // lst = {1, 5, 10, 20, 30}

    cout << "After push_front/push_back: ";
    for (int x : lst)
        cout << x << " ";
    cout << endl;

    // emplace_front() and emplace_back() - Construct in place
    lst.emplace_front(0);
    lst.emplace_back(40);

    // insert() - Insert at any position (O(1) if you have iterator!)
    // This is the key advantage of list over vector!
    auto it = lst.begin(); // Points to first element (0)
    it++;                  // Move to second element (1)
    it++;                  // Move to third element (5)
    lst.insert(it, 100);   // Insert 100 after 5
    // lst = {0, 1, 5, 100, 10, 20, 30, 40}

    cout << "After insert at position: ";
    for (int x : lst)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // REMOVING ELEMENTS
    // ========================================================================

    cout << "\n--- REMOVING ELEMENTS ---" << endl;

    list<int> lstA = {10, 20, 30, 20, 40, 20, 50};

    // pop_front() - Remove first element (O(1))
    lstA.pop_front(); // Removes 10

    // pop_back() - Remove last element (O(1))
    lstA.pop_back(); // Removes 50

    cout << "After pop_front/pop_back: ";
    for (int x : lstA)
        cout << x << " ";
    cout << endl;

    // erase() - Remove at position (O(1) if you have iterator!)
    auto it2 = lstA.begin();
    it2++;           // Point to 20
    lstA.erase(it2); // Removes that 20

    cout << "After erase: ";
    for (int x : lstA)
        cout << x << " ";
    cout << endl;

    // remove() - Remove ALL occurrences of a value (O(n))
    lstA.push_back(20);
    lstA.push_back(20);
    // lstA = {20, 30, 40, 20, 20}
    lstA.remove(20); // Removes ALL 20s!
    // lstA = {30, 40}

    cout << "After remove(20): ";
    for (int x : lstA)
        cout << x << " ";
    cout << endl;

    // remove_if() - Remove elements satisfying condition
    list<int> lstB = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    lstB.remove_if([](int x)
                   { return x % 2 == 0; }); // Remove all even numbers
    // lst3 = {1, 3, 5, 7, 9}

    cout << "After remove_if (even numbers): ";
    for (int x : lstB)
        cout << x << " ";
    cout << endl;

    // clear() - Remove all elements
    lst3.clear();

    // ========================================================================
    // LIST-SPECIFIC OPERATIONS
    // ========================================================================

    cout << "\n--- LIST-SPECIFIC OPERATIONS ---" << endl;

    // unique() - Remove consecutive duplicates
    list<int> lstUnique = {1, 1, 2, 2, 2, 3, 3, 1, 1};
    lst4.unique(); // Only removes CONSECUTIVE duplicates
    // lst4 = {1, 2, 3, 1}
    cout << "After unique: ";
    for (int x : lst4)
        cout << x << " ";
    cout << endl;

    // sort() - Sort the list (list has its own sort!)
    // Note: Can't use std::sort on list (no random access)
    lst4 = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    lst4.sort(); // Ascending order
    // lst4 = {1, 2, 3, 4, 5, 6, 7, 8, 9}
    cout << "After sort: ";
    for (int x : lst4)
        cout << x << " ";
    cout << endl;

    // sort with comparator
    lst4.sort(greater<int>()); // Descending

    // reverse() - Reverse the list
    lst4.reverse();
    // lst4 = {9, 8, 7, 6, 5, 4, 3, 2, 1}
    cout << "After reverse: ";
    for (int x : lst4)
        cout << x << " ";
    cout << endl;

    // merge() - Merge two sorted lists
    list<int> lst5 = {1, 3, 5};
    list<int> lst6 = {2, 4, 6};
    lst5.merge(lst6); // lst5 becomes {1, 2, 3, 4, 5, 6}, lst6 becomes empty
    cout << "After merge: ";
    for (int x : lst5)
        cout << x << " ";
    cout << endl;

    // splice() - Move elements from another list
    list<int> lst7 = {1, 2, 3};
    list<int> lst8 = {10, 20, 30};
    lst7.splice(lst7.begin(), lst8); // Move lst8 into lst7 at begin
    // lst7 = {10, 20, 30, 1, 2, 3}, lst8 becomes empty

    // ========================================================================
    // ITERATING
    // ========================================================================

    cout << "\n--- ITERATING ---" << endl;

    list<int> lst9 = {1, 2, 3, 4, 5};

    // Forward iteration
    cout << "Forward: ";
    for (int x : lst9)
    {
        cout << x << " ";
    }
    cout << endl;

    // Backward iteration using reverse iterators
    cout << "Backward: ";
    for (auto it = lst9.rbegin(); it != lst9.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Using iterators manually
    cout << "Using iterators: ";
    for (auto it = lst9.begin(); it != lst9.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // ========================================================================
    // ACCESSING ELEMENTS (No random access!)
    // ========================================================================

    cout << "\n--- ACCESSING ELEMENTS ---" << endl;

    list<int> lst10 = {10, 20, 30, 40, 50};

    // front() and back() - O(1)
    cout << "Front: " << lst10.front() << endl; // 10
    cout << "Back: " << lst10.back() << endl;   // 50

    // Cannot use lst10[0] or lst10.at(0)!
    // Must use iterators to access any element

    // ========================================================================
    // SIZE OPERATIONS
    // ========================================================================

    cout << "\n--- SIZE OPERATIONS ---" << endl;

    list<int> lst11 = {1, 2, 3};
    cout << "Size: " << lst11.size() << endl;
    cout << "Empty: " << (lst11.empty() ? "Yes" : "No") << endl;
    cout << "Max size: " << lst11.max_size() << endl; // Very large number

    // ========================================================================
    // IMPORTANT NOTES
    // ========================================================================

    cout << "\n--- IMPORTANT NOTES ---" << endl;

    // 1. No Random Access:
    //    - Can't use [] or .at()
    //    - Must use iterators to access elements
    //    - Accessing nth element is O(n)

    // 2. Insertion/Deletion:
    //    - O(1) at any position (given iterator!)
    //    - Much faster than vector for middle insertions

    // 3. Memory:
    //    - Not contiguous (each node has prev/next pointers)
    //    - More memory overhead than vector
    //    - Not cache-friendly

    // 4. When to use list:
    //    - Frequent insertions/deletions in the middle
    //    - Don't need random access
    //    - Need to iterate while modifying

    // 5. When NOT to use list:
    //    - Need random access (use vector)
    //    - Mostly appending at end (use vector)
    //    - Cache performance matters (use vector)

    cout << "\n==========================================" << endl;
    cout << "        LIST COMPLETED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}

/*
================================================================================
                         QUICK REFERENCE
================================================================================

Creating:
    list<int> lst;           // Empty
    list<int> lst(5);        // 5 elements, value = 0
    list<int> lst(5, 100);   // 5 elements, value = 100
    list<int> lst = {1,2,3}; // Initializer list

Adding:
    lst.push_back(x);    // Add at end (O(1))
    lst.push_front(x);   // Add at front (O(1))
    lst.insert(it, x);   // Insert at iterator (O(1))

Removing:
    lst.pop_back();      // Remove from end (O(1))
    lst.pop_front();     // Remove from front (O(1))
    lst.erase(it);       // Remove at iterator (O(1))
    lst.remove(x);       // Remove all x (O(n))
    lst.remove_if(pred); // Remove if predicate true
    lst.clear();         // Remove all

Accessing:
    lst.front();    // First element (O(1))
    lst.back();     // Last element (O(1))
    // NO [] or .at() - no random access!

Size:
    lst.size();     // Number of elements
    lst.empty();    // Is empty?
    lst.max_size(); // Very large number

List-specific:
    lst.sort();           // Sort (O(n log n))
    lst.sort(comp);       // Sort with comparator
    lst.reverse();        // Reverse
    lst.unique();         // Remove consecutive duplicates
    lst.merge(lst2);       // Merge two sorted lists
    lst.splice(it, lst2); // Move elements from lst2

Iterators:
    lst.begin(), lst.end()
    lst.rbegin(), lst.rend()

Algorithms:
    Limited! Can't use std::sort, but has its own sort()
    Can use: find, for_each, count, etc.

Time Complexity:
    Random access:      O(n) - NO random access!
    push_front:       O(1)
    push_back:        O(1)
    pop_front:        O(1)
    pop_back:         O(1)
    insert at any:     O(1) - given iterator!
    remove at any:    O(1) - given iterator!
    search:           O(n)

================================================================================
*/