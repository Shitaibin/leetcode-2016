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
 void inorderTraversal_recursive(TreeNode *root, vector<int> &ret) {
     if (!root) return;
     
     if (root->left) {
         inorderTraversal_recursive(root->left, ret);
     }
     ret.push_back(root->val);
     if (root->right) {
         inorderTraversal_recursive(root->right, ret);
     }
 }
 
 void inorderTraversal_iterative(TreeNode *root, vector<int> &ret) {
     if (!root) return;
     
     vector<TreeNode*> stack;
     while (root || stack.size()) {
         while (root) {
             stack.push_back(root);
             root = root->left;
         }
         
         root = stack.back();
         stack.pop_back();
         ret.push_back(root->val); //visit cur node
         
         root = root->right; // move to right sub tree
     }
     
 }
 
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (rand() % 2) {
            inorderTraversal_recursive(root, result);
        } else {
            inorderTraversal_iterative(root, result);
        }
        inorderTraversal_iterative(root, result);
        return result;
    }
};