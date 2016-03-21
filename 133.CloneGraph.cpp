// v1: WRONG. 并没有真正克隆。你要想想为什么结构体的构造，没有初始化vector，
//      你以为人家傻吗？
// v2: RIGHT ONE.


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

 
// v2: RIGHT ONE.
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (NULL == node) {
            return NULL;
        }
        
        // create a map, key is source node, value is clone node
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> clone_map;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        
        // clone the root 
        UndirectedGraphNode* clone_node = new UndirectedGraphNode(node->label);
        clone_map[node] = clone_node;
        
        // BFS
        while (q.size()) {
            node = q.front();
            q.pop();
            
            // add not visited neighbors into queue
            vector<UndirectedGraphNode *> neighbors = node->neighbors;
            for (int i = 0; i < neighbors.size(); i++) {
                UndirectedGraphNode* neighbor = neighbors[i];
                if (clone_map.find(neighbor) == clone_map.end()) {
                    // clone a new node
                    UndirectedGraphNode *new_node = new UndirectedGraphNode(neighbor->label);
                    clone_map[node]->neighbors.push_back(new_node);
                    clone_map[neighbor] = new_node;
                    
                    // put the neighbor into queue
                    q.push(neighbor);
                } else {
                    clone_map[node]->neighbors.push_back(clone_map[neighbor]);
                }
            }
        }
        
        return clone_node;
    }
};

// v1: WRONG. 并没有真正克隆。
UndirectedGraphNode *cloneNode(UndirectedGraphNode * node) {
    UndirectedGraphNode *clone_node = new UndirectedGraphNode(node->label);
    clone_node->neighbors = node->neighbors; // bug:因为这些是旧节点的地址
    return clone_node;
}

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (NULL == node) {
            return NULL;
        }
        
        unordered_set<UndirectedGraphNode *> cloned_set;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        
        UndirectedGraphNode *new_node = NULL;
        
        while (q.size()) {
            node = q.front();
            q.pop();
            
            // clone 
            UndirectedGraphNode* clone_node = cloneNode(node);
            cout << long(&node) << " " << long(&clone_node) << endl;
            
            // mark first cloned node for return
            if (cloned_set.empty()) {
                new_node = clone_node;
            }
            
            // add node to visited
            cloned_set.insert(node);
            
            // add not visited neighbors into queue
            vector<UndirectedGraphNode *> neighbors = node->neighbors;
            for (int i = 0; i < neighbors.size(); i++) {
                if (cloned_set.find(neighbors[i]) == cloned_set.end()) {
                    q.push(neighbors[i]);
                }
            }
        }
        
        return new_node;
    }
};