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
        vector<int> result;
        
        TreeNode *pre = NULL, *cur = root;
        stack<TreeNode*> s;
        while (cur || s.size()) {
            while (cur) {
                s.push(cur);
                cur = cur->left;
            }
            
            cur = s.top();
            if (cur->right && pre != cur->right) {
                cur = cur->right;
            } else {
                result.push_back(cur->val);
                pre = cur;
                s.pop();
                cur = NULL;
            }
        }
        return result;
    }
};