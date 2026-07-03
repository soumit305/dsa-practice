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

void childSumProperty(TreeNode* root) {
    if (root == nullptr)
        return;
    int child = 0;
    if (root->left)
        child += root->left->val;
    if (root->right)
        child += root->right->val;
    if (child >= root->val)
        root->val = child;
    else {
        if (root->left)
            root->left->val = root->val;
        if (root->right)
            root->right->val = root->val;
    }
    childSumProperty(root->left);
    childSumProperty(root->right);
    int tot = 0;
    if (root->left)
        tot += root->left->val;
    if (root->right)
        tot += root->right->val;
    if (root->left || root->right)
        root->val = tot;
}

int main() {
    vector<int> arr = {1, 2, 3, -1, -1, 4, 5, -1, -1, -1, -1, -1, -1, 6};
    TreeNode* root = convertArrayToTree(arr);
    childSumProperty(root);
    cout << endl;
    return 0;
}