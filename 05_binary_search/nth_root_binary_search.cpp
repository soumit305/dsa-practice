#include <bits/stdc++.h>
using namespace std;

int nthRootBinarySearch(int n, int m) {
    int l = 0, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int num = pow(mid, n);
        if (num == m)
            return mid;
        else if (num < m)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    cout << nthRootBinarySearch(4, 69);
    return 0;
}