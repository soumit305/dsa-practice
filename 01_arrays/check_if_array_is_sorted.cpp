#include <bits/stdc++.h>
using namespace std;

// Problem: Check if Array is Sorted (non-decreasing)
// Approach: Compare each element with previous
// Time: O(n), Space: O(1)

class Solution
{
public:
    bool checkArraySorted(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] > arr[i])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;

    vector<int> a1 = {1, 2, 3, 4, 5};
    cout << "Test 1 (sorted): " << s.checkArraySorted(a1) << endl; // 1

    vector<int> a2 = {5, 4, 6, 7, 8};
    cout << "Test 2 (unsorted): " << s.checkArraySorted(a2) << endl; // 0

    vector<int> a3 = {};
    cout << "Test 3 (empty): " << s.checkArraySorted(a3) << endl; // 1

    vector<int> a4 = {42};
    cout << "Test 4 (single): " << s.checkArraySorted(a4) << endl; // 1

    vector<int> a5 = {3, 3, 3, 3};
    cout << "Test 5 (all equal): " << s.checkArraySorted(a5) << endl; // 1

    vector<int> a6 = {1, 2, 3, 5, 4};
    cout << "Test 6 (fails at end): " << s.checkArraySorted(a6) << endl; // 0

    return 0;
}