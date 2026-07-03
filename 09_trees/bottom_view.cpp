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

vector<int> bottomView(TreeNode* root) {
    if (root == nullptr)
        return {};
    map<int, int> nodes;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (q.size()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto p = q.front();
            q.pop();
            int x = p.second;
            nodes[x] = p.first->val;
            if (p.first->left)
                q.push({p.first->left, x - 1});
            if (p.first->right)
                q.push({p.first->right, x + 1});
        }
    }
    vector<int> ans;
    for (auto it : nodes) {
        ans.push_back(it.second);
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 10, 9, 11, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6};
    TreeNode* root = convertArrayToTree(arr);
    vector<int> res = bottomView(root);
    for (int x : res) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}