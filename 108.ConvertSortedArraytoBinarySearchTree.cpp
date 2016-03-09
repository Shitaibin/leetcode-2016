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
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int low, int high) {
        int mid = low + (high-low) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if (low <= mid-1) {
            root->left = sortedArrayToBSTHelper(nums, low, mid-1);
        }
        if (mid+1 <= high) {
            root->right = sortedArrayToBSTHelper(nums, mid+1, high);
        }
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        
        return sortedArrayToBSTHelper(nums, 0, nums.size()-1);
    }
};