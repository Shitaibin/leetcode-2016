/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// v2: optimized, 64ms

 


// v1: 68ms
class Solution {
public:
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode *p = head;
        while (p) {
            n++;
            p = p->next;
        }
        
        if (n <= 2) {
            return;
        }
        
        // find middle pointer
        p = head;
        int m = n/2-1;
        while (m-- > 0) {
            p = p->next;
        }
        
        if (n % 2) {
            p = p->next;
        }
        ListNode *q = p->next;
        p->next = NULL;
        
        // reverse right part list
        p = q;
        ListNode * head_node = new ListNode(0);
        while (p) {
            q = p->next;
            p->next =head_node->next;
            head_node->next = p;
            p = q;
        }
        
        // merge two list
        p = head;
        q = head_node->next;
        while (p && q) {
            ListNode *n1 = p->next;
            ListNode *n2 = q->next;
            q->next = n1;
            p->next = q;
            
            // move to next node
            p = n1;
            q = n2;
        }
    }
};