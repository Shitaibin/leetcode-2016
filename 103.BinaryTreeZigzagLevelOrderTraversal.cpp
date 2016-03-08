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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL) return ret;
        vector<TreeNode*> cur_level;
        
        cur_level.push_back(root);
        bool flag = true;
        while (cur_level.size()) {
            vector<TreeNode*> next_level;
            vector<int> cur_val;
            for (int i = 0; i < cur_level.size(); i++) {
                TreeNode* node = cur_level[i];
                // visit this node
                cur_val.push_back(node->val);
                if (flag) {
                    if (node->left) {
                        next_level.push_back(node->left);
                    }
                    if (node->right) {
                        next_level.push_back(node->right);
                    }
                } else {
                    if (node->right) {
                        next_level.push_back(node->right);
                    }
                    if (node->left) {
                        next_level.push_back(node->left);
                    }
                }
            }
            
            // add to result
            ret.push_back(cur_val);
            
            
            reverse(next_level.begin(), next_level.end());

            // move to next level
            cur_level = next_level;
            flag = !flag;
        }
        
        return ret;
    }
};