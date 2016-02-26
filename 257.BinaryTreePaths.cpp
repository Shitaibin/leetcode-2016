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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if (root == NULL)
            return ret;
        
        vector<int> path;
        getPaths(root, path, ret);
        return ret;
    }
    
    void getPaths(TreeNode* root, vector<int> path, vector<string> &ret) {
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            // new path
            ret.push_back(formatPath(path));
        } else {
            if (root->left) {
                getPaths(root->left, path, ret);
            }
            if (root->right) {
                getPaths(root->right, path, ret);
            }
        }
    }
    
    string formatPath(vector<int> path) {
        string ret;
        ostringstream oss;
        for (int i = 0; i < path.size()-1; i++) {
            oss << path[i] << "->";
        }
        oss << path.back();
        return oss.str();
    }
};