/*
================================================================================
                    SECTION 6: PRIORITY QUEUE
================================================================================

What is std::priority_queue?
- Heap data structure - always gives the highest (or lowest) element first
- Default is MAX-HEAP (largest element on top)
- Elements are automatically sorted

Key Features:
- O(log n) for insertion and removal
- Can only access top element
- Cannot iterate through elements

When to use:
- Finding k largest/smallest elements
- Dijkstra's algorithm (with min-heap)
- Task scheduling
- Merging sorted files
- Any scenario where you always need the extreme element

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "        PRIORITY QUEUE" << endl;
    cout << "==========================================" << endl;

    // ========================================================================
    // CREATING PRIORITY QUEUE
    // ========================================================================

    cout << "\n--- CREATING PRIORITY QUEUE ---" << endl;

    // Default: MAX-HEAP (largest element on top)
    priority_queue<int> maxHeap;

    // MIN-HEAP: Use std::greater as comparator
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // ========================================================================
    // MAX-HEAP (DEFAULT)
    // ========================================================================

    cout << "\n--- MAX-HEAP (DEFAULT) ---" << endl;

    priority_queue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(50);

    // Top will be the LARGEST element
    cout << "Top (largest): " << pq.top() << endl; // 50

    pq.pop();                                       // Removes 50
    cout << "After pop, top: " << pq.top() << endl; // 30

    // ========================================================================
    // MIN-HEAP
    // ========================================================================

    cout << "\n--- MIN-HEAP ---" << endl;

    priority_queue<int, vector<int>, greater<int>> minPq;

    minPq.push(10);
    minPq.push(30);
    minPq.push(20);
    minPq.push(5);
    minPq.push(1);

    // Top will be the SMALLEST element
    cout << "Top (smallest): " << minPq.top() << endl; // 1

    minPq.pop();
    cout << "After pop, top: " << minPq.top() << endl; // 5

    // ========================================================================
    // COMMON OPERATIONS
    // ========================================================================

    cout << "\n--- COMMON OPERATIONS ---" << endl;

    priority_queue<int> pq2;

    pq2.push(100); // Insert (O(log n))
    pq2.push(50);  // Insert
    pq2.push(200); // Insert
    pq2.push(10);  // Insert

    pq2.pop(); // Remove top (O(log n))

    int topVal = pq2.top();     // Access top (O(1))
    bool isEmpty = pq2.empty(); // Check empty (O(1))
    size_t sz = pq2.size();     // Get size (O(1))

    cout << "Top: " << topVal << ", Empty: " << (isEmpty ? "Yes" : "No")
         << ", Size: " << sz << endl;

    // ========================================================================
    // FINDING K LARGEST ELEMENTS
    // ========================================================================

    cout << "\n--- FIND K LARGEST ELEMENTS ---" << endl;

    vector<int> arr = {3, 2, 1, 5, 6, 4, 7, 10, 9};
    int k = 3;

    // Method 1: Using min-heap of size k
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int x : arr)
    {
        heap.push(x);
        if (heap.size() > k)
        {
            heap.pop();
        }
    }

    // Now heap has k largest elements, top is kth largest
    cout << k << "th largest element: " << heap.top() << endl;

    // Print all k largest elements
    cout << k << " largest elements: ";
    while (!heap.empty())
    {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;

    // ========================================================================
    // FINDING K SMALLEST ELEMENTS
    // ========================================================================

    cout << "\n--- FIND K SMALLEST ELEMENTS ---" << endl;

    // Method: Using max-heap of size k
    priority_queue<int> maxHeap2;
    for (int x : arr)
    {
        maxHeap2.push(x);
        if (maxHeap2.size() > k)
        {
            maxHeap2.pop();
        }
    }

    // Now heap has k smallest elements, top is kth smallest
    cout << k << "th smallest element: " << maxHeap2.top() << endl;

    // Print all k smallest elements
    cout << k << " smallest elements: ";
    while (!maxHeap2.empty())
    {
        cout << maxHeap2.top() << " ";
        maxHeap2.pop();
    }
    cout << endl;

    // ========================================================================
    // SORTING USING PRIORITY QUEUE
    // ========================================================================

    cout << "\n--- SORTING USING PRIORITY QUEUE ---" << endl;

    vector<int> toSort = {5, 2, 8, 1, 9, 3, 7, 4, 6};

    // Sort descending using max-heap
    priority_queue<int> sortHeap(toSort.begin(), toSort.end());
    cout << "Sorted descending: ";
    while (!sortHeap.empty())
    {
        cout << sortHeap.top() << " ";
        sortHeap.pop();
    }
    cout << endl;

    // Sort ascending using min-heap
    priority_queue<int, vector<int>, greater<int>> sortMinHeap(toSort.begin(), toSort.end());
    cout << "Sorted ascending: ";
    while (!sortMinHeap.empty())
    {
        cout << sortMinHeap.top() << " ";
        sortMinHeap.pop();
    }
    cout << endl;

    // ========================================================================
    // USING WITH CUSTOM TYPES
    // ========================================================================

    cout << "\n--- USING WITH PAIRS ---" << endl;

    // By default, compares by first element, then second
    priority_queue<pair<int, int>> pairHeap;

    pairHeap.push({1, 2});
    pairHeap.push({3, 4});
    pairHeap.push({1, 3});
    pairHeap.push({2, 5});

    // Top will be {3, 4} (largest first element)
    cout << "Top pair: (" << pairHeap.top().first << ", "
         << pairHeap.top().second << ")" << endl;

    // Using greater to get smallest first
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minPairHeap;
    minPairHeap.push({1, 2});
    minPairHeap.push({3, 4});
    minPairHeap.push({1, 3});

    // Top will be {1, 2} (smallest first element)
    cout << "Min pair heap top: (" << minPairHeap.top().first << ", "
         << minPairHeap.top().second << ")" << endl;

    // ========================================================================
    // CUSTOM COMPARATOR
    // ========================================================================

    cout << "\n--- CUSTOM COMPARATOR ---" << endl;

    // Example: Priority based on string length
    priority_queue<string, vector<string>, function<bool(string, string)>> customHeap(
        [](const string &a, const string &b)
        { return a.length() > b.length(); });

    customHeap.push("Apple");
    customHeap.push("Banana");
    customHeap.push("Cat");
    customHeap.push("Elephant");

    // Top will be longest string
    cout << "Longest string: " << customHeap.top() << endl;

    // ========================================================================
    // PRACTICAL EXAMPLE: TOP K FREQUENT ELEMENTS
    // ========================================================================

    cout << "\n--- TOP K FREQUENT ELEMENTS ---" << endl;

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    k = 2;

    // Count frequencies
    unordered_map<int, int> freq;
    for (int x : nums)
    {
        freq[x]++;
    }

    // Use min-heap based on frequency
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freqHeap;
    for (auto &p : freq)
    {
        freqHeap.push({p.second, p.first}); // {frequency, value}
        if (freqHeap.size() > k)
        {
            freqHeap.pop();
        }
    }

    cout << k << " most frequent elements: ";
    while (!freqHeap.empty())
    {
        cout << freqHeap.top().second << " "; // value
        freqHeap.pop();
    }
    cout << endl;

    // ========================================================================
    // IMPORTANT NOTES
    // ========================================================================

    cout << "\n--- IMPORTANT NOTES ---" << endl;

    // 1. Default is MAX-HEAP:
    //    - Largest element on top
    //    - Use std::greater for MIN-HEAP

    // 2. Cannot modify elements in the middle!

    // 3. Time Complexity:
    //    - push(): O(log n)
    //    - pop(): O(log n)
    //    - top(): O(1)
    //    - size(), empty(): O(1)

    // 4. Use Cases:
    //    - Find k largest/smallest
    //    - Dijkstra's algorithm
    //    - Task scheduling
    //    - Median of running stream

    // 5. Note: Cannot iterate through elements!

    cout << "\n==========================================" << endl;
    cout << "        PRIORITY QUEUE COMPLETED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}

/*
================================================================================
                         QUICK REFERENCE
================================================================================

Creating:
    priority_queue<int> pq;                    // Max-heap (default)
    priority_queue<int, vector<int>, greater<int>> pq;  // Min-heap

Operations:
    pq.push(x);       // Insert (O(log n))
    pq.pop();         // Remove top (O(log n))
    pq.top();         // Access top element (O(1))
    pq.size();        // Number of elements (O(1))
    pq.empty();       // Is empty? (O(1))

Important:
    - Default: MAX-HEAP (largest on top)
    - Use std::greater for MIN-HEAP
    - Cannot access elements in the middle!
    - Cannot iterate through elements

Use Cases:
    - Find k largest elements: min-heap of size k
    - Find k smallest elements: max-heap of size k
    - Dijkstra's algorithm
    - Task scheduling

Time Complexity:
    push():   O(log n)
    pop():    O(log n)
    top():    O(1)
    size():   O(1)
    empty():  O(1)

================================================================================
*/