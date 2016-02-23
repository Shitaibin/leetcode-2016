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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalancedUtil(root, height);
    }
    bool isBalancedUtil(TreeNode *root, int &height) {
        if (root == NULL) {
            height = 0;
            return true;
        }
        int hl = 0, hr = 0;
        bool isLeft = isBalancedUtil(root->left, hl);
        bool isRight = isBalancedUtil(root->right, hr);
        height = max(hl, hr) + 1;
        return (abs(hl-hr)<2 && isLeft && isRight);
    }
};