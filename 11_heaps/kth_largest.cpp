#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> arr, int k) {
    priority_queue<int> pq;
    for (int x : arr)
        pq.push(x);
    for (int i = 0; i < k - 1; i++) {
        pq.pop();
    }
    return pq.top();
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << kthLargest(arr, 2) << endl;
    return 0;
}