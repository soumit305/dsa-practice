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

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root)
        return nullptr;

    if (key < root->val)
        root->left = deleteNode(root->left, key);  // target is left; re-attach result
    else if (key > root->val)
        root->right = deleteNode(root->right, key);  // target is right; re-attach result
    else {
        // found it — three cases:
        if (!root->left)
            return root->right;  // 0 or 1 child:
        if (!root->right)
            return root->left;  //   child replaces me

        TreeNode* succ = root->right;  // 2 children:
        while (succ->left)
            succ = succ->left;  //   inorder successor = min of right subtree
        root->val = succ->val;  //   copy its value up
        root->right = deleteNode(root->right, succ->val);  //   delete the successor (has ≤1 child)
    }
    return root;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = convertArrayToTree(arr);
    return 0;
}