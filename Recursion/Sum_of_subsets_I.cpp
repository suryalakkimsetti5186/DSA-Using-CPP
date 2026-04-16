#include<bits/stdc++.h>
using namespace std;

/*
PATTERN:
Backtracking (Include / Exclude)

EXPECTED OUTPUT:
0 1 2 3 3 4 5 6

GIT COMMIT:
"Generate all subset sums using backtracking"
*/

void backtrack(vector<int>& v, vector<int>& res, int i, int sum) {
    if (i == v.size()) {
        res.push_back(sum);
        return;
    }

    // Include element
    backtrack(v, res, i + 1, sum + v[i]);

    // Exclude element
    backtrack(v, res, i + 1, sum);
}

int main() {
    vector<int> a = {3, 1, 2};
    vector<int> b;

    backtrack(a, b, 0, 0);

    sort(b.begin(), b.end());

    for (int x : b) cout << x << " ";

    return 0;
}