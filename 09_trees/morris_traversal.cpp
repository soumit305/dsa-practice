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

// Morris Inorder Traversal
// Time : O(N)
// Space : O(1)
vector<int> morrisInorderTraversal(TreeNode* root) {
    vector<int> inorder;
    TreeNode* cur = root;
    while (cur != NULL) {
        if (cur->left == NULL) {
            inorder.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode* prev = cur->left;
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}

// Morris Preorder Traversal
// Time : O(N)
// Space : O(1)
vector<int> morrisPreorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode* cur = root;
    while (cur != NULL) {
        if (cur->left == NULL) {
            preorder.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode* prev = cur->left;
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                prev->right = cur;
                preorder.push_back(cur->val);
                cur = cur->left;
            } else {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = convertArrayToTree(arr);
    vector<int> inorder = morrisInorderTraversal(root);
    for (int x : inorder) {
        cout << x << ' ';
    }
    cout << endl;
    vector<int> preorder = morrisPreorderTraversal(root);
    for (int x : preorder) {
        cout << x << ' ';
    }
    return 0;
}