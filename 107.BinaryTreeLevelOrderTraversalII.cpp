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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> results;
        if (root) {
            vector<TreeNode*> cur_level;
            cur_level.push_back(root);
            while (cur_level.size()) {
                vector<TreeNode*> next_level;
                vector<int> cur_vals;
                for (auto node : cur_level) {
                    cur_vals.push_back(node->val);
                    if (node->left) next_level.push_back(node->left);
                    if (node->right) next_level.push_back(node->right);
                }
                results.push_back(cur_vals);
                cur_level = next_level;
            }
        }
        reverse(results.begin(), results.end());
        return results;
    }
};