#include <bits/stdc++.h>
using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val1) {
        val = val1;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* build(vector<int>& arr, int i) {
    if (i >= arr.size() || arr[i] == -1)
        return nullptr;
    TreeNode* node = new TreeNode(arr[i]);
    node->left = build(arr, 2 * i + 1);
    node->right = build(arr, 2 * i + 2);
    return node;
}
TreeNode* convertArrayToTree(vector<int>& arr) {
    return build(arr, 0);
}

int findFloor(TreeNode* root, int key) {
    int floor = -1;
    while (root) {
        if (root->val == key) {
            return root->val;
        } else if (root->val > key) {
            root = root->left;
        } else {
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = convertArrayToTree(arr);
    cout << findFloor(root, 3) << endl;
    return 0;
}