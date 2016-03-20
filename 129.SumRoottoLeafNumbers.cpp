/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// v1: iterative
class Solution {
private:
    void sumNumbersHelp(TreeNode* root, int sum, int &ret) {
        if (!root) {
            return;
        }
        
        sum = sum*10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            ret += sum;
        } else {
            // 调用再判断
            //    // sumNumbersHelp(root->left, sum, ret);
            //    // sumNumbersHelp(root->right, sum, ret);
            //
            
            // 判断再决定是否调用
            if (root->left) {
                sumNumbersHelp(root->left, sum, ret);
            }
            if (root->right) {
                sumNumbersHelp(root->right, sum, ret);
            }
            
            
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int ret = 0;
        sumNumbersHelp(root, 0, ret);
        return ret;
    }
};


// v2: iterative

struct Node {
    TreeNode *root;
    int sum;
    Node(TreeNode *t, int s): root(t), sum(s) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        queue<Node> q;
        q.push(Node(root, root->val));
        
        int ret = 0;
        
        // queue not empty
        while (q.size()) {
            Node node = q.front();
            q.pop();
            
            root = node.root;
            int sum = node.sum;
            
            if (root->left == NULL && root->right == NULL) {
                ret += sum;
            } else {
                if (root->left) {
                    q.push(Node(root->left, sum*10+root->left->val));
                }
                if (root->right) {
                    q.push(Node(root->right, sum*10+root->right->val));
                }
            }
        }
        
        return ret;
    }
};