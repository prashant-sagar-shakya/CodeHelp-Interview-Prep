/*
================================================================================
                    SECTION 5: STACK
================================================================================

What is std::stack?
- Follows LIFO (Last In, First Out) principle
- Like a stack of plates - last plate added is first to be removed
- It's an ADAPTER - uses another container internally (default: deque)

Key Features:
- Can only access the TOP element
- No iteration possible
- All operations are O(1)

When to use:
- Expression evaluation (balanced parentheses, infix to postfix)
- DFS in graphs/trees
- Undo mechanisms
- Function call simulation
- Any LIFO scenario

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "==========================================" << endl;
    cout << "        STACK" << endl;
    cout << "==========================================" << endl;

    // ========================================================================
    // CREATING STACK
    // ========================================================================

    cout << "\n--- CREATING STACK ---" << endl;

    // Default stack (uses deque internally)
    stack<int> st1;

    // Stack using specific container
    stack<int, vector<int>> st2; // Uses vector
    stack<int, list<int>> st3;   // Uses list
    stack<int, deque<int>> st4;  // Uses deque (default)

    // ========================================================================
    // BASIC OPERATIONS
    // ========================================================================

    cout << "\n--- BASIC OPERATIONS ---" << endl;

    stack<int> st;

    // push() - Add element on TOP
    st.push(10); // Stack: [10]
    st.push(20); // Stack: [10, 20] (20 is on top)
    st.push(30); // Stack: [10, 20, 30] (30 is on top)
    st.push(40); // Stack: [10, 20, 30, 40] (40 is on top)

    // top() - See TOP element (doesn't remove it)
    cout << "Top element: " << st.top() << endl; // Output: 40

    // pop() - Remove TOP element (doesn't return it!)
    st.pop();                                       // Removes 40, now stack = [10, 20, 30]
    cout << "After pop, top: " << st.top() << endl; // Output: 30

    // size() and empty()
    cout << "Size: " << st.size() << endl;                    // 3
    cout << "Empty: " << (st.empty() ? "Yes" : "No") << endl; // No

    // ========================================================================
    // PRACTICAL EXAMPLE: Balanced Parentheses
    // ========================================================================

    cout << "\n--- BALANCED PARENTHESES CHECK ---" << endl;

    string expr1 = "{[()]}"; // Balanced
    string expr2 = "{[(])}"; // Not balanced
    string expr3 = "({[]})"; // Balanced

    auto checkBalanced = [](string expr) -> bool
    {
        stack<char> s;
        for (char c : expr)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                s.push(c);
            }
            else if (c == ')')
            {
                if (s.empty() || s.top() != '(')
                    return false;
                s.pop();
            }
            else if (c == ']')
            {
                if (s.empty() || s.top() != '[')
                    return false;
                s.pop();
            }
            else if (c == '}')
            {
                if (s.empty() || s.top() != '{')
                    return false;
                s.pop();
            }
        }
        return s.empty();
    };

    cout << expr1 << " is " << (checkBalanced(expr1) ? "balanced" : "not balanced") << endl;
    cout << expr2 << " is " << (checkBalanced(expr2) ? "balanced" : "not balanced") << endl;
    cout << expr3 << " is " << (checkBalanced(expr3) ? "balanced" : "not balanced") << endl;

    // ========================================================================
    // PRACTICAL EXAMPLE: Reversing a String
    // ========================================================================

    cout << "\n--- REVERSE A STRING ---" << endl;

    string str = "Hello World";
    stack<char> s;

    // Push all characters
    for (char c : str)
    {
        s.push(c);
    }

    // Pop all characters (reversed)
    string reversed = "";
    while (!s.empty())
    {
        reversed += s.top();
        s.pop();
    }

    cout << "Original: " << str << endl;
    cout << "Reversed: " << reversed << endl;

    // ========================================================================
    // PRACTICAL EXAMPLE: Stock Span Problem
    // ========================================================================

    cout << "\n--- STOCK SPAN PROBLEM ---" << endl;

    // Stock prices for 7 days
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span(7);

    // For each day, find how many consecutive days before had lower price
    for (int i = 0; i < 7; i++)
    {
        span[i] = 1; // At least itself
        int j = i - 1;
        while (j >= 0 && prices[j] <= prices[i])
        {
            span[i] += span[j];
            j -= span[j]; // Jump to the previous span's start
        }
    }

    cout << "Prices: ";
    for (int p : prices)
        cout << p << " ";
    cout << endl;

    cout << "Spans:  ";
    for (int s : span)
        cout << s << " ";
    cout << endl;

    // ========================================================================
    // PRACTICAL EXAMPLE: Next Greater Element
    // ========================================================================

    cout << "\n--- NEXT GREATER ELEMENT ---" << endl;

    vector<int> arr = {4, 5, 2, 25};
    vector<int> result(arr.size(), -1);

    // For each element, find next greater element to its right
    stack<pair<int, int>> stk; // pair of (value, index)

    for (int i = 0; i < arr.size(); i++)
    {
        // While stack is not empty and current element > top of stack
        while (!stk.empty() && arr[i] > stk.top().first)
        {
            result[stk.top().second] = arr[i];
            stk.pop();
        }
        stk.push({arr[i], i});
    }

    cout << "Array:  ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    cout << "Next Greater: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    // ========================================================================
    // PRACTICAL EXAMPLE: DFS (Depth First Search)
    // ========================================================================

    cout << "\n--- DFS SIMULATION ---" << endl;

    // Simple graph representation: adjacency list
    // 0 -> 1, 2
    // 1 -> 0, 3
    // 2 -> 0, 3
    // 3 -> 1, 2

    vector<vector<int>> graph = {
        {1, 2}, // 0 connected to 1, 2
        {0, 3}, // 1 connected to 0, 3
        {0, 3}, // 2 connected to 0, 3
        {1, 2}  // 3 connected to 1, 2
    };

    vector<bool> visited(4, false);
    stack<int> dfsStack;

    // Start DFS from node 0
    dfsStack.push(0);
    visited[0] = true;

    cout << "DFS traversal: ";
    while (!dfsStack.empty())
    {
        int node = dfsStack.top();
        dfsStack.pop();
        cout << node << " ";

        // Add all unvisited neighbors (in reverse order for correct order)
        for (int i = graph[node].size() - 1; i >= 0; i--)
        {
            int neighbor = graph[node][i];
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                dfsStack.push(neighbor);
            }
        }
    }
    cout << endl;

    // ========================================================================
    // IMPORTANT NOTES
    // ========================================================================

    cout << "\n--- IMPORTANT NOTES ---" << endl;

    // 1. LIFO Principle:
    //    - Last element added is first to be removed
    //    - Like a stack of plates or books

    // 2. Container Adapter:
    //    - stack is an adapter, not a full container
    //    - Uses deque (default), vector, or list internally
    //    - Can't access elements except top

    // 3. Operations:
    //    - push() - O(1)
    //    - pop() - O(1) - doesn't return value!
    //    - top() - O(1)
    //    - size() - O(1)
    //    - empty() - O(1)

    // 4. Use Cases:
    //    - Expression evaluation
    //    - DFS traversal
    //    - Undo functionality
    //    - Matching problems

    cout << "\n==========================================" << endl;
    cout << "        STACK COMPLETED!" << endl;
    cout << "==========================================" << endl;

    return 0;
}

/*
================================================================================
                         QUICK REFERENCE
================================================================================

Creating:
    stack<int> st;                    // Default (uses deque)
    stack<int, vector<int>> st;       // Using vector
    stack<int, list<int>> st;         // Using list
    stack<int, deque<int>> st;        // Using deque

Operations:
    st.push(x);      // Add x on top (O(1))
    st.pop();        // Remove top (O(1)) - doesn't return!
    st.top();        // See top element (O(1))
    st.size();       // Number of elements (O(1))
    st.empty();      // Is empty? (O(1))

Important:
    - pop() doesn't return the removed element!
    - Always use top() + pop() together if you need the value

Use Cases:
    - Balanced parentheses
    - Infix to postfix conversion
    - DFS in graphs/trees
    - Undo mechanisms
    - Expression evaluation

Time Complexity:
    All operations: O(1)

================================================================================
*/