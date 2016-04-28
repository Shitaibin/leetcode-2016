/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
// 公司：Uber


// v3：O(N)。108ms。这种方法不使用额外空间，也不需要查询。
// 再每个节点的后面添加一个新的节点，作为该接线点的拷贝。
// 然后再次遍历填写新节点的random指针，具有如下关系：
// cur->next->random = cur->random->next;
// 最后把这些节点从链表中取出来。

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        
        RandomListNode* cur = head;
        while (cur) {
            RandomListNode* tmp = new RandomListNode(cur->label);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        
        RandomListNode HEAD(0);
        RandomListNode* tail = &HEAD;
        cur = head;
        while (cur) {
            tail->next = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            tail = tail->next;
        }
        return HEAD.next;
    }
};


// v2：O(NlogN)，116ms。重构v1的拷贝算法。
// 不使用头结点，节省了8ms。
RandomListNode* copy(RandomListNode *head, unordered_map<RandomListNode*, RandomListNode*>& m) {
    if (head == NULL) return NULL;
    
    // RandomListNode* fake_head = new RandomListNode(0);
    // RandomListNode* cfake_head = new RandomListNode(0);
    RandomListNode* chead = new RandomListNode(head->label);
    RandomListNode* p = chead;
    m[head] = chead;
    
    // if has next node, make a copy of it, then move to it
    while (head->next) {
        RandomListNode* cnode = new RandomListNode(head->next->label);
        p->next = cnode;
        m[head->next] = cnode;
        head = head->next;
        p = cnode;
    }
    
    
    // delete fake_head;
    // delete cfake_head;
    
    return chead;
}

// v1：O(NlogN)，124ms。模拟法。
// 先使用next拷贝链表，形成就节点与新节点的映射。
// 再遍历链表，设置random指针。
class Solution {
    // copy the list by using next pointer
    RandomListNode* copy(RandomListNode *head, unordered_map<RandomListNode*, RandomListNode*>& m) {
        RandomListNode* fake_head = new RandomListNode(0);
        RandomListNode* cfake_head = new RandomListNode(0);
        RandomListNode* chead;
        fake_head->next = head;
        head = fake_head;
        chead = cfake_head;
        // if has next node, make a copy of it, then move to it
        while (head->next) {
            RandomListNode* cnode = new RandomListNode(head->next->label);
            chead->next = cnode;
            m[head->next] = cnode;
            head = head->next;
            chead = cnode;
        }
        chead = cfake_head->next;
        
        delete fake_head;
        delete cfake_head;
        
        return chead;
    }
    
    void setRandom(RandomListNode *head, RandomListNode *chead, unordered_map<RandomListNode*, RandomListNode*>& m) {
        while (head) {
            chead->random = m[head->random];
            head = head->next;
            chead = chead->next;
        }
    }
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> m;
        RandomListNode* chead = copy(head, m);
        setRandom(head, chead, m);
        return chead;
    }
};