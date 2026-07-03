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

bool isLeaf(TreeNode* root) {
    return !root->left && !root->right;
}

void leftBoundary(TreeNode* root, vector<int>& ans) {
    TreeNode* curr = root->left;
    while (curr) {
        if (!isLeaf(curr))
            ans.push_back(curr->val);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void leafBoundary(TreeNode* root, vector<int>& ans) {
    if (isLeaf(root)) {
        ans.push_back(root->val);
        return;
    }
    if (root->left)
        leafBoundary(root->left, ans);
    if (root->right)
        leafBoundary(root->right, ans);
}

void rightBoundary(TreeNode* root, vector<int>& ans) {
    TreeNode* curr = root->right;
    vector<int> temp;
    while (curr) {
        if (!isLeaf(curr))
            temp.push_back(curr->val);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--) {
        ans.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> ans;
    if (!root)
        return ans;
    if (!isLeaf(root))
        ans.push_back(root->val);
    leftBoundary(root, ans);
    leafBoundary(root, ans);
    rightBoundary(root, ans);
    return ans;
}

int main() {
    vector<int> arr = {1,  2,  7, 3, -1, -1, 8,  -1, 4,  -1, -1, -1, -1, 9, -1,
                       -1, -1, 5, 6, -1, -1, -1, -1, -1, -1, -1, -1, 10, 11};
    TreeNode* root = convertArrayToTree(arr);
    vector<int> res = boundaryTraversal(root);
    for (int x : res) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}