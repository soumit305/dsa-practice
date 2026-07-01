#include <bits/stdc++.h>
using namespace std;

// Given two integers L and R. Find the XOR of the elements in the range [L , R]

int xorRange(int num) {
    if (num % 4 == 0)
        return num;
    else if (num % 4 == 1)
        return 1;
    else if (num % 4 == 2)
        return num + 1;
    else
        return 0;
}

int main() {
    int l = 3;
    int r = 5;
    int xorInRange = xorRange(l - 1) ^ xorRange(r);
    cout << xorInRange;
    return 0;
}