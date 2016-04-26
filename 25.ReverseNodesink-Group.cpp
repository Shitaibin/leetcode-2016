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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        head = new_head;
        
        while (head) {
            ListNode* tail = head;
            int i;
            for (i = 0; i < k && tail;i++)
                tail = tail->next;
            
            // not enough to reverse
            if (i < k || tail == NULL) break;
            
            // save next section
            ListNode* next_section = tail->next;
            // revser it
            tail->next = NULL;
            ListNode* p = head->next;
            head->next = next_section;
            tail = p;   // after reverse, tail->next = next_section
            
            while (p) {
                ListNode* next = p->next;
                p->next = head->next;
                head->next = p;
                p = next;
            }
            // move head to `tail`
            head = tail;
        }
        
        return new_head->next;
    }
};