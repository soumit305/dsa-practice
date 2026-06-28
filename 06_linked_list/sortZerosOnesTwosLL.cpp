#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int val;
    Node* next;

    Node() {
        val = 0;
        next = nullptr;
    }

    Node(int val1, Node* next1) {
        val = val1;
        next = next1;
    }

    Node(int val1) {
        val = val1;
        next = nullptr;
    }
};

Node* convertArrayToLL(vector<int> arr) {
    if (arr.size() == 0)
        return nullptr;
    Node* head = new Node(arr[0]);
    Node* it = head;
    for (int i = 1; i < arr.size(); i++) {
        it->next = new Node(arr[i]);
        it = it->next;
    }
    return head;
}

void printLL(Node* head) {
    Node* it = head;
    while (it) {
        cout << it->val << ' ';
        it = it->next;
    }
    cout << endl;
}

Node* sortZerosOnesTwosLL(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zeroit = zeroHead;
    Node* oneit = oneHead;
    Node* twoit = twoHead;
    Node* it = head;
    while (it) {
        if (it->val == 0) {
            zeroit->next = it;
            zeroit = zeroit->next;
        } else if (it->val == 1) {
            oneit->next = it;
            oneit = oneit->next;
        }
        if (it->val == 2) {
            twoit->next = it;
            twoit = twoit->next;
        }
        it = it->next;
    }
    zeroit->next = (oneHead->next) ? oneHead->next : twoHead->next;
    oneit->next = twoHead->next;
    twoit->next = nullptr;
    return zeroHead->next;
}

int main() {
    vector<int> arr1 = {1, 2, 0, 1, 0, 2};
    Node* head1 = convertArrayToLL(arr1);
    head1 = sortZerosOnesTwosLL(head1);
    printLL(head1);
    cout << endl;
    vector<int> arr2 = {2, 1, 2, 0, 0, 1};
    Node* head2 = convertArrayToLL(arr2);
    head2 = sortZerosOnesTwosLL(head2);
    printLL(head2);
    return 0;
}