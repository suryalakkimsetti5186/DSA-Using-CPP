#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int i=0,c=0,k=0;
        while(i<s.size()){
            k=0;
            while(i<s.size() && s[i]==' ') i++;
            while(i<s.size() && s[i]!=' ') {k=1;i++;}
            c=(k==1)?c+1:c;
            while(i<s.size() && s[i]==' ') i++;
        }
        return c;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    getline(cin, s);

    cout << "Number of segments: " << obj.countSegments(s) << endl;

    return 0;
}