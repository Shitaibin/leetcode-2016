/**
 * 添加一个假头结点，就不需要判断移除的是否是真头结点，
 * 以及，只需要使用两个指针，而不是pre, cur, fast。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *HEAD = new ListNode(0);
        HEAD->next = head;
        
        ListNode *fast = head, *pre = HEAD;
        while (n--) fast = fast->next;
        while (fast) {
            fast = fast->next;
            pre = pre->next;
        }
        
        ListNode *remove_node = pre->next;
        pre->next = remove_node->next;
        free(remove_node);
        return HEAD->next;
    }
};