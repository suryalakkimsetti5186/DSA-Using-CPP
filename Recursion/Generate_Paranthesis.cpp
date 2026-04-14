#include<bits/stdc++.h>
using namespace std;

/*
Problem:
--------
Generate all valid combinations of n pairs of parentheses.

Strategy (Backtracking):
------------------------
We build the string step by step using two counters:
- open  → number of '(' used
- close → number of ')' used

Rules:
------
1. We can add '(' if open < n
2. We can add ')' if close < open
   (this ensures validity → no premature closing)

Base Case:
----------
If string length == 2*n → valid combination → store it

Key Idea:
---------
Always maintain:
close <= open  (valid structure)
*/

void backtrack(vector<string>& v, int n, string s, int open, int close){
    // Base case
    if(s.size() == 2*n){
        v.push_back(s);
        return;
    }

    // Add '('
    if(open < n)
        backtrack(v, n, s + '(', open + 1, close);

    // Add ')'
    if(close < open)
        backtrack(v, n, s + ')', open, close + 1);
}

int main(){
    int n = 3;
    vector<string> result;

    backtrack(result, n, "", 0, 0);

    cout << "Valid Parentheses Combinations:\n";
    for(const string& s : result){
        cout << s << "\n";
    }

    cout << "\nTotal = " << result.size() << endl;
}

/*
Example Output (n = 3):
-----------------------
((()))
(()())
(())()
()(())
()()()

Total = 5

Complexity:
-----------
Time  : O(2^n) approx, actually Catalan growth
Space : O(n) recursion stack

Note:
-----
Number of valid combinations = Catalan Number
C(n) = (1/(n+1)) * (2n choose n)
*/