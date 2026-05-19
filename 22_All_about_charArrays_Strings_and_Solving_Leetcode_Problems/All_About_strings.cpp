#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define endl '\n'

const ll MOD = 1e9 + 7;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
╔══════════════════════════════════════════════════════════════════════════════╗
║                    C++ STRINGS                                               ║
║                                                                              ║
║  In this file we will learn:                                                 ║
║  1. What is a string? (Actually an array of characters!)                     ║
║  2. How to declare and use strings                                           ║
║  3. Why cin >> string doesn't read spaces                                    ║
║  4. How to read strings with spaces and newlines                             ║
║  5. Important string functions                                               ║
║  6. Character arrays vs C++ strings                                          ║
╚══════════════════════════════════════════════════════════════════════════════╝
*/

void LearnStringsBasics()
{
    cout << "══════════════════════════════════════════════════════" << endl;
    cout << "        PART 1: STRING IS AN ARRAY OF CHARACTERS     " << endl;
    cout << "══════════════════════════════════════════════════════" << endl;

    // In C++, a string is actually stored as an array of characters
    // The last character is always a NULL character '\0' (end marker)
    // This is called "null-terminated string"

    // Example: "Hello" is stored as: H e l l o \0
    //                                0 1 2 3 4 5

    string s = "Hello";

    // How to access each character? Using [] just like arrays!
    cout << "String: " << s << endl;
    cout << "First character (s[0]): " << s[0] << endl;  // Output: H
    cout << "Second character (s[1]): " << s[1] << endl;  // Output: e
    cout << "Third character (s[2]): " << s[2] << endl;   // Output: l

    // We can also modify characters like an array
    s[0] = 'J';  // Now string becomes "Jello"
    cout << "After changing s[0] to 'J': " << s << endl;

    // Loop through string like an array
    cout << "All characters one by one: ";
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;

    // Get size/length of string
    cout << "Length of string: " << s.length() << endl;  // Output: 5

    cout << endl;
}


void LearnCinWithSpace()
{
    cout << "══════════════════════════════════════════════════════" << endl;
    cout << "     PART 2: WHY CIN >> STRING DOESN'T READ SPACES   " << endl;
    cout << "══════════════════════════════════════════════════════" << endl;

    // PROBLEM: cin >> only reads until it finds a whitespace (space, tab, newline)
    // It stops at the first space!

    string name1;
    cout << "Enter your full name (using cin >>): " << endl;
    // cin >> name1;  // Try input: "John Doe"
    // cout << "You entered: " << name1 << endl;
    // Output will be just "John" - it stops at space!

    // WHY DOES THIS HAPPEN?
    // The >> operator is designed to read "words", not sentences
    // It considers spaces, tabs, and newlines as word separators

    // Example of what cin >> does:
    // Input: "John Doe Smith"
    // cin >> name1  --> reads "John", stops at space
    // The " Doe Smith" is still waiting in the input buffer!

    cout << "\n--- THIS IS THE PROBLEM ---" << endl;
    cout << "cin >> reads ONLY ONE WORD, not the whole line!" << endl;
    cout << "It treats SPACE as a delimiter (separator)" << endl;

    cout << endl;
}


void LearnNewlineHandling()
{
    cout << "══════════════════════════════════════════════════════" << endl;
    cout << "           PART 3: UNDERSTANDING NEWLINES             " << endl;
    cout << "══════════════════════════════════════════════════════" << endl;

    // When you press Enter, a newline character '\n' is added to input
    // This can cause problems if not handled properly

    // PROBLEM 1: After reading with cin >>, newline stays in buffer
    // This can cause getline to read an empty string!

    string str1, str2;

    cout << "Example of newline causing empty read:" << endl;
    cout << "Enter first string: ";
    // cin >> str1;              // User types "Hello" then presses Enter
    // cin.ignore();             // This clears the newline from buffer
    // cout << "Enter second string: ";
    // getline(cin, str2);       // Without ignore(), this reads empty!

    // PROBLEM 2: Using both cin >> and getline together
    // After cin >>, the newline remains and gets read by getline

    // SOLUTION: Use cin.ignore() after cin >>

    /*
    // WRONG WAY:
    int age;
    string name;
    cin >> age;          // User enters: 25 [ENTER]
    getline(cin, name);  // PROBLEM! Reads empty string (the newline)

    // CORRECT WAY:
    int age;
    string name;
    cin >> age;
    cin.ignore();        // Clear the newline from buffer
    getline(cin, name);  // Now this works properly!
    */

    cout << "Remember: After cin >> always use cin.ignore() before getline!" << endl;

    cout << endl;
}


void LearnGetlineAndSolutions()
{
    cout << "══════════════════════════════════════════════════════" << endl;
    cout << "     PART 4: HOW TO READ STRINGS WITH SPACES         " << endl;
    cout << "══════════════════════════════════════════════════════" << endl;

    // SOLUTION 1: use getline() - reads entire line including spaces
    string fullName;

    cout << "Using getline() - it reads SPACES too!" << endl;
    cout << "Enter your full name: ";
    // getline(cin, fullName);  // Input: "John Doe"
    // cout << "You entered: " << fullName << endl;  // Output: John Doe

    // getline() keeps reading until it hits Enter (newline)
    // It DOES NOT stop at spaces - that's the difference!

    cout << "\n--- COMPARISON ---" << endl;
    cout << "cin >> str    : Stops at SPACE, TAB, or NEWLINE" << endl;
    cout << "getline()     : Reads until only NEWLINE (Enter key)" << endl;

    // SOLUTION 2: Using multiple getline() calls
    string line1, line2;
    cout << "\nMultiple lines input:" << endl;
    // cout << "Line 1: ";
    // getline(cin, line1);
    // cout << "Line 2: ";
    // getline(cin, line2);

    // SOLUTION 3: For character array input with spaces, use cin.get()
    char charArray[100];
    cout << "\nUsing cin.get() for character array with spaces:" << endl;
    // cin.get(charArray, 100);  // Reads up to 99 chars or newline
    // cout << "You entered: " << charArray << endl;

    cout << endl;
}


void LearnStringFunctions()
{
    cout << "══════════════════════════════════════════════════════" << endl;
    cout << "           PART 5: IMPORTANT STRING FUNCTIONS         " << endl;
    cout << "══════════════════════════════════════════════════════" << endl;

    string s = "Hello World";

    // 1. length() or size() - returns number of characters
    cout << "1. length() - Number of characters:" << endl;
    cout << "   s = \"" << s << "\"" << endl;
    cout << "   s.length() = " << s.length() << endl;  // 11 (space counts!)
    cout << "   s.size() = " << s.size() << endl;      // Same as length()

    // 2. substr() - extract part of string
    cout << "\n2. substr() - Extract part of string:" << endl;
    cout << "   s.substr(6) = \"" << s.substr(6) << "\" (from index 6 to end)" << endl;
    cout << "   s.substr(0, 5) = \"" << s.substr(0, 5) << "\" (5 chars from start)" << endl;
    // substr(start_position, how_many_characters)

    // 3. find() - find position of a character or substring
    cout << "\n3. find() - Find position:" << endl;
    cout << "   s.find(\"World\") = " << s.find("World") << endl;  // Returns 6
    cout << "   s.find('o') = " << s.find('o') << endl;            // Returns 4 (first 'o')
    // Returns string::npos if not found

    // 4. replace() - replace part of string
    cout << "\n4. replace() - Replace part of string:" << endl;
    string s2 = "Hello";
    s2.replace(0, 5, "Hi");  // Replace 5 chars from index 0 with "Hi"
    cout << "   After s2.replace(0, 5, \"Hi\"): \"" << s2 << "\"" << endl;

    // 5. insert() - insert string at position
    cout << "\n5. insert() - Insert characters:" << endl;
    string s3 = "Hello";
    s3.insert(2, "XYZ");  // Insert "XYZ" at index 2
    cout << "   After s3.insert(2, \"XYZ\"): \"" << s3 << "\"" << endl;

    // 6. erase() - remove characters
    cout << "\n6. erase() - Remove characters:" << endl;
    string s4 = "Hello World";
    s4.erase(5, 6);  // Remove 6 chars starting from index 5
    cout << "   After s4.erase(5, 6): \"" << s4 << "\"" << endl;

    // 7. compare() - compare two strings
    cout << "\n7. compare() - Compare strings:" << endl;
    string a = "apple", b = "apple";
    cout << "   a.compare(b) = " << a.compare(b) << endl;  // 0 if equal
    cout << "   Returns 0 if equal, negative if a<b, positive if a>b" << endl;

    // 8. append() or += - add to end of string
    cout << "\n8. append() - Add to end:" << endl;
    string s5 = "Hello";
    s5.append(" World");
    cout << "   After s5.append(\" World\"): \"" << s5 << "\"" << endl;

    // 9. push_back() - add single character to end
    cout << "\n9. push_back() - Add one character:" << endl;
    string s6 = "Hello";
    s6.push_back('!');
    cout << "   After s6.push_back('!'): \"" << s6 << "\"" << endl;

    // 10. pop_back() - remove last character
    cout << "\n10. pop_back() - Remove last character:" << endl;
    string s7 = "Hello!";
    s7.pop_back();
    cout << "   After s7.pop_back(): \"" << s7 << "\"" << endl;

    // 11. empty() - check if string is empty
    cout << "\n11. empty() - Check if empty:" << endl;
    string s8 = "";
    cout << "   \"\".empty() = " << s8.empty() << endl;  // 1 (true)

    // 12. clear() - make string empty
    cout << "\n12. clear() - Empty the string:" << endl;
    string s9 = "Hello";
    s9.clear();
    cout << "   After s9.clear(), s9.empty() = " << s9.empty() << endl;

    cout << endl;
}


void LearnCharArrayVsString()
{
    cout << "══════════════════════════════════════════════════════" << endl;
    cout << "    PART 6: CHARACTER ARRAY vs C++ STRING OBJECT      " << endl;
    cout << "══════════════════════════════════════════════════════" << endl;

    // METHOD 1: Character Array (C-style string)
    char cArr[] = "Hello";  // Size is 6 (5 chars + null terminator)

    // METHOD 2: C++ String Object (modern way)
    string cxxStr = "Hello";

    cout << "Character Array:" << endl;
    cout << "  Declaration: char cArr[] = \"Hello\";" << endl;
    cout << "  Size: " << sizeof(cArr) << " bytes (includes null \\0)" << endl;

    cout << "\nC++ String Object:" << endl;
    cout << "  Declaration: string cxxStr = \"Hello\";" << endl;
    cout << "  Length: " << cxxStr.length() << " characters" << endl;

    cout << "\n--- KEY DIFFERENCES ---" << endl;
    cout << "1. Character array needs manual size management" << endl;
    cout << "2. String object handles size automatically" << endl;
    cout << "3. String has built-in functions (length, substr, etc.)" << endl;
    cout << "4. String is safer - no buffer overflow danger" << endl;
    cout << "5. Character array can be faster in some cases" << endl;

    cout << "\n--- COMPARISON TABLE ---" << endl;
    cout << "Operation          | Char Array       | C++ String" << endl;
    cout << "-------------------|------------------|------------" << endl;
    cout << "Get length         | strlen()         | s.length()" << endl;
    cout << "Copy               | strcpy()         | s1 = s2" << endl;
    cout << "Concatenate        | strcat()         | s1 + s2" << endl;
    cout << "Compare            | strcmp()         | s1.compare(s2)" << endl;
    cout << "Read with spaces   | cin.get()        | getline()" << endl;

    cout << endl;
}


void LearnIteratingStrings()
{
    cout << "══════════════════════════════════════════════════════" << endl;
    cout << "        PART 7: DIFFERENT WAYS TO ITERATE STRING      " << endl;
    cout << "══════════════════════════════════════════════════════" << endl;

    string s = "Hello";

    // Method 1: Using for loop with index
    cout << "Method 1: For loop with index:" << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;

    // Method 2: Using range-based for loop (C++11+)
    cout << "\nMethod 2: Range-based for loop:" << endl;
    for (char c : s)
    {
        cout << c << " ";
    }
    cout << endl;

    // Method 3: Using iterators
    cout << "\nMethod 3: Using iterators:" << endl;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Method 4: Using while loop
    cout << "\nMethod 4: While loop:" << endl;
    int i = 0;
    while (s[i] != '\0')
    {
        cout << s[i] << " ";
        i++;
    }
    cout << endl;

    cout << endl;
}


void LearnStringInputExamples()
{
    cout << "══════════════════════════════════════════════════════" << endl;
    cout << "         PART 8: PRACTICAL INPUT EXAMPLES             " << endl;
    cout << "══════════════════════════════════════════════════════" << endl;

    // Example 1: Reading a single word
    cout << "Example 1: Single word (no spaces)" << endl;
    cout << "  Use: cin >> word" << endl;
    cout << "  Input: Hello" << endl;
    cout << "  Output: Hello" << endl;
    cout << "  Input: Hello World" << endl;
    cout << "  Output: Hello (stops at space!)" << endl;

    // Example 2: Reading a full line with spaces
    cout << "\nExample 2: Full line with spaces" << endl;
    cout << "  Use: getline(cin, str)" << endl;
    cout << "  Input: Hello World" << endl;
    cout << "  Output: Hello World" << endl;

    // Example 3: Reading multiple values (mix of types)
    cout << "\nExample 3: Mix of cin >> and getline()" << endl;
    /*
    int age;
    string name, city;

    cin >> age;              // Reads: 25
    cin.ignore();            // IMPORTANT: Clear newline!
    getline(cin, name);      // Reads: John Doe
    getline(cin, city);      // Reads: New York

    // If you forget cin.ignore(), name will be empty!
    */

    cout << "  Remember: After cin >> always use cin.ignore()!" << endl;

    // Example 4: Reading character array with spaces
    cout << "\nExample 4: Character array with spaces" << endl;
    cout << "  Use: cin.get(charArray, size)" << endl;
    /*
    char msg[100];
    cin.get(msg, 100);  // Reads up to 99 chars
    */

    // Example 5: Reading until specific character
    cout << "\nExample 5: Read until specific character" << endl;
    cout << "  Use: cin.getline(charArray, size, delimiter)" << endl;
    /*
    char line[100];
    cin.getline(line, 100, ',');  // Stop at comma
    */

    cout << endl;
}


void QuickReference()
{
    cout << "══════════════════════════════════════════════════════" << endl;
    cout << "                    QUICK REFERENCE                    " << endl;
    cout << "══════════════════════════════════════════════════════" << endl;

    cout << R"(
┌─────────────────────────────────────────────────────────────────────┐
│                    STRING CHEAT SHEET                               │
├─────────────────────────────────────────────────────────────────────┤
│  DECLARATION:                                                       │
│    string s = "Hello";           // C++ string object               │
│    char cArr[] = "Hello";        // C-style char array              │
├─────────────────────────────────────────────────────────────────────┤
│  INPUT METHODS:                                                     │
│    cin >> s;                     // Reads ONE WORD (no spaces)      │
│    getline(cin, s);             // Reads FULL LINE (with spaces)    │
│    cin.get(arr, size);          // Char array with spaces           │
├─────────────────────────────────────────────────────────────────────┤
│  IMPORTANT:                                                         │
│    After cin >> x;                                                  │
│    Always use: cin.ignore(); before getline()!                      │
│    Why? Because newline stays in buffer and breaks getline()        │
├─────────────────────────────────────────────────────────────────────┤
│  COMMON FUNCTIONS:                                                  │
│    s.length() or s.size()      → Get number of characters           │
│    s[i]                         → Access character at index i       │
│    s.substr(start, count)      → Extract portion of string          │
│    s.find("word")               → Find position of substring        │
│    s.replace(pos, len, "new")  → Replace portion                    │
│    s.insert(pos, "text")       → Insert text                        │
│    s.erase(pos, len)           → Delete portion                     │
│    s.append("text") or s += "text" → Concatenate                    │
│    s.push_back('c')            → Add one character                  │
│    s.pop_back()                → Remove last character              │
│    s.empty()                   → Check if empty (returns bool)      │
│    s.clear()                   → Make string empty                  │
├─────────────────────────────────────────────────────────────────────┤
│  CHARACTER FUNCTIONS:                                               │
│    isalpha(c)                   → Is it a letter?                   │
│    isdigit(c)                   → Is it a digit?                    │
│    isspace(c)                   → Is it whitespace?                 │
│    toupper(c)                   → Convert to uppercase              │
│    tolower(c)                   → Convert to lowercase              │
├─────────────────────────────────────────────────────────────────────┤
│  KEY POINTS TO REMEMBER:                                            │
│    ✓ String is an array of characters ending with '\0'              │
│    ✓ cin >> stops at SPACE, TAB, or NEWLINE                         │
│    ✓ getline() reads until NEWLINE only                             │
│    ✓ Always clear newline buffer after cin >> before getline()      │
│    ✓ Use C++ string (string) for modern, safe code                  │
│    ✓ Character arrays are faster but less safe                      │
└─────────────────────────────────────────────────────────────────────┘
)" << endl;

    cout << endl;
    cout << "══════════════════════════════════════════════════════" << endl;
    cout << "                      EXAMPLES                           " << endl;
    cout << "══════════════════════════════════════════════════════" << endl;

    // Live examples to demonstrate
    cout << "\n--- LIVE EXAMPLES ---" << endl;

    string example = "I love C++ Programming";

    cout << "String: \"" << example << "\"" << endl;
    cout << "Length: " << example.length() << endl;
    cout << "First char: " << example[0] << endl;
    cout << "Substr(2,5): " << example.substr(2, 5) << endl;
    cout << "Find(\"C++\"): " << example.find("C++") << endl;

    string a = "Hello", b = "World";
    cout << "\nConcatenation: " << a + " " + b << endl;

    cout << "\nCompare: \"apple\" vs \"banana\"" << endl;
    cout << "\"apple\".compare(\"banana\") = " << string("apple").compare("banana") << " (negative means apple < banana)" << endl;
}


// ════════════════════════════════════════════════════════════════════════════
//                              MAIN FUNCTION
// ════════════════════════════════════════════════════════════════════════════
void Solve()
{
    // Uncomment the examples below to test them!

    // ─────────────────────────────────────────────────────────────
    // TEST PART 1: String is array of characters
    // ─────────────────────────────────────────────────────────────
    LearnStringsBasics();


    // ─────────────────────────────────────────────────────────────
    // TEST PART 2: Why cin >> doesn't read spaces
    // ─────────────────────────────────────────────────────────────
    LearnCinWithSpace();


    // ─────────────────────────────────────────────────────────────
    // TEST PART 3: Newline handling problems
    // ─────────────────────────────────────────────────────────────
    LearnNewlineHandling();


    // ─────────────────────────────────────────────────────────────
    // TEST PART 4: How to read strings with spaces
    // ─────────────────────────────────────────────────────────────
    LearnGetlineAndSolutions();


    // ─────────────────────────────────────────────────────────────
    // TEST PART 5: Important string functions
    // ─────────────────────────────────────────────────────────────
    LearnStringFunctions();


    // ─────────────────────────────────────────────────────────────
    // TEST PART 6: Char array vs C++ string
    // ─────────────────────────────────────────────────────────────
    LearnCharArrayVsString();


    // ─────────────────────────────────────────────────────────────
    // TEST PART 7: Different ways to iterate
    // ─────────────────────────────────────────────────────────────
    LearnIteratingStrings();


    // ─────────────────────────────────────────────────────────────
    // TEST PART 8: Practical input examples
    // ─────────────────────────────────────────────────────────────
    LearnStringInputExamples();


    // ─────────────────────────────────────────────────────────────
    // QUICK REFERENCE
    // ─────────────────────────────────────────────────────────────
    QuickReference();


    // ═══════════════════════════════════════════════════════════
    // EXERCISE FOR YOU: Try these at home!
    // ═══════════════════════════════════════════════════════════
    cout << "\n══════════════════════════════════════════════════════" << endl;
    cout << "                    EXERCISES                           " << endl;
    cout << "══════════════════════════════════════════════════════" << endl;
    cout << R"(
Try these to practice:

1. Write a program to reverse a string
2. Count vowels and consonants in a string
3. Check if string is palindrome
4. Convert string to uppercase/lowercase
5. Find frequency of each character
6. Remove duplicate characters from string
7. Find first and last occurrence of a character
8. Replace all spaces with underscores
9. Split a sentence into words
10. Compare two strings (case-insensitive)
)" << endl;
}


// Driver code
int main() {
#ifdef _WIN32
    // Set console output codepage to UTF-8 for printing special box-drawing characters correctly
    SetConsoleOutputCP(CP_UTF8);
#endif
    fastio();

    // Uncomment to test interactive input:
    /*
    string name;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Hello, " << name << "!" << endl;
    */

    Solve();
    return 0;
}