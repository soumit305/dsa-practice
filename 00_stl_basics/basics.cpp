#include <bits/stdc++.h>
using namespace std;

void explainPair() {
    pair<int, int> p = {1, 3};
    cout << p.first << ' ' << p.second << endl;
    return;
}

void explainVector() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int>::iterator it1 = v.begin();
    vector<int>::iterator it2 = v.end();
    it2--;
    cout << *it1 << ' ' << *it2 << endl;
    // You can use auto keyword as well....
    // auto automatically assigns the datatype for you
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    cout << v.back() << endl;

    // v.erase(v.begin()); (1 in this example)
    // will erase the element the iterator is point to
    v.erase(v.begin() + 1, v.begin() + 3);
    // will erase starting from the index of first parameter to the index just before the second
    // parameter (2 & 3 in this example)
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;

    // Will insert at the position of the iterator
    v.insert(v.begin() + 1, 2);
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    v.insert(v.begin() + 2, 3);
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    v.pop_back();
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    return;
}

// List is the same as vector but you can push thinns in front also
// using push_front() and emplace_front()

// Deque is also almost exactly similar to vector and list

// Stack -> LIFO
// we only use push(), top(), pop(), empty(), size() at the most

// Queue -> FIFO
void explainQueue() {
    queue<int> q;
    q.push(1);     // {1}
    q.push(2);     // {1,2}
    q.emplace(4);  // {1,2,4}

    q.back() += 5;  // {1,2,9}
    cout << q.back() << endl;
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    return;
}

// VVV Important
void explainPriorityQueue() {
    // Maximum Heap
    priority_queue<int> pq;
    pq.push(5);      // {5}
    pq.push(2);      // {5,2}
    pq.push(8);      // {8,5,2}
    pq.emplace(10);  // {10,8,5,2}

    cout << pq.top() << endl;
    pq.pop();  // {8,5,2}
    cout << pq.top() << endl;

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(5);      // {5}
    minheap.push(2);      // {2,5}
    minheap.push(8);      // {2,5,8}
    minheap.emplace(10);  // {2,5,8,10}
    cout << minheap.top() << endl;
    minheap.pop();  // {5,8,10}
    cout << minheap.top() << endl;
}

// Set : Everything is sorted and is unique
// You know this..

// Unordered Set : Evertthing is unique but not sorted
// You know this..

// Multiset : Can store multiple occurences also...
// Rest evenrything is the same as set
// If you erase in multiset all the occurences ar removed.

// Map -> key and value pair (both can be anything)
// Key is unique
// You know this
// Unordered Map and MultiMap - Same story as Set

// Comparator ⭐️⭐️⭐️⭐️⭐️
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;
    if (p1.first > p2.first)
        return true;
    return false;
}

// Algorithms
void explainExtra() {
    vector<int> v = {1, 4, 2, 4, 6, 7, 8};

    // Sort
    // Ascending
    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    // Descending
    sort(v.begin(), v.end(), greater<int>());
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;

    // My Way - VVV Important
    // Using Comparators !! [Definition above the function]
    // Cannot define function inside a function :P
    vector<pair<int, int>> ex = {{1, 2}, {2, 1}, {4, 1}};
    // sort it according to the second element
    // if second element is same, the sort
    // it acc to the first element but in descending
    // it should become {{4,1},{2,1},{1,2}}

    cout << "Sorting using Comparator" << endl;
    sort(ex.begin(), ex.end(), comp);
    for (auto it = ex.begin(); it != ex.end(); it++) {
        cout << it->first << ' ' << it->second;
        cout << endl;
    }
    cout << endl;

    return;
}

int main() {
    explainExtra();
    return 0;
}