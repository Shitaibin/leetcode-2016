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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *head_node = new ListNode(0);
        ListNode *p = head;
        while (p) {
            ListNode *t = p->next;
            // find insert place
            head = head_node;
            while (head->next && head->next->val < p->val) {
                head = head->next;
            }
            // insert
            p->next = head->next;
            head->next = p;
            // move p to next
            p = t;
        }
        return head_node->next;
    }
};