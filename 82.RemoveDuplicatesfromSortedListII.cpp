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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *pre = new_head;
        ListNode *p = pre->next;
        while (p && p->next) {
            // skip duplicates
            if (p->val == p->next->val) {
                int dup_val = p->val;
                while (p && p->val == dup_val) {
                    p = p->next;
                }
                pre->next = p;
                continue;
            }
            pre = p;
            p = p->next;
        }
        return new_head->next;
    }
};