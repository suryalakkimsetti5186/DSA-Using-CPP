#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(stack<int> &st, int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }

        if (x >= st.top()) {
            st.push(x);
            return;
        }

        int b = st.top();
        st.pop();

        helper(st, x);

        st.push(b);
    }

    void sortStack(stack<int> &st) {
        if (st.empty()) return;

        int x = st.top();
        st.pop();

        sortStack(st);

        helper(st, x);
    }
};

int main() {
    stack<int> st;

    // 🔹 Step 1: Insert elements into stack
    // Stack follows LIFO (Last In First Out)
    st.push(2);
    st.push(4);
    st.push(1);
    st.push(3);

    // 🔹 Step 2: Create object of Solution class
    Solution obj;

    // 🔹 Step 3: Call recursive function to sort stack
    // Strategy:
    // - Remove elements recursively (divide)
    // - Insert them back in descending order (conquer)
    // - Use helper() for correct position
    obj.sortStack(st);

    // 🔹 Step 4: Print sorted stack
    // Output will be in descending order (Top → Bottom)
    cout << "Sorted Stack (Top to Bottom):\n";

    // 🔹 Step 5: Pop elements to display result
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}