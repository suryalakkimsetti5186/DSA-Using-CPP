#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
STRATEGY USED:
Backtracking + Include/Exclude (Decision Tree)

At each index, we have 2 choices:
1. Exclude the character
2. Include the character

This forms a recursion tree of size 2^n.

Time Complexity: O(n * 2^n)
Space Complexity: O(n) (recursion stack)

===========================================================
EXAMPLE:

Input:
s = "abc"

Output:
"a"
"ab"
"abc"
"ac"
"b"
"bc"
"c"

(Empty string "" is skipped)

===========================================================
*/

class Solution {
public:
    void helper(string &s, int index, string &current, vector<string> &result) {
        
        // Base case
        if (index == s.size()) {
            if(current != "") // skip empty subsequence
                result.push_back(current);
            return;
        }

        // Choice 1: Exclude current character
        helper(s, index + 1, current, result);

        // Choice 2: Include current character
        current.push_back(s[index]);
        helper(s, index + 1, current, result);

        // Backtrack (undo the inclusion)
        current.pop_back();
    }

    vector<string> getSubsequences(string s) {
        vector<string> result;
        string current = "";
        helper(s, 0, current, result);
        return result;
    }
};

int main() {
    string s = "abc";
    Solution sol;

    vector<string> subsequences = sol.getSubsequences(s);

    // Sort for lexicographical order (optional)
    sort(subsequences.begin(), subsequences.end());

    cout << "Subsequences:\n";
    for (auto &subseq : subsequences) {
        cout << "\"" << subseq << "\"" << endl;
    }

    return 0;
}  