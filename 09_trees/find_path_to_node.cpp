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

bool findPath(TreeNode* root, int target, vector<int>& ans) {
    if (root == nullptr)
        return false;
    ans.push_back(root->val);
    if (root->val == target) {
        return true;
    }
    if (findPath(root->left, target, ans) || findPath(root->right, target, ans)) {
        return true;
    }
    ans.pop_back();
    return false;
}

vector<int> rootToNodePath(TreeNode* root, int target) {
    vector<int> ans;
    findPath(root, target, ans);
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, -1, -1, 4, 5, -1, -1, -1, -1, -1, -1, 6};
    TreeNode* root = convertArrayToTree(arr);
    vector<int> res = rootToNodePath(root, 6);
    for (int x : res) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}