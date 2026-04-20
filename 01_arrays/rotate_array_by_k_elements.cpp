#include <bits/stdc++.h>
using namespace std;

// Problem: [Name and link]
// Time: O(?)
// Space: O(?)
/*
[1, 2, 3, 4, 5, 6, 7]
to
[4, 5, 6, 7, 1, 2, 3]

Steps
reverse full :
[7,6,5,4,3,2,1]
reverse first [size - k (7-3 = 4)] elements
[4,5,6,7,3,2,1]
reverse last k elemets
[4,5,6,7,1,2,3]
there we go
*/
class Solution {
   public:
    void rotateByKElements(vector<int>& arr, int k, string direction) {
        if (k == 0)
            return;
        int len = arr.size();
        k = k % len;
        reverse(arr, 0, len - 1);
        if (direction == "left") {
            reverse(arr, 0, len - k - 1);
            reverse(arr, len - k, len - 1);
        } else {
            reverse(arr, 0, k - 1);
            reverse(arr, k, len - 1);
        }
        return;
    }

    void reverse(vector<int>& arr, int first, int last) {
        int temp;
        while (first < last) {
            temp = arr[first];
            arr[first] = arr[last];
            arr[last] = temp;
            first++;
            last--;
        }
        return;
    }
    // function signature here
};

int main() {
    // test cases
    Solution s;

    auto print = [](const vector<int>& arr) {
        cout << "[";
        for (int i = 0; i < (int)arr.size(); i++) {
            cout << arr[i] << (i == (int)arr.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    };

    vector<int> a1 = {1, 2, 3, 4, 5, 6, 7};
    s.rotateByKElements(a1, 3, "left");
    cout << "Test 1: ";
    print(a1);  // [2, 3, 4, 5, 1]

    vector<int> a2 = {1, 2, 3, 4, 5};
    s.rotateByKElements(a2, 2, "left");
    cout << "Test 2: ";
    print(a2);  // [1]

    vector<int> a3 = {1, 2, 3};
    s.rotateByKElements(a3, 0, "left");
    cout << "Test 3: ";
    print(a3);  // []

    vector<int> a4 = {1, 2, 3};
    s.rotateByKElements(a4, 3, "left");
    cout << "Test 4: ";
    print(a4);  // [2, 1]

    vector<int> a5 = {1, 2, 3};
    s.rotateByKElements(a5, 7, "left");
    cout << "Test 5: ";
    print(a5);  // [5, 5, 5]
    return 0;
}