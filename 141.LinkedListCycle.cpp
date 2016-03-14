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
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        
        ListNode *p, *q;
        q = head;
        p = head->next;
        while (p && q) {
            if (p == q) {
                return true;
            }
            
            if (p->next) {
                p = p->next->next;
            } else {
                return false;
            }
            q = q->next;
        }
        return false;
    }
};