#include <bits/stdc++.h>
using namespace std;

void helper(int n, string& current, int last, vector<string>& ans) {
    if (n == 0) {
        ans.push_back(current);
        return;
    }
    current.push_back('0');
    helper(n - 1, current, 0, ans);
    current.pop_back();
    if (last)
        return;
    else {
        current.push_back('1');
        helper(n - 1, current, 1, ans);
        current.pop_back();
    }
}

vector<string> func(int n) {
    vector<string> ans;
    string current;
    int last = 0;
    helper(n, current, last, ans);
    return ans;
}

int main() {
    vector<int> testcases = {3, 2, 4};
    int t = testcases.size();
    int k = 0;
    while (t--) {
        vector<string> ans = func(testcases[k]);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < testcases[k]; j++) {
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
        k++;
        cout << endl;
    }
    return 0;
}