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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL)
            return ret;
        
        vector<TreeNode*> cur_nodes;
        cur_nodes.push_back(root);
        while (cur_nodes.size()) {
            vector<int> cur_val;
            vector<TreeNode*> next_nodes;
            for (auto node: cur_nodes) {
                cur_val.push_back(node->val);
                if (node->left)
                    next_nodes.push_back(node->left);
                if (node->right)
                    next_nodes.push_back(node->right);
            }
            ret.push_back(cur_val);
            cur_nodes = next_nodes;
        }
        return ret;
    }
};