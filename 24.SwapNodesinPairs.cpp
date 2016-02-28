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
    ListNode* swapPairs(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        head = new_head; // using head as the tail of the previous pair
        while (head->next && head->next->next) {
            ListNode* p = head->next;
            ListNode* q = p->next;
            p->next = q->next;
            head->next = q;
            q->next = p;
            // move head
            head = p;
        }
        return new_head->next;
    }
};