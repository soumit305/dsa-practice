#include <bits/stdc++.h>
using namespace std;

int squareRootBinarySearch(int n) {
    int l = 0, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (mid * mid <= n) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

int main() {
    cout << squareRootBinarySearch(17);
    return 0;
}