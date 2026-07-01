#include <bits/stdc++.h>
using namespace std;

// All numbers except two distinct numbers are present in pairs
// Return a list of those two numbers in any order

vector<int> singleNumber(vector<int>& nums) {
    long xorSum = 0;
    for (int num : nums) {
        xorSum = xorSum ^ num;
    }
    int rightMostSet = (xorSum & (xorSum - 1)) ^ xorSum;
    int b1 = 0;
    int b2 = 0;
    for (int num : nums) {
        if (rightMostSet & num)
            b1 = b1 ^ num;
        else
            b2 = b2 ^ num;
    }
    return {b1, b2};
}

int main() {
    vector<int> arr1 = {1, 2, 1, 3, 5, 2};
    vector<int> arr2 = {-1, 0};
    for (int x : singleNumber(arr1)) {
        cout << x << ' ';
    }
    cout << endl;
    for (int x : singleNumber(arr2)) {
        cout << x << ' ';
    }
    return 0;
}