/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 抢了当前位置，再加从孙子开始抢的结果
 // 不抢当前位置，将从两个子树开始抢的结果
class Solution {
    int robber(TreeNode* node, int &l, int &r) {
        if (node == NULL) {
            return 0;
        }
        
        int ll, lr, rl, rr;
        ll = lr = rl = rr = 0;
        l = robber(node->left, ll, lr);
        r = robber(node->right, rl, rr);
        
        return max(node->val+ll+lr+rl+rr, l+r);
    }
    
public:
    int rob(TreeNode* root) {
        int l, r;
        return robber(root, l, r);
    }
};