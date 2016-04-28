// 公司：未知


// v1: O(N). 56ms.
// 考虑到BST的特性，中序遍历是有序递增的。那么下面这个例子：
// 1, 2, 3, 8, 5, 6, 7, 4, 9
// 其中，8和4是被交换的，他们具有什么特点？
// 1. 本来是递增的，交换后存在局部的逆序，比如[8, 5]和[7, 4]。
// 也就是说，我们从前向后遍历出来这两对数就可以，然后把
// 第1对的第1个数字，和第2对的第2个数字交换，就可以完成
// Recover。
// 对于二叉树而言，我们可以记录前面访问的节点，却不太容易
// 获取下一个需要访问的节点。因此使用[prev_node, cur_node]
// 作为1对，看他们是否具有局部逆序关系。
class Solution {
    TreeNode* first, *second, *prev;
    
    void inorder(TreeNode* root) {
        if (root == NULL) return;
        
        inorder(root->left);
        if (prev && prev->val > root->val) {
            if (first == NULL) first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
    
public:
    Solution(): first(NULL), second(NULL), prev(NULL) {}
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};


// v2: 迭代模式
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* pre, *n1, *n2;
        pre = n1 = n2 = NULL;
        
        stack<TreeNode*> sta;
        while (!sta.empty() || root) {
            while (root) {
                sta.push(root);
                root = root->left;
            }
            
            // visit current node
            root = sta.top();
            sta.pop();
            if (pre && root->val <= pre->val) {
                if (n1 == NULL)
                    n1 = pre;
                n2 = root;
            }
            pre = root;
            
            root = root->right;
        }
        
        // found the nodes
        if (n1 && n2) {
            swap(n1->val, n2->val);
        }
    }
};