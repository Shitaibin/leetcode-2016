/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree_recursive(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* new_left = invertTree(root->right);
        root->right = invertTree(root->left);
        root->left = new_left;
        return root;
    }

    TreeNode* invertTree_non_recursive(TreeNode* root) {
        if (!root) return NULL;
        vector<TreeNode*> s;
        s.push_back(root);
        while (s.size()) {
            TreeNode* node = s.back();
            s.pop_back();
            swap(node->left, node->right);
            if (node->left) s.push_back(node->left);
            if (node->right) s.push_back(node->right);
        }
        return root;
    }

    TreeNode* invertTree_recursive(TreeNode* root) {
        if (rand() % 2)
        	return invertTree_recursive(root);
        return invertTree_non_recursive(root);
    }
};

