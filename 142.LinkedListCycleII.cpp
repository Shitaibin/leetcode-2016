/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//  如果p1, p2相遇，说明是有环的，然后重置p1
//  为head，同步向后移动p1和p2，直到二者再次相遇，
//  相遇位置即结果。
class Solution {
    ListNode *p1, *p2;
    
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        p1 = p2 = head;
        
        while (p1 && p2) {
            p1 = p1->next;
            if (p2->next) {
                p2 = p2->next->next;
            } else {
                return false;
            }
            if (p1 == p2) {
                return true;
            }
        }
        return false;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if (hasCycle(head) == false) {
            return NULL;
        }
        
        p1 = head;
        
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
    }
};