#include <bits/stdc++.h>
using namespace std;

// Problem: Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//
// First attempt: tracked max — worked because array is sorted, but didn't
// generalize. Replaced with canonical two-pointer below.
//
// Final approach: Two pointers — slow (write) and fast (read).
// Invariant: arr[0..write] contains unique elements seen so far.
// When read finds something new, advance write and copy.
//
// Time: O(n), Space: O(1)

class Solution
{
public:
    // function signature here
    int removeDuplicates(vector<int> &arr)
    {
        int len = arr.size();
        if (len < 2)
            return len;
        int write = 0;
        for (int read : arr)
        {
            if (read != arr[write])
            {
                write++;
                arr[write] = read;
            }
        }
        return write + 1;
    }
};

int main()
{
    // test cases
    Solution s;

    vector<int> a1 = {1, 1, 2, 2, 3, 4, 4};
    int k1 = s.removeDuplicates(a1);
    cout << "Test 1: k = " << k1 << ", arr = [";
    for (int i = 0; i < k1; i++)
    {
        cout << a1[i] << (i == k1 - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    // Expected: k = 4, arr = [1, 2, 3, 4]

    return 0;
}