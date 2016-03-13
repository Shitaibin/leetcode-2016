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
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        TreeNode *right = root->right;
        root->right = root->left;
        root->left = NULL;
        
        // flatten left
        flatten(root->right);
        TreeNode *p = root;
        
        // add old righ to new place
        while (p->right) {
            p = p->right;
        }
        p->right = right;
        
        // flatten old right
        flatten(p->right);
    }
};