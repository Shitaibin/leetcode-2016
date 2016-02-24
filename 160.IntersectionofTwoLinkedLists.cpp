// better than mine
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

            //caculate the length of each List
            int lenA = getListLength(headA);
            int lenB = getListLength(headB);

            if (lenA<=0 || lenB<=0 ) return NULL;

            //let List A is the longest List;
            if (lenA < lenB){
                swap(headA, headB);
            }

            //move head of List A, make both of Lists are same length 
            for (int i=0; i<abs(lenA-lenB); i++){
                headA = headA->next;
            }

            //synced travel both of Lists and check their nodes are same or not 
            while (headA != headB){
                headA = headA->next;
                headB = headB->next;
            }

            return headA;
        }
    private:    
        inline int getListLength(ListNode *head){
            int len=0;
            while(head!=NULL){
                head = head->next;
                len++;
            }
            return len;
        }
};