#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Consecutive Ones
// https://takeuforward.org/arrays/count-maximum-consecutive-ones-in-the-array/
// Approach: ?
// Time: O(?)
// Space: O(?)

class Solution {
   public:
    int maxConsecutiveOnes(vector<int>& arr) {
        // your code
        int ans = 0;
        int first;
        int second = 0;
        int len = arr.size();
        int temp = 0;
        while (second < len) {
            if (arr[second] == 1) {
                temp++;
                second++;
            } else {
                second++;
                first = second;
                if (temp > ans)
                    ans = temp;
                temp = 0;
            }
        }
        if (temp > ans)
            ans = temp;
        return ans;
    }

    /*
    Better solution
    int maxConsecutiveOnes(vector<int>& arr) {
    int ans = 0, streak = 0;
    for (int x : arr) {
        if (x == 1) {
            streak++;
            ans = max(ans, streak);
        } else {
            streak = 0;
        }
    }
    return ans;
}
    */
};

int main() {
    Solution s;

    // Test 1: normal
    vector<int> a1 = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    cout << "Test 1: " << s.maxConsecutiveOnes(a1) << endl;  // 3

    // Test 2: all ones
    vector<int> a2 = {1, 1, 1, 1, 1};
    cout << "Test 2: " << s.maxConsecutiveOnes(a2) << endl;  // 5

    // Test 3: all zeros
    vector<int> a3 = {0, 0, 0, 0};
    cout << "Test 3: " << s.maxConsecutiveOnes(a3) << endl;  // 0

    // Test 4: alternating
    vector<int> a4 = {1, 0, 1, 0, 1, 0};
    cout << "Test 4: " << s.maxConsecutiveOnes(a4) << endl;  // 1

    // Test 5: empty
    vector<int> a5 = {};
    cout << "Test 5: " << s.maxConsecutiveOnes(a5) << endl;  // 0

    // Test 6: single 1
    vector<int> a6 = {1};
    cout << "Test 6: " << s.maxConsecutiveOnes(a6) << endl;  // 1

    // Test 7: single 0
    vector<int> a7 = {0};
    cout << "Test 7: " << s.maxConsecutiveOnes(a7) << endl;  // 0

    // Test 8: best streak at end
    vector<int> a8 = {1, 0, 1, 1, 1, 1};
    cout << "Test 8: " << s.maxConsecutiveOnes(a8) << endl;  // 4

    // Test 9: best streak at start
    vector<int> a9 = {1, 1, 1, 1, 0, 1};
    cout << "Test 9: " << s.maxConsecutiveOnes(a9) << endl;  // 4

    return 0;
}