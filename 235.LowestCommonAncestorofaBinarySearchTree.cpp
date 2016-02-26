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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root){
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
                continue;
            }
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
                continue;
            }
            return root;
        }
        return NULL; // if p and q in tree, it is not necessary
    }
};