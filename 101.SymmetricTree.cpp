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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isSame(root->left, root->right);
    }
    bool isSame(TreeNode *p, TreeNode *q) {
        if (p == q) 
            return true;
        if (!(p && q))
            return false;
        if (p->val == q->val)
            return isSame(p->left, q->right) && isSame(p->right, q->left);
        return false;
    }
};