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

vector<vector<int>> preInPostTraversal(TreeNode* root) {
    // Vectors to store traversals
    vector<int> pre, in, post;

    // If the tree is empty,
    // return empty traversals
    if (root == NULL) {
        return {};
    }

    // Stack to maintain nodes
    // and their traversal state
    stack<pair<TreeNode*, int>> st;

    // Start with the root node
    // and state 1 (preorder)
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of pre
        if (it.second == 1) {
            // Store the node's data
            // in the preorder traversal
            pre.push_back(it.first->val);
            // Move to state 2
            // (inorder) for this node
            it.second = 2;
            // Push the updated state
            // back onto the stack
            st.push(it);

            // Push left child onto
            // the stack for processing
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }

        // this is a part of in
        else if (it.second == 2) {
            // Store the node's data
            // in the inorder traversal
            in.push_back(it.first->val);
            // Move to state 3
            // (postorder) for this node
            it.second = 3;
            // Push the updated state
            // back onto the stack
            st.push(it);

            // Push right child onto
            // the stack for processing
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }

        // this is part of post
        else {
            // Store the node's data
            // in the postorder traversal
            post.push_back(it.first->val);
        }
    }

    // Returning the traversals
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}

int main() {
    vector<int> arr = {4, 2, 5, 3, -1, 7, 6, -1, 9, -1, -1, 8, -1, 1};
    TreeNode* root = convertArrayToTree(arr);
    vector<vector<int>> res = preInPostTraversal(root);

    cout << "Preorder" << endl;
    for (int x : res[0]) {
        cout << x << ' ';
    }
    cout << endl;

    cout << "Inorder" << endl;
    for (int x : res[1]) {
        cout << x << ' ';
    }
    cout << endl;

    cout << "Postorder" << endl;
    for (int x : res[2]) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;
}