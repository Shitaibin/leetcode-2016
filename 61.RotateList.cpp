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
 // v1: mine
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

// v2: using only one pointer
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k<=0)
            return head;
        
        // find the length of List
        int len = 1;
        ListNode* p = NULL;
        for (p = head; p->next; p = p->next) {
            len++;
        }
        p->next = head; // connect tail to head
        
    
        // k <= len, find the place
        k = len - (k % len);
        while (k--) {
            p = p->next;
        }
        
        // break list
        head = p->next;
        p->next = NULL;
        
        return head;
    }
};