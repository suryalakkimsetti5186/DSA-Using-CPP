#include <bits/stdc++.h>
using namespace std;

bool comparePairs(const pair<char,int> &a, const pair<char,int> &b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for (char c : s) mp[c]++;

        vector<pair<char,int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), comparePairs);

        string as = "";
        for (auto &it : v) {
            string k(it.second, it.first);
            as += k;
        }
        return as;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    string result = obj.frequencySort(s);

    cout << "Sorted by frequency: " << result << endl;

    return 0;
}