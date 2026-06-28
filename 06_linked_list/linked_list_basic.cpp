#include <bits/stdc++.h>
using namespace std;

// You can use struct as well but to use OOPS concepts you need to use class
class Node {
   public:
    int data;
    Node* next;

   public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

   public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* convertArraytoLL(vector<int> arr) {
    int n = arr.size();
    if (n == 0)
        return nullptr;
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node* head) {
    Node* it = head;
    while (it) {
        cout << it->data << ' ';
        it = it->next;
    }
    cout << endl;
    return;
}

bool searchLL(Node* head, int target) {
    Node* it = head;
    while (it) {
        if (it->data == target)
            return true;
        it = it->next;
    }
    return false;
}

Node* insertAtHead(Node* head, int value) {
    Node* temp = new Node(value);
    temp->next = head;
    return temp;
}

int lengthLL(Node* head) {
    Node* it = head;
    int count = 0;
    while (it) {
        count++;
        it = it->next;
    }
    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* head = convertArraytoLL(arr);
    printLL(head);
    cout << searchLL(head, 10);
    cout << endl;
    head = insertAtHead(head, 0);
    printLL(head);
    cout << lengthLL(head);
    return 0;
}