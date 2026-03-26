#include <bits/stdc++.h>
using namespace std;

/*
 * File: myAtoi.cpp
 * Author: Surya
 * Description: Implements atoi (string to integer conversion) using recursion
 *              with overflow handling similar to C/C++ atoi.
 */

class Solution {
public:
    const int MIN = -2147483648;
    const int MAX = 2147483647;

    int check(const string &s, int sign, int i, long long num) {
        if (i >= s.size() || !isdigit(s[i])) {
            return (int)(sign * num);
        }

        num = num * 10 + (s[i] - '0');

        if (sign * num < MIN) return MIN;
        if (sign * num > MAX) return MAX;

        return check(s, sign, i + 1, num);
    }

    int myAtoi(string s) {
        int sign = 1;
        int i = 0;

        // Skip spaces
        while (i < s.size() && s[i] == ' ') i++;

        // Check sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return check(s, sign, i, 0);
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    int result = obj.myAtoi(s);

    cout << "Converted Integer: " << result << endl;

    return 0;
}