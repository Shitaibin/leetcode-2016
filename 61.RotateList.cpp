/**
 * 没有限定k的大小，k>=0
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        int list_size = 0;
        for (ListNode* p = head; p; p = p->next) {
            list_size++;
        }
        
        k = k % list_size;
        if (k == 0) 
            return head;
        
        // k < list_size
        ListNode *pk = head;
        while (k--) {
            pk = pk->next;
        }
        ListNode *p = head;
        while (pk->next) {
            pk = pk->next;
            p = p->next;
        }
        pk->next = head;
        head = p->next;
        p->next = NULL;
        
        return head;
    }
};