#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) return s;

        string a[numRows];
        string as="";

        int i=0,j=0;
        bool down=true;

        while(i<s.size()){

            a[j]+=s[i];

            if(j==numRows-1) down=false;
            else if(j==0) down=true;

            if(down) j++;
            else j--;

            i++;
        }

        for(int k=0;k<numRows;k++)
            as+=a[k];

        return as;
    }
};

int main() {

    Solution obj;
    string s;
    int numRows;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter number of rows: ";
    cin >> numRows;

    string result = obj.convert(s, numRows);

    cout << "Zigzag Conversion: " << result << endl;

    return 0;
}