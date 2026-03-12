#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string sum = "";

        while (i >= 0 || j >= 0 || carry) {
            int d1 = (i >= 0) ? num1[i] - '0' : 0;
            int d2 = (j >= 0) ? num2[j] - '0' : 0;

            int total = d1 + d2 + carry;
            carry = total / 10;

            sum.push_back('0' + (total % 10));

            i--;
            j--;
        }

        reverse(sum.begin(), sum.end());
        return sum;
    }
};

int main() {
    Solution obj;

    string num1, num2;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    string result = obj.addStrings(num1, num2);

    cout << "Sum: " << result << endl;

    return 0;
}