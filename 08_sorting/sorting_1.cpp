// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// Selection sort is "selecting" the mininmum element is placing it at the front, then incrementing
// the front pointer Time Complexity -> O(N^2) [Best, Average, Worst]
void selectionSort(vector<int>& arr, int n) {
    int index;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
    return;
}

// Inserting the element in its correct order... take subarrays of increasing length and place the
// next element after the subarray to its correct place in the subarray... do this till the subarray
// becomes the full array Worst and Average -> O(N^2) Best -> O(N) (the condition in the while loop
// will prevent the inner loop from running)
void insertionSort(vector<int>& arr, int n) {
    int j;
    for (int i = 0; i < n; i++) {
        j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
    return;
}

// Bubble sort is pushing the maximum element to the end
// Worst and Average -> O(N^2)
// Best -> O(N) [ with the modification of counting swap in the first iteration]
void bubbleSort(vector<int>& arr, int n) {
    int didSwap = 0;
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                didSwap++;
            }
        }
        if (didSwap == 0)
            break;
    }
    return;
}

int main() {
    vector<int> arr = {1, 3, 4, 2, 5, 0, -1, 6, 10, 9, 8, 7};
    // selectionSort(arr, arr.size());
    insertionSort(arr, arr.size());
    // bubbleSort(arr, arr.size());
    for (int x : arr) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}