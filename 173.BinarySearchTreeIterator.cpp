// 把中序遍历分解为几个模块

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    TreeNode *node;
    stack<TreeNode*> sta;
public:
    BSTIterator(TreeNode *root) : node(root) {
        goSmallest(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        // sta not empty
        return sta.size();
    }

    /** @return the next smallest number */
    int next() {
        // pop it, go his right child
        node = sta.top();
        sta.pop();
        int x = node->val;
        goSmallest(node->right);
        return x;
    }
    
    void goSmallest(TreeNode *root) {
        while (root) {
            sta.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */