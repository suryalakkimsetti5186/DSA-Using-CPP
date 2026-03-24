#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int size = n * m, mod = 12345;

        vector<long long> prefix(size,1), suffix(size,1), v;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                v.push_back(grid[i][j]);
            }
        }

        for(int i = 1; i < size; i++)
            prefix[i] = (prefix[i-1] * v[i-1]) % mod;

        for(int i = size-2; i >= 0; i--)
            suffix[i] = (suffix[i+1] * v[i+1]) % mod;

        int index = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                grid[i][j] = (prefix[index] * suffix[index]) % mod;
                index++;
            }
        }

        return grid;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 2},
        {3, 4}
    };

    Solution obj;
    vector<vector<int>> result = obj.constructProductMatrix(grid);

    cout << "Result Matrix:\n";
    for(auto &row : result){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}