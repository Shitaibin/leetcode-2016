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
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        while (head) {
            ListNode* t = head->next;
            head->next = new_head->next;
            new_head->next = head;
            head = t;
        }
        return new_head->next;
    }
};