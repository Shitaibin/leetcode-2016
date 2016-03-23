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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        // if (!root) return v;
        
        stack<TreeNode*> s;
        while (root || s.size()) {
            if (root == NULL) {
                root = s.top();
                s.pop();
            }
            
            
            while (root) {
                v.push_back(root->val);
                if (root->right) {
                    s.push(root->right);
                }
                root = root->left;
            }
        }
        
        return v;
    }
};