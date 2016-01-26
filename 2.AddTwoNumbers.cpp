/**
 * 1. 两个链表皆非空，但长度不一定相等。
 * 2. 最后同样可能存在进位。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 int adjust(ListNode *l) {
     if (l->val > 9) {
         l->val -= 10;
         return 1;
     } else {
         return 0;
     }
 }
 
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3_head = new ListNode(-1);
        ListNode *l3 = l3_head;
        int carry = 0;
        while (l1 && l2) {
            l3->next = new ListNode(carry + l1->val + l2->val);
            l3 = l3->next;
            carry = adjust(l3);
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
            l3->next = new ListNode(carry + l1->val);
            l3 = l3->next;
            carry = adjust(l3);
            l1 = l1->next;
        }
        
        while (l2) {
            l3->next = new ListNode(carry + l2->val);
            l3 = l3->next;
            carry = adjust(l3);
            l2 = l2->next;
        }
        
        if (carry) {
            l3->next = new ListNode(1);
        }
        return l3_head->next;
    }
};