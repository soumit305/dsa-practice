#include <bits/stdc++.h>
using namespace std;

vector<int> nearestSmallerElement(vector<int>& nums) {
    vector<int> ans;
    stack<int> st;
    for (int i = nums.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= nums[i])
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
    vector<int> nums = {4, 8, 5, 2, 25};
    vector<int> nums2 = {10, 9, 8, 7};
    vector<int> ans = nearestSmallerElement(nums);
    vector<int> ans2 = nearestSmallerElement(nums2);
    for (int i : ans) {
        cout << i << ' ';
    }
    cout << endl;
    for (int i : ans2) {
        cout << i << ' ';
    }
    return 0;
}