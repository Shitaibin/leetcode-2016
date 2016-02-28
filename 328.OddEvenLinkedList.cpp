/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // v1
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(0);
        ListNode* even = new ListNode(0);
        ListNode* odd_tail = odd, *even_tail = even;
        int idx = 1;
        ListNode* p = head;
        while (p) {
            if (idx) {
                idx = 0;
                odd_tail->next = p;
                odd_tail = p;
            } else {
                idx = 1;
                even_tail->next = p;
                even_tail = p;
            }
            p = p->next;
        }
        even_tail->next = NULL; // fix bug: when size is odd, even_tail is not NULL
        odd_tail->next = even->next;
        return odd->next;
    }
};

// v2
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        ListNode *p_odd_tail = head;
        ListNode *p_even = head->next;
        ListNode *p_next = NULL;
        while (p_even && (p_next = p_even->next)) {
            p_even->next = p_next->next; // point to new even item
            p_next->next = p_odd_tail->next; // link to even head
            p_odd_tail->next = p_next;
            
            p_even = p_even->next; // move to new even item
            p_odd_tail = p_odd_tail->next; // move to new odd tail
        }
        return head;
    }
};