/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// v1: backtraing, using reference to solution, faster than not using reference.
class Solution {
    void pathSumHepler(TreeNode* root, int sum, vector<int> &solution, vector<vector<int> > &result) {
        solution.push_back(root->val);
        sum -= root->val;
        
        if (isLeaf(root) && 0 == sum) {
            result.push_back(solution);
            solution.pop_back();		// pop it before back
            return;
        }
        
        if (root->left) {
            pathSumHepler(root->left, sum, solution, result);
        }
        if (root->right) {
            pathSumHepler(root->right, sum, solution, result);
        }
        
        solution.pop_back();
    }
    
    bool isLeaf(TreeNode *node) {
        if (NULL == node->left && NULL == node->right) {
            return true;
        }
        return false;
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        if (NULL == root) {
            return result;
        }
        
        vector<int> solution;
        pathSumHepler(root, sum, solution, result);
        return result;
    }
};

// v2: not using reference
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
    void pathSumHepler(TreeNode* root, int sum, vector<int> solution, vector<vector<int> > &result) {
        solution.push_back(root->val);
        sum -= root->val;
        
        if (isLeaf(root) && 0 == sum) {
            result.push_back(solution);
            //solution.pop_back();
            return;
        }
        
        if (root->left) {
            pathSumHepler(root->left, sum, solution, result);
        }
        if (root->right) {
            pathSumHepler(root->right, sum, solution, result);
        }
        
        //solution.pop_back();
    }
    
    bool isLeaf(TreeNode *node) {
        if (NULL == node->left && NULL == node->right) {
            return true;
        }
        return false;
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        if (NULL == root) {
            return result;
        }
        
        vector<int> solution;
        pathSumHepler(root, sum, solution, result);
        return result;
    }
};