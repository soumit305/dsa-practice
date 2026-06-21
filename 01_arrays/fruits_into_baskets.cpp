#include <bits/stdc++.h>
using namespace std;

int fruitsIntoBasket(vector<int>& arr, int n) {
    int maxLength = 0;
    int l = 0, r = 0;
    unordered_map<int, int> mpp;
    while (r < n) {
        mpp[arr[r]]++;
        if (mpp.size() > 2) {
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0)
                mpp.erase(arr[l]);
            l++;
        }
        maxLength = max(maxLength, r - l + 1);
        r++;
    }
    return maxLength;
}

int main() {
    vector<int> arr = {1, 2, 1};
    vector<int> arr2 = {1, 2, 3, 2, 2};
    // for (int x : arr){
    //     cout << x << ' ';
    // }
    cout << fruitsIntoBasket(arr, arr.size());
    cout << endl;
    cout << fruitsIntoBasket(arr2, arr2.size());
    // for (int x : arr2){
    //     cout << x << ' ';
    // }
    return 0;
}