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
private:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int i_start, int p_end, int len) {
        TreeNode *root = NULL;
        
        for (int i = i_start; i < i_start+len; i++) {
            if (inorder[i] == postorder[p_end]) {
                // find the root
                root = new TreeNode(inorder[i]);
                int left_len = i - i_start;
                root->left = buildTreeHelper(inorder, postorder, i_start, p_end-len+left_len, left_len);
                root->right = buildTreeHelper(inorder, postorder, i+1, p_end-1, len-left_len-1);
            }
        }
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, postorder, 0, postorder.size()-1, postorder.size());
    }
};