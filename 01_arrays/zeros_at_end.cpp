#include <bits/stdc++.h>
using namespace std;

// Problem: [Name and link]
// Time: O(?)
// Space: O(?)

class Solution {
   public:
    void zerosAtEnd(vector<int>& arr) {
        int len = arr.size();
        if (len < 2)
            return;
        int write = 0;
        for (int i = 0; i < len; i++) {
            if (arr[i] != 0) {
                arr[write] = arr[i];
                write++;
            }
        }
        for (int j = write; j < len; j++) {
            arr[j] = 0;
        }
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

    vector<int> a1 = {1, 0, 2, 3, 0, 4, 0, 1};
    s.zerosAtEnd(a1);
    cout << "Test 1: ";
    print(a1);

    vector<int> a2 = {1, 2, 0, 1, 0, 4, 0};
    s.zerosAtEnd(a2);
    cout << "Test 2: ";
    print(a2);

    vector<int> a3 = {1, 2, 0, 0, 0, 4, 0};
    s.zerosAtEnd(a3);
    cout << "Test 3: ";
    print(a3);

    vector<int> a4 = {0, 0, 3};
    s.zerosAtEnd(a4);
    cout << "Test 4: ";
    print(a4);

    return 0;
}