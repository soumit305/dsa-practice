#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumZero(vector<int> arr, int n) {
    unordered_map<int, int> mpp;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) {
            ans = max(ans, i + 1);
        }
        if (mpp.find(sum) != mpp.end()) {
            ans = max(ans, i - mpp[sum]);
        } else {
            mpp[sum] = i;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {9, -3, 3, -1, 6, -5};
    int ans = longestSubarrayWithSumZero(arr, arr.size());
    cout << ans;
    cout << endl;
    vector<int> arr2 = {6, -2, 2, -8, 1, 7, 4, -10};
    int ans2 = longestSubarrayWithSumZero(arr2, arr2.size());
    cout << ans2;
    cout << endl;
    return 0;
}