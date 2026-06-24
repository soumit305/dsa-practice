#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> arr, int idx, int sum, vector<int>& ans) {
    if (idx == arr.size()) {
        ans.push_back(sum);
        return;
    }
    helper(arr, idx + 1, sum, ans);
    helper(arr, idx + 1, sum + arr[idx], ans);
}

vector<int> sumSubsets(vector<int> arr) {
    vector<int> ans;
    int sum = 0;
    int idx = 0;
    helper(arr, idx, sum, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> arr1 = {5, 2, 1};
    vector<int> arr2 = {3, 1, 2};
    vector<int> ans1 = sumSubsets(arr1);
    vector<int> ans2 = sumSubsets(arr2);
    for (int i : ans1)
        cout << i << ' ';
    cout << endl;
    for (int i : ans2)
        cout << i << ' ';
    return 0;
}