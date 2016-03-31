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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        
        vector<TreeNode*> cur_level;
        cur_level.push_back(root);
        
        while (cur_level.empty() == false) {
            vector<TreeNode*> next_level;
            result.push_back(cur_level.back()->val);
            
            for (int i = 0; i < cur_level.size(); i++) {
                TreeNode *t = cur_level[i];
                if (t->left) {
                    next_level.push_back(t->left);
                }
                if (t->right) {
                    next_level.push_back(t->right);
                }
            }
            cur_level = next_level;
        }
        
        return result;
    }
};