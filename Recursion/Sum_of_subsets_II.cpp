#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /*
     * STRATEGY:
     * Backtracking + Pruning
     *
     * 1. Sort the array so duplicates are adjacent.
     * 2. Use recursion to generate subsets.
     * 3. Skip duplicates at the same recursion level using:
     *    (j > index && nums[j] == nums[j-1])
     * 4. Backtrack after each recursive call.
     */

    void backtrack(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums, int index) {
        result.push_back(temp);

        for (int j = index; j < nums.size(); j++) {

            // 🔥 Skip duplicates at same recursion level
            if (j > index && nums[j] == nums[j - 1]) continue;

            temp.push_back(nums[j]);                 // choose
            backtrack(result, temp, nums, j + 1);    // explore
            temp.pop_back();                         // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // important
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(result, temp, nums, 0);
        return result;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = obj.subsetsWithDup(nums);

    cout << "Subsets:\n";
    for (auto subset : result) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}

/*
EXPECTED OUTPUT:
Subsets:
[ ]
[ 1 ]
[ 1 2 ]
[ 1 2 2 ]
[ 2 ]
[ 2 2 ]
*/

/*
GIT COMMIT MESSAGE:
Implement unique subsets using backtracking with duplicate pruning in C++
*/