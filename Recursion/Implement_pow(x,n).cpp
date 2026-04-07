#include <iostream>
using namespace std;

class Solution {
public:
    double helper(double x, long long n){
        if(n==0) return 1;
        if(n==1) return x;
        if(n%2==0) return helper(x*x, n/2);
        return x * helper(x, n-1);
    }

    double myPow(double x, int n) {
        long long n1 = n;
        if(n < 0) return (1 / helper(x, -n1));
        return helper(x, n1);
    }
};

int main() {
    Solution obj;

    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;

    cout << "Enter power (n): ";
    cin >> n;

    double result = obj.myPow(x, n);

    cout << "Result: " << result << endl;

    return 0;
}