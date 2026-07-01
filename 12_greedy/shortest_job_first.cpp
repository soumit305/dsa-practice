#include <bits/stdc++.h>
using namespace std;

int shortestJobFirst(vector<int>& arr) {
    int totTime = 0;
    int totalWaitingTime = 0;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        totalWaitingTime += totTime;
        totTime += arr[i];
    }
    return totalWaitingTime / n;
}

int main() {
    vector<int> arr = {3, 1, 4, 2, 5};
    cout << shortestJobFirst(arr) << endl;
    vector<int> arr1 = {4, 3, 7, 1, 2};
    cout << shortestJobFirst(arr1) << endl;
    return 0;
}