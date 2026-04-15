#include<bits/stdc++.h>
using namespace std;

/*
PATTERN:
Backtracking + Include/Exclude + Target Sum

-----------------------------------------------------------
INPUT:
v = {4, 2, 10, 5, 1, 3}
target = 5

EXPECTED OUTPUT:

Input Array: 4 2 10 5 1 3 
Target Sum: 5

Valid Subsequences:
{ 4 1 }
{ 2 3 }
{ 5 }

Total Subsequences with sum 5 = 3
-----------------------------------------------------------
*/

void backtrack(vector<int>& v, vector<int>& current, int &count, int k, int i){

    // If target achieved → print subsequence
    if(k == 0){
        count++;

        cout << "{ ";
        for(int x : current) cout << x << " ";
        cout << "}" << endl;

        return;
    }

    if(i == v.size()) return;

    // Include
    if(v[i] <= k){
        current.push_back(v[i]);
        backtrack(v, current, count, k - v[i], i + 1);
        current.pop_back(); // backtrack
    }

    // Exclude
    backtrack(v, current, count, k, i + 1);
}

int main(){
    vector<int> v = {4, 2, 10, 5, 1, 3};
    int target = 5;

    vector<int> current;
    int count = 0;

    cout << "Input Array: ";
    for(int x : v) cout << x << " ";
    cout << endl;

    cout << "Target Sum: " << target << endl << endl;

    cout << "Valid Subsequences:\n";

    backtrack(v, current, count, target, 0);

    cout << "\nTotal Subsequences with sum " << target << " = " << count << endl;
}