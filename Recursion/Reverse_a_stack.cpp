#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(stack<int> &st, int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int b = st.top();
        st.pop();
        helper(st, x);
        st.push(b);
    }

    void reverseStack(stack<int> &st) {
        if(st.empty()) return;

        int x = st.top();
        st.pop();

        reverseStack(st);
        helper(st, x);
    }
};

int main() {
    stack<int> st;

    // Input stack (push elements)
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    Solution obj;
    obj.reverseStack(st);

    // Print reversed stack
    cout << "Reversed Stack:\n";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}