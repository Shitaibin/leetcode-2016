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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n || head == NULL) {
            return head;
        }
        
        ListNode *new_head = new ListNode (0);
        new_head->next = head;
        ListNode *pre_pm = new_head;
        for (int i = 0; i < m-1; i++) { // bug源自while(m--),在移动某个数量位置的时候，避免使用while
            pre_pm = pre_pm->next;
        }
        
        ListNode *pm = pre_pm->next;
        ListNode *pn = pm->next;
        for (int i = 0; i < n-m && pn; i++) {
            ListNode *next = pn->next;
            pn->next = pre_pm->next;
            pre_pm->next = pn;
            pn = next;
        }
        pm->next = pn;
        
        return new_head->next;
    }
};