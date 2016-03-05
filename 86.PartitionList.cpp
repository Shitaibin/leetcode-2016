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
    ListNode* partition(ListNode* head, int x) {
        ListNode *s_head = new ListNode(0);
        ListNode *b_head = new ListNode(0);
        ListNode *s_tail = s_head;
        ListNode *b_tail = b_head;
        ListNode *p = head;
        while (p) {
            ListNode *q = p->next;
            if (p->val < x) {
                s_tail->next = p;
                s_tail=s_tail->next;
            } else {
                b_tail->next = p;
                b_tail = b_tail->next;
            }
            p = q;
        }
        b_tail->next = NULL;
        s_tail->next = b_head->next;
        return s_head->next;
    }
};