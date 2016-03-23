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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        
        TreeNode *pre = NULL, *cur = root;
        
        stack<TreeNode*> s;
        while (cur || s.size()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            if (cur->right && pre != cur->right) {
                // if right has been visited
                // pre must be the right child
                cur = cur->right;
            } else {
                v.push_back(cur->val);
                pre = cur;
                s.pop();
                cur = NULL;
            }
        }
        
        return v;
    }
};