#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void reverseStack(stack<int>& st) {
        if (st.empty())
            return;
        int top = st.top();
        st.pop();
        reverseStack(st);
        insertReversed(st, top);
    }
    void insertReversed(stack<int>& st, int num) {
        if (st.empty()) {
            st.push(num);
            return;
        }
        int top = st.top();
        st.pop();
        insertReversed(st, num);
        st.push(top);
    }
};