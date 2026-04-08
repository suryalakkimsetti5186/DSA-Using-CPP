#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long MOD = 1e9 + 7;

    // Fast exponentiation (Divide & Conquer)
    long long power(long long x, long long n) {
        if (n == 0) return 1;

        long long half = power(x, n / 2);
        long long result = (half * half) % MOD;

        if (n % 2 == 1)
            result = (result * x) % MOD;

        return result;
    }

    long long countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // even indices count
        long long odd = n / 2;        // odd indices count

        long long ans = (power(5, even) * power(4, odd)) % MOD;
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countGoodNumbers(50) << endl;
}