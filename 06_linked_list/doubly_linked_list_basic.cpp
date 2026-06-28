#include <bits/stdc++.h>
using namespace std;

// You can use struct as well but to use OOPS concepts you need to use class
class Node {
   public:
    int data;
    Node* next;
    Node* prev;

   public:
    Node(int data1, Node* next1, Node* prev1) {
        data = data1;
        next = next1;
        prev = prev1;
    }

   public:
    Node(int data1) {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* convertArraytoDLL(vector<int> arr) {
    int n = arr.size();
    if (n == 0)
        return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

void printLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = convertArraytoDLL(arr);
    printLL(head);
    cout << head->next->next->prev->data;
    return 0;
}