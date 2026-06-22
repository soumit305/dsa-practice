#include <bits/stdc++.h>
using namespace std;

vector<int> nearestGreaterElement(vector<int>& nums) {
    vector<int> ans;
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i])
            st.pop();
        if (st.empty())
            ans.push_back(-1);
        else
            ans.push_back(st.top());
        st.push(nums[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> nums3 = {1, 3, 2, 4};
    vector<int> nums4 = {6, 8, 0, 1, 3};
    vector<int> ans3 = nearestGreaterElement(nums3);
    vector<int> ans4 = nearestGreaterElement(nums4);
    for (int i : ans3) {
        cout << i << ' ';
    }
    cout << endl;
    for (int i : ans4) {
        cout << i << ' ';
    }
    return 0;
}