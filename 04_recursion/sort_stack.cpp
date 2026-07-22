#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void sortStack(stack<int>& st) {
        if (st.empty())
            return;
        int top = st.top();
        st.pop();
        sortStack(st);
        insertSorted(st, top);
    }
    void insertSorted(stack<int>& st, int num) {
        if (st.empty() || num > st.top()) {
            st.push(num);
            return;
        }
        int top = st.top();
        st.pop();
        insertSorted(st, num);
        st.push(top);
    }
};