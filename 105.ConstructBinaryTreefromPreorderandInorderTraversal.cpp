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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int p_start, int i_start, int len) {
        TreeNode *root = NULL;
        
        for (int i = i_start; i < i_start+len; i++) {
            if (inorder[i] == preorder[p_start]) {
                // find the root
                root = new TreeNode(preorder[p_start]);
                int left_len = i-i_start;
                root->left = buildTreeHelper(preorder, inorder, p_start+1, i_start, left_len);
                root->right = buildTreeHelper(preorder, inorder, p_start+left_len+1, i+1, len-left_len-1);
            }
        }
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, inorder, 0, 0, inorder.size());
    }
};