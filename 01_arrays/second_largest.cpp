#include <bits/stdc++.h>
using namespace std;

// Problem: [Name and link]
// Time: O(?)
// Space: O(?)
/*
The approach : 
Brute force would be to just sort and return second last element. Works but not optimal
What else can we do to complete this in one passing
One way would be to let's say find the max using the code we know and then pick a number smaller than that,
if there is no number smaller than that then to we can return saying no second largest
if there is then thats the ans
to do it in one passing I think we can use another variable
what we can do is the following 
we can have maxval2 variable so that it is bigger than any number apart from maxval
that will make it the second largest
now if we find out that maxval2 is min int (which we set as default) we can say there is no second largest number 
else we can return it
*/

class Solution {
public:
    int secondLargestElement(vector<int>& arr){
        int maxVal = INT32_MIN;
        int maxVal2 = INT32_MIN;
        for (int i : arr){
            if (i > maxVal){
                maxVal2 = maxVal;
                maxVal = i;
            } else if (i<maxVal && i>maxVal2)
            {
                maxVal2 = i;
            }
            
        }
        return maxVal2;
    }
};

int main() {
    // test cases
    Solution s;

    vector<int> a1 = {3, 7, 2, 9, 5};
    cout << "Test 1: " << s.secondLargestElement(a1) << endl;

    vector<int> a2 = {5, 5, 5, 2, 1};
    cout << "Test 2: " << s.secondLargestElement(a2) << endl;

    vector<int> a3 = {10, 20};
    cout << "Test 3: " << s.secondLargestElement(a3) << endl;
    
    vector<int> a4 = {7, 7, 7};
    cout << "Test 4: " << s.secondLargestElement(a4) << endl;

    return 0;
}