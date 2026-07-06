#include <bits/stdc++.h>
using namespace std;

bool checkMinHeap(vector<int> arr) {
    int n = arr.size();
    if (n == 0 || n == 1)
        return true;
    int leftIdx;
    int rightIdx;
    for (int i = 0; i < n; i++) {
        leftIdx = 2 * i + 1;
        rightIdx = 2 * i + 2;
        if (leftIdx == n)
            break;
        if (arr[leftIdx] < arr[i])
            return false;
        if (rightIdx == n)
            break;
        if (arr[rightIdx] < arr[i])
            return false;
    }
    return true;
}

int main() {
    vector<int> arr = {10, 20, 30, 21, 23};
    cout << checkMinHeap(arr) << endl;
    return 0;
}