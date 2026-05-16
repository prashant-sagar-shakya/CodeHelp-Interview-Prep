/*
================================================================================
                    SECTION 9: STL ALGORITHMS
================================================================================

STL provides 100+ algorithms. Here are the most important ones:

Time & Space Complexity Overview:
- sort: O(n log n) time, O(1) extra space (in-place)
- stable_sort: O(n log n) time, O(n) space
- binary_search: O(log n) time, O(1) space
- lower_bound/upper_bound: O(log n) time, O(1) space
- find: O(n) time, O(1) space
- transform: O(n) time, O(n) or O(1) space (depends on output)
- accumulate: O(n) time, O(1) space

Categories:
1. Sorting: sort, stable_sort, partial_sort, nth_element
2. Searching: binary_search, lower_bound, upper_bound
3. Transformation: transform, for_each
4. Numeric: accumulate, min, max
5. Utility: find, count, copy, remove

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "        STL ALGORITHMS" << endl;
    cout << "==========================================" << endl;

    // ========================================================================
    // 1. SORTING ALGORITHMS
    // ========================================================================

    cout << "\n========== SORTING ALGORITHMS ==========" << endl;

    // --- sort() - O(n log n) ---
    cout << "\n--- sort() - O(n log n) ---" << endl;

    vector<int> v1 = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    cout << "Before sort: ";
    for (int x : v1)
        cout << x << " ";
    cout << endl;

    sort(v1.begin(), v1.end()); // Sort ascending
    cout << "After sort (ascending): ";
    for (int x : v1)
        cout << x << " ";
    cout << endl;

    sort(v1.begin(), v1.end(), greater<int>()); // Sort descending
    cout << "After sort (descending): ";
    for (int x : v1)
        cout << x << " ";
    cout << endl;

    // Custom comparator (sort by absolute value)
    vector<int> v2 = {-3, 1, -2, 4, -1};
    sort(v2.begin(), v2.end(), [](int a, int b)
         {
             return abs(a) < abs(b); // Sort by absolute value
         });
    cout << "Sort by absolute value: ";
    for (int x : v2)
        cout << x << " ";
    cout << endl;

    // --- stable_sort() - O(n log n), maintains order of equal elements ---
    cout << "\n--- stable_sort() - O(n log n) ---" << endl;

    vector<pair<int, char>> v3 = {{1, 'b'}, {1, 'a'}, {2, 'c'}};
    stable_sort(v3.begin(), v3.end(), [](auto &a, auto &b)
                { return a.first < b.first; });
    // Result: {{1, 'b'}, {1, 'a'}, {2, 'c'}} - 'b' before 'a' maintained!
    cout << "Stable sort (maintains relative order): ";
    for (auto &p : v3)
        cout << p.first << p.second << " ";
    cout << endl;

    // --- partial_sort() - O(n log k) ---
    cout << "\n--- partial_sort() - O(n log k) ---" << endl;

    vector<int> v4 = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    partial_sort(v4.begin(), v4.begin() + 3, v4.end());
    // First 3 elements are smallest 3 (sorted), rest are unspecified
    cout << "Partial sort (first 3 are smallest): ";
    for (int x : v4)
        cout << x << " ";
    cout << endl;

    // --- nth_element() - O(n) on average ---
    cout << "\n--- nth_element() - O(n) average ---" << endl;

    vector<int> v5 = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    nth_element(v5.begin(), v5.begin() + 4, v5.end());
    // Element at position 4 is 5th smallest (index 4), but rest are unsorted!
    cout << "nth_element (5th smallest at index 4): ";
    for (int x : v5)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // 2. SEARCHING ALGORITHMS
    // ========================================================================

    cout << "\n========== SEARCHING ALGORITHMS ==========" << endl;

    // IMPORTANT: Binary search requires SORTED range!

    // --- binary_search() - O(log n) ---
    cout << "\n--- binary_search() - O(log n) ---" << endl;

    vector<int> sortedV = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bool found = binary_search(sortedV.begin(), sortedV.end(), 5);
    cout << "Binary search for 5: " << (found ? "Found" : "Not found") << endl;

    found = binary_search(sortedV.begin(), sortedV.end(), 15);
    cout << "Binary search for 15: " << (found ? "Found" : "Not found") << endl;

    // With custom comparator
    found = binary_search(sortedV.begin(), sortedV.end(), 5, greater<int>());
    cout << "Binary search (descending): " << (found ? "Found" : "Not found") << endl;

    // --- lower_bound() - O(log n) ---
    cout << "\n--- lower_bound() - O(log n) ---" << endl;

    vector<int> v6 = {1, 2, 3, 3, 3, 4, 5};
    auto lb = lower_bound(v6.begin(), v6.end(), 3);
    // First element >= 3 (first 3)
    if (lb != v6.end())
    {
        cout << "Lower bound of 3: index " << (lb - v6.begin()) << ", value " << *lb << endl;
    }

    // --- upper_bound() - O(log n) ---
    cout << "\n--- upper_bound() - O(log n) ---" << endl;

    auto ub = upper_bound(v6.begin(), v6.end(), 3);
    // First element > 3 (first 4)
    if (ub != v6.end())
    {
        cout << "Upper bound of 3: index " << (ub - v6.begin()) << ", value " << *ub << endl;
    }

    // --- equal_range() - O(log n) ---
    cout << "\n--- equal_range() - O(log n) ---" << endl;

    auto range = equal_range(v6.begin(), v6.end(), 3);
    // Returns pair of {first >= 3, first > 3}
    int cnt = range.second - range.first;
    cout << "Number of 3s: " << cnt << endl;

    // ========================================================================
    // 3. TRANSFORMATION ALGORITHMS
    // ========================================================================

    cout << "\n========== TRANSFORMATION ALGORITHMS ==========" << endl;

    // --- for_each() - O(n) ---
    cout << "\n--- for_each() - O(n) ---" << endl;

    vector<int> v7 = {1, 2, 3, 4, 5};
    cout << "for_each (multiply by 2): ";
    for_each(v7.begin(), v7.end(), [](int x)
             { cout << x * 2 << " "; });
    cout << endl;

    // --- transform() - O(n) ---
    cout << "\n--- transform() - O(n) ---" << endl;

    vector<int> v8 = {1, 2, 3, 4, 5};
    vector<int> result;

    // Unary transform (single input)
    result.resize(v8.size());
    transform(v8.begin(), v8.end(), result.begin(), [](int x)
              {
                  return x * x; // Square each element
              });
    cout << "Transform (square): ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    // Binary transform (two inputs)
    vector<int> a = {1, 2, 3};
    vector<int> b = {10, 20, 30};
    vector<int> sum(3);
    transform(a.begin(), a.end(), b.begin(), sum.begin(), [](int x, int y)
              { return x + y; });
    cout << "Transform (add two vectors): ";
    for (int x : sum)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // 4. NUMERIC ALGORITHMS
    // ========================================================================

    cout << "\n========== NUMERIC ALGORITHMS ==========" << endl;

    // --- accumulate() - O(n) ---
    cout << "\n--- accumulate() - O(n) ---" << endl;

    vector<int> v9 = {1, 2, 3, 4, 5};

    int sum1 = accumulate(v9.begin(), v9.end(), 0);
    cout << "Sum: " << sum1 << endl;

    int product = accumulate(v9.begin(), v9.end(), 1, [](int a, int b)
                             { return a * b; });
    cout << "Product: " << product << endl;

    // --- min_element() and max_element() - O(n) ---
    cout << "\n--- min_element/max_element - O(n) ---" << endl;

    auto minIt = min_element(v9.begin(), v9.end());
    auto maxIt = max_element(v9.begin(), v9.end());
    cout << "Min: " << *minIt << ", Max: " << *maxIt << endl;

    // --- minmax_element() - O(n) ---
    cout << "\n--- minmax_element - O(n) ---" << endl;

    auto [minVal, maxVal] = minmax_element(v9.begin(), v9.end());
    cout << "Min: " << *minVal << ", Max: " << *maxVal << endl;

    // ========================================================================
    // 5. UTILITY ALGORITHMS
    // ========================================================================

    cout << "\n========== UTILITY ALGORITHMS ==========" << endl;

    // --- find() - O(n) ---
    cout << "\n--- find() - O(n) ---" << endl;

    vector<int> v10 = {1, 2, 3, 4, 5};
    auto findIt = find(v10.begin(), v10.end(), 3);
    if (findIt != v10.end())
    {
        cout << "Found 3 at index: " << (findIt - v10.begin()) << endl;
    }

    // --- find_if() - O(n) ---
    cout << "\n--- find_if() - O(n) ---" << endl;

    auto evenIt = find_if(v10.begin(), v10.end(), [](int x)
                          { return x % 2 == 0; });
    if (evenIt != v10.end())
    {
        cout << "First even number: " << *evenIt << endl;
    }

    // --- find_if_not() ---
    cout << "\n--- find_if_not() - O(n) ---" << endl;

    auto oddIt = find_if_not(v10.begin(), v10.end(), [](int x)
                             { return x % 2 == 0; });
    if (oddIt != v10.end())
    {
        cout << "First odd number: " << *oddIt << endl;
    }

    // --- count() - O(n) ---
    cout << "\n--- count() - O(n) ---" << endl;

    vector<int> v11 = {1, 2, 2, 3, 2, 4};
    int twos = count(v11.begin(), v11.end(), 2);
    cout << "Number of 2s: " << twos << endl;

    // --- count_if() - O(n) ---
    cout << "\n--- count_if() - O(n) ---" << endl;

    int evens = count_if(v11.begin(), v11.end(), [](int x)
                         { return x % 2 == 0; });
    cout << "Number of even numbers: " << evens << endl;

    // --- copy() - O(n) ---
    cout << "\n--- copy() - O(n) ---" << endl;

    vector<int> source = {1, 2, 3, 4, 5};
    vector<int> destination(5);
    copy(source.begin(), source.end(), destination.begin());
    cout << "Copied: ";
    for (int x : destination)
        cout << x << " ";
    cout << endl;

    // --- remove() and remove_if() - O(n) ---
    cout << "\n--- remove() - O(n) ---" << endl;

    vector<int> v12 = {1, 2, 3, 2, 4, 2, 5};
    auto newEnd = remove(v12.begin(), v12.end(), 2); // Remove all 2s
    v12.erase(newEnd, v12.end());                    // Erase removed elements
    cout << "After remove(2): ";
    for (int x : v12)
        cout << x << " ";
    cout << endl;

    // --- replace() - O(n) ---
    cout << "\n--- replace() - O(n) ---" << endl;

    vector<int> v13 = {1, 2, 3, 2, 4};
    replace(v13.begin(), v13.end(), 2, 20); // Replace all 2s with 20
    cout << "After replace(2, 20): ";
    for (int x : v13)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // 6. SET ALGORITHMS (on sorted ranges)
    // ========================================================================

    cout << "\n========== SET ALGORITHMS ==========" << endl;

    // Note: These require sorted input ranges!

    vector<int> set1 = {1, 2, 3, 4, 5};
    vector<int> set2 = {3, 4, 5, 6, 7};

    // set_union - O(n + m)
    vector<int> unionResult;
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(),
              back_inserter(unionResult));
    cout << "Union: ";
    for (int x : unionResult)
        cout << x << " ";
    cout << endl;

    // set_intersection - O(n + m)
    vector<int> intersectionResult;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                     back_inserter(intersectionResult));
    cout << "Intersection: ";
    for (int x : intersectionResult)
        cout << x << " ";
    cout << endl;

    // set_difference - O(n + m)
    vector<int> diffResult;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                   back_inserter(diffResult));
    cout << "Difference (set1 - set2): ";
    for (int x : diffResult)
        cout << x << " ";
    cout << endl;

    // set_symmetric_difference - O(n + m)
    vector<int> symDiffResult;
    set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                             back_inserter(symDiffResult));
    cout << "Symmetric difference: ";
    for (int x : symDiffResult)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // SUMMARY OF COMPLEXITIES
    // ========================================================================

    cout << "\n========== COMPLEXITY SUMMARY ==========" << endl;
    cout << "sort:                  O(n log n), O(1) space" << endl;
    cout << "stable_sort:          O(n log n), O(n) space" << endl;
    cout << "partial_sort:         O(n log k), O(k) space" << endl;
    cout << "nth_element:          O(n) avg, O(1) space" << endl;
    cout << "binary_search:        O(log n), O(1) space" << endl;
    cout << "lower/upper_bound:    O(log n), O(1) space" << endl;
    cout << "find:                 O(n), O(1) space" << endl;
    cout << "count:                O(n), O(1) space" << endl;
    cout << "transform:            O(n), O(n) or O(1) space" << endl;
    cout << "accumulate:           O(n), O(1) space" << endl;
    cout << "set_union:            O(n + m), O(n + m) space" << endl;

    cout << "\n==========================================" << endl;
    cout << "        STL ALGORITHMS COMPLETED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}

/*
================================================================================
                         QUICK REFERENCE
================================================================================

SORTING:
    sort(begin, end);           // O(n log n)
    sort(begin, end, comp);      // O(n log n)
    stable_sort(begin, end);    // O(n log n), maintains order
    partial_sort(begin, begin+k, end);  // O(n log k)
    nth_element(begin, begin+n, end);    // O(n) avg

SEARCHING (sorted):
    binary_search(begin, end, x);    // O(log n)
    lower_bound(begin, end, x);      // O(log n), first >= x
    upper_bound(begin, end, x);      // O(log n), first > x
    equal_range(begin, end, x);      // O(log n), both bounds

SEARCHING (unsorted):
    find(begin, end, x);         // O(n)
    find_if(begin, end, pred);  // O(n)
    find_if_not(begin, end, pred);  // O(n)

COUNTING:
    count(begin, end, x);       // O(n)
    count_if(begin, end, pred); // O(n)

TRANSFORMATION:
    for_each(begin, end, func);         // O(n)
    transform(begin, end, out, func);   // O(n)

NUMERIC:
    accumulate(begin, end, init);           // O(n)
    accumulate(begin, end, init, binary_op); // O(n)
    min_element(begin, end);  // O(n)
    max_element(begin, end);  // O(n)

MODIFICATION:
    copy(begin, end, out);            // O(n)
    remove(begin, end, x);            // O(n)
    remove_if(begin, end, pred);      // O(n)
    replace(begin, end, old, new);    // O(n)

SET OPERATIONS (sorted):
    set_union(begin1, end1, begin2, end2, out);   // O(n+m)
    set_intersection(begin1, end1, begin2, end2, out);  // O(n+m)
    set_difference(begin1, end1, begin2, end2, out);  // O(n+m)

================================================================================
*/