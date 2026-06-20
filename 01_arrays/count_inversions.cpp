#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int low, int mid, int high, int prevCount) {
    int left = low;
    int right = mid + 1;
    int count = 0;
    vector<int> res;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            res.push_back(arr[left]);
            left++;
        } else {
            res.push_back(arr[right]);
            right++;
            count += mid - left + 1;
        }
    }
    while (left <= mid) {
        res.push_back(arr[left]);
        left++;
    }
    while (right <= high) {
        res.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = res[i - low];
    }
    return count + prevCount;
}

int mergeSort(vector<int>& arr, int low, int high) {
    if (low == high)
        return 0;
    int mid = (low + high) / 2;
    int temp1 = mergeSort(arr, low, mid);
    int temp2 = mergeSort(arr, mid + 1, high);
    return merge(arr, low, mid, high, temp1 + temp2);
}

int countInversions(vector<int>& arr, int n) {
    return mergeSort(arr, 0, n - 1);
}

int main() {
    cout << "Hello World";
    cout << endl;
    vector<int> arr = {5, 4, 3, 2, 1};
    cout << countInversions(arr, arr.size());
    return 0;
}