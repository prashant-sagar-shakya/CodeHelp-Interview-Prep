/*
================================================================================
                    SECTION 3: DEQUE
================================================================================

What is std::deque? (Double-Ended Queue)
- Allows insertion and deletion from BOTH ENDS in O(1) time
- Like vector but with efficient front insertion
- NOT stored in contiguous memory (uses blocks)

Key Features:
- Fast insertion/removal at both front and back: O(1)
- Random access like vector: O(1)
- No contiguous memory (can grow in both directions efficiently)

When to use:
- When you need to frequently add/remove from front
- When you need both front and back operations
- When implementing queues or deques
- When you need random access + fast front operations

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "        DEQUE" << endl;
    cout << "==========================================" << endl;

    // ========================================================================
    // CREATING DEQUE
    // ========================================================================

    cout << "\n--- CREATING DEQUE ---" << endl;

    // Empty deque
    deque<int> dq1;

    // With initial size
    deque<int> dq2(5);      // 5 elements, all 0
    deque<int> dq3(5, 100); // 5 elements, all 100

    // With initializer list
    deque<int> dq4 = {1, 2, 3, 4, 5};

    cout << "dq4 = ";
    for (int x : dq4)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // ADDING ELEMENTS
    // ========================================================================

    cout << "\n--- ADDING ELEMENTS ---" << endl;

    deque<int> dq;

    // push_back() - Add at BACK (O(1))
    dq.push_back(10); // dq = {10}
    dq.push_back(20); // dq = {10, 20}
    dq.push_back(30); // dq = {10, 20, 30}
    cout << "After push_back: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // push_front() - Add at FRONT (O(1)) - Unlike vector!
    dq.push_front(5); // dq = {5, 10, 20, 30}
    dq.push_front(1); // dq = {1, 5, 10, 20, 30}
    cout << "After push_front: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // emplace_back() and emplace_front() - Construct in place
    dq.emplace_back(40); // Add at back
    dq.emplace_front(0); // Add at front

    // insert() - Insert at any position (O(n))
    dq.insert(dq.begin() + 2, 15); // Insert 15 at index 2
    cout << "After insert: ";
    for (int x : dq)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // REMOVING ELEMENTS
    // ========================================================================

    cout << "\n--- REMOVING ELEMENTS ---" << endl;

    deque<int> dqNew = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // pop_back() - Remove from BACK (O(1))
    dqNew.pop_back(); // Removes 9
    // dqNew = {1, 2, 3, 4, 5, 6, 7, 8}

    // pop_front() - Remove from FRONT (O(1)) - Unlike vector!
    dqNew.pop_front(); // Removes 1
    // dqNew = {2, 3, 4, 5, 6, 7, 8}

    cout << "After pops: ";
    for (int x : dqNew)
        cout << x << " ";
    cout << endl;

    // erase() - Remove at position (O(n))
    dqNew.erase(dqNew.begin() + 2); // Remove element at index 2

    // clear() - Remove all
    dqNew.clear();

    // ========================================================================
    // ACCESSING ELEMENTS
    // ========================================================================

    cout << "\n--- ACCESSING ELEMENTS ---" << endl;

    deque<int> dqA = {10, 20, 30, 40, 50};

    // Random access (like vector) - O(1)
    cout << "dqA[0] = " << dqA[0] << endl;       // 10
    cout << "dqA.at(2) = " << dqA.at(2) << endl; // 30
    cout << "dqA[4] = " << dqA[4] << endl;       // 50

    // front() and back()
    cout << "Front: " << dq3.front() << endl; // 10
    cout << "Back: " << dq3.back() << endl;   // 50

    // ========================================================================
    // SIZE OPERATIONS
    // ========================================================================

    cout << "\n--- SIZE OPERATIONS ---" << endl;

    deque<int> dqB = {1, 2, 3};
    cout << "Size: " << dqB.size() << endl;
    cout << "Empty: " << (dqB.empty() ? "Yes" : "No") << endl;

    // resize() - Change size
    dqB.resize(5);      // Add zeros to make size 5
    dqB.resize(7, 100); // Add 100s to make size 7

    // ========================================================================
    // ITERATORS
    // ========================================================================

    cout << "\n--- ITERATORS ---" << endl;

    deque<int> dq5 = {1, 2, 3, 4, 5};

    // Forward iteration
    cout << "Forward: ";
    for (auto it = dq5.begin(); it != dq5.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse iteration
    cout << "Reverse: ";
    for (auto it = dq5.rbegin(); it != dq5.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // ========================================================================
    // USE CASES
    // ========================================================================

    cout << "\n--- USE CASES ---" << endl;

    // 1. Sliding Window Problem
    deque<int> window;
    vector<int> arr = {1, 2, 3, 4, 5};
    int windowSize = 3;

    // Add first 3 elements
    for (int i = 0; i < windowSize; i++)
    {
        window.push_back(arr[i]);
    }
    cout << "Window size 3: ";
    for (int x : window)
        cout << x << " ";
    cout << endl;

    // Slide the window
    window.pop_front();  // Remove 1
    window.push_back(6); // Add 6
    cout << "After sliding: ";
    for (int x : window)
        cout << x << " ";
    cout << endl;

    // 2. Implementing Queue (when you need random access)
    deque<int> q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    // Similar to queue but with random access

    // ========================================================================
    // IMPORTANT NOTES
    // ========================================================================

    cout << "\n--- IMPORTANT NOTES ---" << endl;

    // 1. Deque vs Vector:
    //    - Vector: O(1) push_back, O(n) push_front
    //    - Deque: O(1) push_front AND push_back

    // 2. Memory Layout:
    //    - Vector: contiguous memory
    //    - Deque: multiple blocks (not contiguous)
    //    - Random access is O(1) for both, but vector is slightly faster

    // 3. When to use:
    //    - Need fast insertion at front -> deque
    //    - Need both front and back operations -> deque
    //    - Otherwise, vector is usually better (more cache-friendly)

    // 4. When NOT to use:
    //    - Frequent insertions in middle (use list)
    //    - Need pointer stability (use vector)

    cout << "\n==========================================" << endl;
    cout << "        DEQUE COMPLETED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}

/*
================================================================================
                         QUICK REFERENCE
================================================================================

Creating:
    deque<int> dq;           // Empty
    deque<int> dq(5);       // 5 elements, value = 0
    deque<int> dq(5, 100);  // 5 elements, value = 100
    deque<int> dq = {1,2,3}; // Initializer list

Adding:
    dq.push_back(x);    // Add at back (O(1))
    dq.push_front(x);   // Add at front (O(1)) - unlike vector!
    dq.emplace_back(x); // Construct in place
    dq.emplace_front(x);// Construct in place at front

Removing:
    dq.pop_back();     // Remove from back (O(1))
    dq.pop_front();    // Remove from front (O(1)) - unlike vector!
    dq.erase(pos);     // Remove at position (O(n))
    dq.clear();        // Remove all

Accessing:
    dq[i];         // No bounds check
    dq.at(i);      // With bounds check
    dq.front();    // First element
    dq.back();     // Last element

Size:
    dq.size();     // Number of elements
    dq.empty();    // Is empty?
    dq.resize(n);  // Change size

Algorithms:
    Works with ALL STL algorithms!

Time Complexity:
    Random access:      O(1)
    push_front:       O(1)
    push_back:        O(1)
    pop_front:        O(1)
    pop_back:         O(1)
    insert at middle:  O(n)

================================================================================
*/