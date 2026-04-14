#include<bits/stdc++.h>
using namespace std;

/*
Strategy:
---------
Generate all binary strings of length n with NO consecutive 1s
using backtracking.

Only check current index with previous index.
*/

bool place(vector<int>& res, int k){
    if (k > 0 && res[k] == 1 && res[k-1] == 1)
        return false;
    return true;
}

void backtrack(vector<string>& v, vector<int>& res, int n, int k){
    for(int i = 0; i < 2; i++){
        res[k] = i;

        if(place(res, k)){
            if(k == n-1){
                // Convert vector<int> to string
                string s = "";
                for(int x : res) s += char(x + '0');
                v.push_back(s);
            } else {
                backtrack(v, res, n, k+1);
            }
        }
    }
}

int main(){
    int n = 2;
    vector<string> v;
    vector<int> res(n, -1);

    backtrack(v, res, n, 0);

    cout << "Valid binary strings:\n";
    for (const string& s : v) {
        cout << s << "\n";
    }

/*Valid binary strings:
00
01
10

Total valid strings = 3 */
    cout << "\nTotal valid strings = " << v.size() << endl;
}