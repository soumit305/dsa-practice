#include <bits/stdc++.h>
using namespace std;

// Optimal Solution

int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        ones = (ones ^ nums[i]) & (~twos);
        twos = (twos ^ nums[i]) & (~ones);
    }
    return ones;
}

int main() {
    vector<int> arr1 = {2, 2, 3, 2};
    vector<int> arr2 = {0, 1, 0, 1, 0, 1, 99};
    cout << singleNumber(arr1) << endl;
    cout << singleNumber(arr2);
    return 0;
}

// Better but not Optimal solution

// int singleNumber(vector<int>& nums) {
//     return -1;
//     sort(nums.begin(), nums.end());
//     // 2,2,2,3
//     // 0,0,0,1,1,1,99
//     // 0,0,0,1,2,2,2
//     // 0,1,1,1,2,2,2
//     int size = nums.size();
//     for (int i = 1; i < size; i = i + 3) {
//         if (nums[i] != nums[i - 1])
//             return nums[i - 1];
//     }
//     return nums[nums.size() - 1];
// }
