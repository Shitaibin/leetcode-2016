/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
// v2: https://github.com/haoel/leetcode/blob/master/algorithms/cpp/populatingNextRightPointersInEachNode/populatingNextRightPointersInEachNode.II.cpp
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        
        if (root->left && root->right) {
            root->left->next = root->right;
        }
        
        if (root->next) {
            TreeLinkNode *left, *right;
            left = right = NULL;
            
            left = root->right ? root->right:root->left;
            
            // find the next
            for (TreeLinkNode *p = root->next; p!=NULL; p=p->next) {
                if (p->left) {
                    right = p->left;
                    break;
                }
                if (p->right) {
                    right = p->right;
                    break;
                }
            }
            
            if (left) {
                left->next = right;
            }
        }
        
        // Hi, care about this.
        // make the right part link to next first. 
        // Or, for can't find the corret next.
        connect(root->right);
        connect(root->left);
    }
};


// The root of thought is not right.
class Solution {
    enum TYPE {LEFT, RIGHT, NEXT};
    
    bool isLeaf(TreeLinkNode *node) {
        if (!node->left && !node->right) {
            return true;
        }
        return false;
    }
    
    void findNext(TreeLinkNode *root, TreeLinkNode *node) {
        // level of `node` is upper than `root` one level
        while (node) {
            if (isLeaf(node)) {
                node = node->next;
                continue;
            }
            
            // got the node which has child
            if (node->left) {
                root->next = node->left;
            } else {
                root->next = node->right;
            }
            return;
        }
    }
    
    void connectHelper(TreeLinkNode *root, TYPE type, TreeLinkNode* parent) {
        if (!root->next) { // v3, add this shell
            if (type == LEFT) {
                // root is left child
                if (NULL != parent->right) {
                    root->next = parent->right;
                } else {
                    findNext(root, parent->next);
                }
            } else {
                // root is right child
                findNext(root, parent->next);
            }
        }
        
        
        
        // v1:it's wrong. we should using level traversal.
        // because the current level based on the upper level.
        // but it will use extra space, if you using queue.
        // // deal with next level nodes
        // if (root->left) {
        //     connectHelper(root->left, LEFT, root);
        // }
        // if (root->right) {
        //     connectHelper(root->right, RIGHT, root);
        // }
        
        // v2: I got an idea. the next alway move the next node at the same level.
        // So, I go to next first, and then go to left, last, go to the right child.
        // Bloody hell. IF `next` has visited this node, `left` and `right` may 
        // revisit it again. SO, Time Consuming.
        // if (root->next) {
        //     connectHelper(root->next, NEXT, root);
        // }
        // if (root->left) {
        //     connectHelper(root->left, LEFT, root);
        // }
        // if (root->right) {
        //     connectHelper(root->right, RIGHT, root);
        // }
        
        // v3: If root->next is not NULL, so, it must have been visited.
        // BUT, still TLE,
        if (root->next) {
            connectHelper(root->next, NEXT, root);
        }
        if (root->left) {
            connectHelper(root->left, LEFT, root);
        }
        if (root->right) {
            connectHelper(root->right, RIGHT, root);
        }
    }
    
public:
    void connect(TreeLinkNode *root) {
        if (NULL == root) {
            return;
        }
        
        if (root->left) {
            connectHelper(root->left, LEFT, root);
        }
        if (root->right) {
            connectHelper(root->right, RIGHT, root);
        }
    }
};