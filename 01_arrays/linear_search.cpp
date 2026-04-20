#include <bits/stdc++.h>
using namespace std;

// Problem: [Name and link]
// Time: O(?)
// Space: O(?)

class Solution {
   public:
    // function signature here
    int linearSearch(vector<int>& arr, int num) {
        int len = arr.size();
        if (len == 0)
            return -1;
        for (int i = 0; i < len; i++) {
            if (arr[i] == num) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    // test cases
    Solution s;

    vector<int> a1 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Test 1: " << s.linearSearch(a1, 3) << endl;

    vector<int> a2 = {1, 2, 3, 4, 5};
    cout << "Test 2: " << s.linearSearch(a2, 6) << endl;

    return 0;
}