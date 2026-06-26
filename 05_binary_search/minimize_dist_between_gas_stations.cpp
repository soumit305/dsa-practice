#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(long double dist, vector<int>& arr) {
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++) {
        int numberInBetween = (arr[i] - arr[i - 1]) / dist;
        if ((arr[i] - arr[i - 1]) / dist == numberInBetween * dist) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int>& arr, int k) {
    int n = arr.size();
    long double low = 0;
    long double high = 0;
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)arr[i + 1] - arr[i]);
    }
    long double diff = 1e-6;
    while (high - low > diff) {
        long double mid = (high + low) / (2.0);
        int count = numberOfGasStationsRequired(mid, arr);
        if (count > k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << minimiseMaxDistance(arr1, 4);
    cout << endl;
    cout << minimiseMaxDistance(arr2, 1);
    return 0;
}