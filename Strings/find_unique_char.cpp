#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;

        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;

        for(int i = 0; i < s.size(); i++) {
            if(mp[s[i]] == 1)
                return i;
        }

        return -1;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    int index = obj.firstUniqChar(s);

    cout << "First unique character index: " << index << endl;

    return 0;
}