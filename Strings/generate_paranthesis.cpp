#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
void backtrack(vector<string>& v,string s,int n,int f,int k){
   if(s.size()==2*n){
    v.push_back(s);
    return;
   }
    if(f<n){
        backtrack(v,s+'(',n,f+1,k);
    }
    if(k<f) backtrack(v,s+')',n,f,k+1);
}

vector<string> generateParenthesis(int n) {
       vector<string> v;
       string s="";
       backtrack(v,s,n,0,0); 
       return v;
}
};

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    Solution obj;
    vector<string> result = obj.generateParenthesis(n);

    cout << "Well-formed parentheses combinations:\n";
    for(auto &it : result){
        cout << it << endl;
    }

    return 0;
}