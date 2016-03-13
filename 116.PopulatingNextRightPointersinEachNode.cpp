/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 const int  LEFT_NODE = 0;
 const int  RIGHT_NODE = 1;
 
class Solution {
    void connectHelper(TreeLinkNode *root, TreeLinkNode* parent, int node_type){
        if (!root) return;
        
        if (node_type == LEFT_NODE) {
            // root is the left child of `parent`
            root->next = parent->right;
        } else if (parent && parent->next) {
            // root is the right child of `parent`
            // and parent is valid and parent has valid next
            root->next = parent->next->left;
        }
        
        connectHelper(root->left, root, LEFT_NODE);
        connectHelper(root->right, root, RIGHT_NODE);
    }
    
public:
    void connect(TreeLinkNode *root) {
        connectHelper(root, NULL, RIGHT_NODE);
    }
};