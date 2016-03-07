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
    vector<TreeNode*> generateTrees(int low, int high) {
        vector<TreeNode*> v;
        if (low > high || low <= 0 || high <= 0) {
            v.push_back(NULL);
            return v;
        }
        
        // leaf node
        if (low == high) {
            TreeNode *node = new TreeNode(low);
            v.push_back(node);
            return v;
        }
        
        // each node as root
        for (int i = low; i <= high; i++) {
            vector<TreeNode *> vleft = generateTrees(low, i-1); // all left sub tree
            vector<TreeNode *> vright = generateTrees(i+1, high); // all right sub tree
            for (int l = 0; l < vleft.size(); l++) {
                for (int r = 0; r < vright.size(); r++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = vleft[l];
                    root->right = vright[r];
                    v.push_back(root);
                }
            }
        }
        
        return v;
    }
    
    
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> v;
        if (n <= 0) return v;
        v = generateTrees(1, n);
        return v;
    }
};