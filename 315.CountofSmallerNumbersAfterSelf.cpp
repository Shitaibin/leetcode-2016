// 公司：未知


// vx：36ms，O(NlogN)。二叉搜索树。
// 每次更新时，都会更新路径上的信息，也通过less信息统计了
// 当前节点小于target的值的数量。
class BSTNode {
public:
    int val;
    int less;   // count of numbers less than val, in it's left child tree
    int equal;  // count of numbers equal to val
    BSTNode *left, *right;
    BSTNode(int x) : val(x), less(0), equal(1), left(NULL), right(NULL) {}
};

class BST {
private:
    BSTNode *root;
    
public:
    BST() : root(NULL) {}
    ~BST() {
        freeTree(root);
    }
    
    void insert(const int& target, int &lessThan) {
        insert(root, target, lessThan);
    }
    
private:
    void freeTree(BSTNode *root) {
        if (root) {
            freeTree(root->left);
            freeTree(root->right);
            delete root;
        }
    }
    
    // 更新到节点路径上的信息
    //              3
    //            /   \
    //           2     5
    //          /     /
    //         1     4 
    void insert(BSTNode* root, const int& target, int& lessThan) {
        // empty tree
        if (root == NULL) {
            this->root = new BSTNode(target);
            return ;
        }

        if (target > root->val) {
            // right
            lessThan += root->less + root->equal;
            if (root->right)
                insert(root->right, target, lessThan);  // update right child tree information
            else
                root->right = new BSTNode(target);
        } else if (target < root->val) {
            // left
            root->less++;
            if (root->left)
                insert(root->left, target, lessThan);
            else
                root->left = new BSTNode(target);
        } else {
            // Wow, found it
            lessThan += root->less;
            root->equal++;
        }
    }
};


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // cut from 40ms to 36ms
        // 初始化result大小和值
        vector<int> result(nums.size(), 0);
        BST tree;
        for (int i = nums.size()-1; i >= 0; i--) {
            tree.insert(nums[i], result[i]);
        }
        return result;
    }
};