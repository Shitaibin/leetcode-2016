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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* pre = new_head;
        while (pre->next) {
            if (pre->next->val == val) {
                ListNode* t = pre->next;
                pre->next = t->next;
                free(t);
            } else {
                pre = pre->next;
            }
        }
        return new_head->next;
    }
};