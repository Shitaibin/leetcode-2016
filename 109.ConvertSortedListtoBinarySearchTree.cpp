/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
private:
    TreeNode* sortedListToBST(ListNode* &head, int low, int high) { 
        //key1: type of head, using reference
        if (low > high || head == NULL) {
            return NULL;
        }
        
        int mid = low + (high-low)/2;
        TreeNode* left_child = sortedListToBST(head, low, mid-1);
        // new the root node
        TreeNode* root = new TreeNode(head->val);
        root->left = left_child;
        // move to the next node
        head = head->next;  // key 2
        root->right = sortedListToBST(head, mid+1, high);
        return root;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        for (ListNode* p = head; p != NULL; p=p->next) {
            len++;
        }
        sortedListToBST(head, 0, len-1);
    }
};