// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void printName(int n) {
    if (n == 0)
        return;
    cout << "Soumit\n";
    n--;
    printName(n);
}

void printLinear(int i, int n) {
    if (i > n) {
        return;
    }
    cout << i << "\n";
    i++;
    printLinear(i, n);
}

void printReverse(int n) {
    if (n == 0) {
        return;
    }
    cout << n << "\n";
    printReverse(n - 1);
}

// Backtracking
// Print 1 -> N but can't call f(i+1,n)
void printLinearBacktrack(int i, int n) {
    if (i < 1)
        return;
    printLinearBacktrack(i - 1, n);
    cout << i << "\n";
}

// Backtracking
// Print N -> 1 but can't call f(i-1,n)
void printReverseBacktrack(int i, int n) {
    if (i > n)
        return;
    printReverseBacktrack(i + 1, n);
    cout << i << "\n";
}

// Functional Summation 1 -> N
int functionalSummation(int n) {
    if (n == 0)
        return 0;
    return n + functionalSummation(n - 1);
}
// Parametrized Summation 1 -> N
void parameterizedSummation(int sum, int n) {
    if (n == 0) {
        cout << sum << "\n";
        return;
    }
    sum = sum + n;
    parameterizedSummation(sum, n - 1);
}

// Reverse an array using recursion
void reverseArray(vector<int>& arr, int n, int l, int r) {
    if (l >= n / 2) {
        return;
    }
    swap(arr[l], arr[r]);
    l++;
    r--;
    reverseArray(arr, n, l, r);
}

bool checkPalindrome(string s, int l, int r) {
    if (l >= s.size() / 2)
        return true;
    if (s[l] != s[r])
        return false;
    return checkPalindrome(s, l + 1, r - 1);
}

int fibonacciNumber(int n) {
    if (n <= 1)
        return n;
    return fibonacciNumber(n - 1) + fibonacciNumber(n - 2);
}

int main() {
    int n = 5;
    printName(n);
    printLinear(1, n);
    printReverse(n);
    // New Examples for Backtracking
    int x = 3;
    cout << "Backtracking 1 \n";
    printLinearBacktrack(x, x);
    cout << "Backtracking 2 \n";
    printReverseBacktrack(1, x);
    cout << "Functional Summation\n";
    cout << functionalSummation(x + 1) << "\n";
    cout << "Parameterized Summation\n";
    parameterizedSummation(0, x);
    cout << "Reverse an Array using Recursion\n";
    vector<int> arr = {10, 20, 30, 40, 50, 60};
    reverseArray(arr, arr.size(), 0, arr.size() - 1);
    for (const auto& element : arr) {
        cout << element << " ";
    }
    cout << "\n";
    cout << "Check if String is Palindrome using Recursion\n";
    string s = "racecar";
    cout << checkPalindrome(s, 0, s.size() - 1) << "\n";
    cout << "Fibonacci Number \n";
    cout << fibonacciNumber(3);
    return 0;
}