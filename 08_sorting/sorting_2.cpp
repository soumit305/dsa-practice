#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> res;
    int pt1 = low;
    int pt2 = mid + 1;
    int itr = 0;
    while (pt1 <= mid && pt2 <= high) {
        if (arr[pt1] <= arr[pt2]) {
            res.push_back(arr[pt1]);
            pt1++;
        } else {
            res.push_back(arr[pt2]);
            pt2++;
        }
        itr++;
    }
    while (pt1 <= mid) {
        res.push_back(arr[pt1]);
        itr++;
        pt1++;
    }
    while (pt2 <= high) {
        res.push_back(arr[pt2]);
        itr++;
        pt2++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = res[i - low];
    }
}

// Beautiful Recursive Algorithm
// Takes O(NlogN) in the Best, Worst and Average Case
// Most Optimal in Time Complexity
// Takes O(N) in Space Complexity in the merge step
void mergeSort(vector<int>& arr, int low, int high) {
    if (low == high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void recursiveBubbleSort(vector<int>& arr, int n) {
    return;
}

void recursiveInsertionSort(vector<int>& arr, int n) {
    return;
}

// Pick a Pivot and Place it in its correct place in the sorted array
// This pivot can be any element
// Smaller on the left and Larger on the right

int placePivot(vector<int>& arr, int low, int high) {
    int pivot = low;
    int left = low;
    int right = high;
    while (left < right) {
        while (arr[left] <= arr[pivot] && left < high) {
            left++;
        }
        while (arr[right] > arr[pivot] && right > low) {
            right--;
        }
        if (left < right)
            swap(arr[left], arr[right]);
    }
    swap(arr[pivot], arr[right]);
    return right;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = placePivot(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
    return;
}

int main() {
    vector<int> arr = {10, 6, 5, 8, 7, -1, 0, 2, 4, 1, 3};
    // sort(arr.begin(), arr.end());
    // mergeSort(arr,0,arr.size()-1);
    quickSort(arr, 0, arr.size() - 1);
    for (int x : arr) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}