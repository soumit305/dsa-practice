#include <bits/stdc++.h>
using namespace std;

// Problem: Left Rotate Array by One
// https://takeuforward.org/data-structure/left-rotate-the-array-by-one/
// Approach: Save first element, shift all others left by one, place saved at end.
// Time: O(n), Space: O(1)

class Solution {
public:
    void rotateLeft(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return;
        
        int first = arr[0];
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = first;
    }
};

int main() {
    Solution s;
    
    auto print = [](const vector<int>& arr) {
        cout << "[";
        for (int i = 0; i < (int)arr.size(); i++) {
            cout << arr[i] << (i == (int)arr.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    };
    
    vector<int> a1 = {1, 2, 3, 4, 5};
    s.rotateLeft(a1);
    cout << "Test 1 (normal): "; print(a1);  // [2, 3, 4, 5, 1]
    
    vector<int> a2 = {1};
    s.rotateLeft(a2);
    cout << "Test 2 (single): "; print(a2);  // [1]
    
    vector<int> a3 = {};
    s.rotateLeft(a3);
    cout << "Test 3 (empty): "; print(a3);   // []
    
    vector<int> a4 = {1, 2};
    s.rotateLeft(a4);
    cout << "Test 4 (two): "; print(a4);     // [2, 1]
    
    vector<int> a5 = {5, 5, 5};
    s.rotateLeft(a5);
    cout << "Test 5 (all same): "; print(a5);// [5, 5, 5]
    
    return 0;
}