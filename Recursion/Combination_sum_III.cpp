#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * STRATEGY:
     * Backtracking + Pruning
     * - Use numbers from 1 to 9
     * - Each number used once (move forward with index)
     * - Stop recursion if sum > n or size > k
     */

    void backtrack(vector<vector<int>>& res, vector<int>& v, int k, int n, int sum, int j) {
        // 
        if (v.size() > k || sum > n) return;

        // 
        if (v.size() == k && sum == n) {
            res.push_back(v);
            return;
        }

        for (int i = j; i < 9; i++) {
            v.push_back(i + 1);                         // choose
            backtrack(res, v, k, n, sum + i + 1, i + 1); // explore
            v.pop_back();                               // backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> v;
        backtrack(res, v, k, n, 0, 0);
        return res;
    }
};

// 🔹 MAIN FUNCTION
int main() {
    Solution obj;

    int k = 3, n = 9;

    vector<vector<int>> result = obj.combinationSum3(k, n);

    cout << "Combinations:\n";
    for (auto &subset : result) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}

/*
EXPECTED OUTPUT:
Combinations:
[ 1 2 6 ]
[ 1 3 5 ]
[ 2 3 4 ]
*/

/*
PATTERN USED:
Backtracking with pruning
*/

/*
GIT COMMIT MESSAGE:
Add Combination Sum III using backtracking with pruning (C++)
*/