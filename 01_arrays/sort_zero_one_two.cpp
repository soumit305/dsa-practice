#include <bits/stdc++.h>
using namespace std;

// Problem: Sort an array of 0's, 1's and 2's
// Link: https://leetcode.com/problems/sort-colors/
// Time: O(?)
// Space: O(?)
/*
The approach :
(write your reasoning out loud here before you code)

Brute force:  ...
Better:       ...
Optimal:      ...

Hint to recognize the pattern (read only if stuck after thinking):
  You are sorting an array with exactly 3 distinct values.
  - Counting sort: count how many 0s, 1s, 2s, then overwrite the array.
    O(n) time, O(1) space, but TWO passes.
  - Can you do it in ONE pass, in place? Partition the array into regions:
        [ 0s ] [ 1s ] [ unknown ] [ 2s ]
         ^low        ^mid        ^high
    Walk `mid` forward. arr[mid]==0 -> swap into low region.
    arr[mid]==1 -> it's already home, advance mid. arr[mid]==2 -> swap into
    high region (and DON'T advance mid, because the swapped-in value is
    still unexamined). This is the Dutch National Flag algorithm.
*/

class Solution {
   public:
    void sortZeroOneTwo(vector<int>& arr) {
        int low = 0, mid = 0, high = arr.size() - 1;
        while (mid <= high) {
            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            } else if (arr[mid] == 1) {
                mid++;
            } else {
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};

int main() {
    // test cases
    Solution s;

    auto printArr = [](vector<int>& v) {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    };

    vector<int> a1 = {2, 0, 2, 1, 1, 0};
    s.sortZeroOneTwo(a1);
    cout << "Test 1 (expect 0 0 1 1 2 2):     ";
    printArr(a1);

    vector<int> a2 = {2, 0, 1};
    s.sortZeroOneTwo(a2);
    cout << "Test 2 (expect 0 1 2):           ";
    printArr(a2);

    vector<int> a3 = {0};
    s.sortZeroOneTwo(a3);
    cout << "Test 3 (expect 0):               ";
    printArr(a3);

    vector<int> a4 = {2, 2, 2};
    s.sortZeroOneTwo(a4);
    cout << "Test 4 (expect 2 2 2):           ";
    printArr(a4);

    vector<int> a5 = {1, 0, 0, 1, 2, 1, 0, 2};
    s.sortZeroOneTwo(a5);
    cout << "Test 5 (expect 0 0 0 1 1 1 2 2): ";
    printArr(a5);

    vector<int> a6 = {};
    s.sortZeroOneTwo(a6);
    cout << "Test 6 (expect empty):           ";
    printArr(a6);

    vector<int> a7 = {2, 0};
    s.sortZeroOneTwo(a7);
    cout << "Test 7 (expect 0 2):             ";
    printArr(a7);

    return 0;
}