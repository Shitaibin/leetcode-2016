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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* p = head;
        while (p) {
            n++;
            p = p->next;
        }
        
        p = head;
        for (int i = 0; i < n/2; i++) {
            p = p->next;
        }
        if (n%2 == 1) {
            p = p->next;
        }
        
        ListNode * new_head = reverseList(p);
        for (int i = 0; i < n/2; i++) {
            if (head->val != new_head->val) {
                return false;
            }
            head = head->next;
            new_head = new_head->next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        while (head) {
            ListNode *t = head->next;
            head->next = new_head->next;
            new_head->next = head;
            head = t;
        }
        return new_head->next;
    }
};