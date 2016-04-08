// 附加题：
// 经常存在插入与删除操作，如何优化，快速的查找到第k小的数字。
// 
// 假设树的高度为H，方便后面分析时间复杂度。
// 
// 论坛上的思路是更改节点信息，设置一个变量leftTotal存放左子树的节点数量。
// 但是，经过思考，其实还需要设置rightTotal存放右子树的节点数量。
// 原因如下：
// 1. 父节点在更新leftTotal时，需要的是整颗左子树的节点数量，
//    而不是左子树的左子树数量+1。具体细节情况之一如下：
//    删除删除左子树left_child的右子树left_right_child的某个节点，
//    尽管left_child的leftTotal不会变化，但是当前节点的leftTotal却减去了1。
// 
// 这样调整之后，查找效率由O(N)提高为O(H)。
// 结构体定义如下：
struct TreeNode {
    int val;
    int leftTotal;
    int rightTotal;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 但这种方案好不好呢？细节推敲起来，并不好，虽然查找的效率提升上去了，但是
// 为何节点信息的开销却增加了。
// 1. 如果删除的是叶节点，更新根节点到叶节点路径上每个节点的信息就好了。
// 2. 如果删除的是非叶节点，我首先要满足二叉搜索树的约束进行调整，
//    二叉搜索树的调整，会转化为删除右子树的最左边的节点，所以转化为1。

// 如果删除的节点是必然存在与树中的，那么我们可以顶向下，
// 依次更新节点信息，直到某个页节点。如果删除的节点，不确定在不在，
// 就需要两次遍历。时间复杂度没有变O(H)。

// 复杂度并不高呀，看似没有影响，但是题目是：经常插入与删除。
// 每插入与删除一次，就要维护一下结构，维护开销就上去了。其实这种
// 结构适合的是不经常插入与删除的情况，就像数据库的索引一样。


// v1: 少了一个变量，就让速度提升了4ms
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> sta;
        //int count = 0; // 不使用count
        while (root || sta.empty() == false) {
            while (root) {
                sta.push(root);
                root = root->left;
            }
            
            root = sta.top();
            sta.pop();
            k--;
            if (0 == k) {
                return root->val;
            }
            
            root = root->right;
        }
        
        return -1;
    }
};


// v2: 因为root只在访问的时候使用，访问时可以使用栈顶代替root
// 但这样降低了可读性，效率也并不会有提升
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> sta;
        //int count = 0;
        while (root || sta.empty() == false) {
            while (root) {
                sta.push(root);
                root = root->left;
            }
            
            k--;
            if (0 == k) {
                return sta.top()->val;
            }
            
            root = sta.top()->right;
            sta.pop();
        }
        
        return -1;
    }
};