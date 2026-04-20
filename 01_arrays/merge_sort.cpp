#include <bits/stdc++.h>
using namespace std;

// Problem: Union of Two Sorted Arrays
// https://takeuforward.org/data-structure/union-of-two-sorted-arrays/
// Approach: ?
// Time: O(?)
// Space: O(?)

class Solution {
   public:
    vector<int> unionSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        vector<int> ans;

        auto addIfNew = [&](int val) {
            if (ans.empty() || ans.back() != val) {
                ans.push_back(val);
            }
        };

        while (i < n && j < m) {
            if (a[i] < b[j]) {
                addIfNew(a[i]);
                i++;
            } else if (a[i] > b[j]) {
                addIfNew(b[j]);
                j++;
            } else {
                addIfNew(a[i]);
                i++;
                j++;
            }
        }

        while (i < n) {
            addIfNew(a[i]);
            i++;
        }

        while (j < m) {
            addIfNew(b[j]);
            j++;
        }

        return ans;
    }
};

int main() {
    Solution s;

    auto print = [](const vector<int>& arr) {
        int len = arr.size();
        cout << "[";
        for (int i = 0; i < len; i++) {
            cout << arr[i] << (i == len - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    };

    // Test 1: typical overlap
    vector<int> a1 = {1, 2, 3, 4, 5};
    vector<int> b1 = {2, 3, 4, 4, 5};
    cout << "Test 1: ";
    print(s.unionSortedArrays(a1, b1));  // [1, 2, 3, 4, 5]

    // Test 2: no overlap
    vector<int> a2 = {1, 3, 5};
    vector<int> b2 = {2, 4, 6};
    cout << "Test 2: ";
    print(s.unionSortedArrays(a2, b2));  // [1, 2, 3, 4, 5, 6]

    // Test 3: full overlap (identical arrays)
    vector<int> a3 = {1, 2, 3};
    vector<int> b3 = {1, 2, 3};
    cout << "Test 3: ";
    print(s.unionSortedArrays(a3, b3));  // [1, 2, 3]

    // Test 4: one array empty
    vector<int> a4 = {};
    vector<int> b4 = {1, 2, 3};
    cout << "Test 4: ";
    print(s.unionSortedArrays(a4, b4));  // [1, 2, 3]

    // Test 5: both empty
    vector<int> a5 = {};
    vector<int> b5 = {};
    cout << "Test 5: ";
    print(s.unionSortedArrays(a5, b5));  // []

    // Test 6: duplicates within one array
    vector<int> a6 = {1, 1, 1, 2, 2, 3};
    vector<int> b6 = {2, 3, 3, 4};
    cout << "Test 6: ";
    print(s.unionSortedArrays(a6, b6));  // [1, 2, 3, 4]

    // Test 7: different lengths, overlap at end
    vector<int> a7 = {1, 2};
    vector<int> b7 = {2, 3, 4, 5, 6};
    cout << "Test 7: ";
    print(s.unionSortedArrays(a7, b7));  // [1, 2, 3, 4, 5, 6]

    // Test 8: all duplicates to deduplicate
    vector<int> a8 = {1, 1, 1};
    vector<int> b8 = {1, 1};
    cout << "Test 8: ";
    print(s.unionSortedArrays(a8, b8));  // [1]

    return 0;
}