/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// v2: O(N)。
/* 潜在bug：必须保证p,q都在树中 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        //left==NULL means both `p` and `q` are not found in left tree.
        if (left == NULL) return right;
        //right==NULL means both `p` and `q` are not found in right tree.
        if (right == NULL) return left;
        // left!=NULL && right !=NULL, which means `p` & `q` are seperated in left and right tree.
        return root;
    }
};


// v1：O(N)。先得路径，再得路径上最相近的点
class Solution {
    bool findPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {
        if (!root) return false;

        if (root == p) {
            path.push_back(root);
            return true;
        }
        
        path.push_back(root);
        if (findPath(root->left, p, path) || findPath(root->right, p, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path({NULL}), q_path({NULL});
        findPath(root, p, p_path);
        findPath(root, q, q_path);
        
        int i;
        for (i = 0; i < min(p_path.size(), q_path.size()); i++) {
            if (p_path[i] != q_path[i]) break;
        }
        return p_path[--i];
    }
};