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

void inorder(TreeNode* root, vector<int>& ans) {
    if (root == nullptr)
        return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

int main() {
    vector<int> arr = {4, 2, 5, 3, -1, 7, 6, -1, 9, -1, -1, 8, -1, 1};
    TreeNode* root = convertArrayToTree(arr);
    vector<int> res = inorderTraversal(root);
    for (int x : res) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}