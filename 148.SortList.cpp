/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* findMidPos(ListNode *head) {
        // list without head node
        ListNode *p, *q;
        p = head;
        q = head->next;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        return p;
    }
    
    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *head, *tail;
        head = tail = new ListNode(0);
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        
        // point to left nodes
        if (l1) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
        return head->next;
    }
    
    void print(ListNode* l) {
        while (l) {
            cout << l->val << " ";
            l = l->next;
        }
        cout << endl;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if (!head || head->next == NULL)
            return head;
            
        ListNode *mid = findMidPos(head);
        ListNode *right_head = mid->next;
        mid->next = NULL;
        
        // divide
        head = sortList(head);
        right_head = sortList(right_head);
        
        // merge
        head = merge(head, right_head);
        
        return head;
    }
};