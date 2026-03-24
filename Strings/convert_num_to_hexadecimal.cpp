#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    char push(int x){
        switch(x){
            case 10: return 'a';
            case 11: return 'b';
            case 12: return 'c';
            case 13: return 'd';
            case 14: return 'e';
            case 15: return 'f';
        }
        return '0' + x; 
    }

    string check(unsigned int x){
        int a = 0;
        string s = "";
        while(x > 0){
            a = x % 16;
            s.push_back(push(a));
            x /= 16;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string toHex(int num) {
        if(num == 0) return "0";
        string s = "";
        if(num < 0) {
            unsigned int sum = (1ULL << 32) + num;
            s = check(sum);
        } 
        else {
            s = check(num);
        }
        return s;
    }
};

int main() {
    Solution obj;

    int num;
    cout << "Enter number: ";
    cin >> num;

    cout << "Hexadecimal: " << obj.toHex(num) << endl;

    return 0;
}