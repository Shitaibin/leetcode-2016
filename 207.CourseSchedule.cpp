// 公司:Facebook
// 
// 使用DFS判断有向图有没有环


// v2: 260ms. O(EV)
// using less space than v1.
class Solution {
    bool hasCycle(int n, vector<int>& visited, map<int, vector<int>>& graph) {
        if (visited[n] == 2) return false;
        if (visited[n] == 1) return true;
        /* add to current path, visited once */
        visited[n] = 1;
        for (int i = 0; i < graph[n].size(); i++) {
            /* DFS */
            if (hasCycle(graph[n][i], visited, graph))
                return true;
        }
        /* no cycle found, mark this node*/
        visited[n] = 2;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        /* using map to stor the graph, it's easy to search the edge for each node */
        map<int, vector<int>> graph;
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[ prerequisites[i].second ].push_back( prerequisites[i].first );
        }
        /* visited[] is used to vistied state */
        /* 0: not visited, 1: visted once, 2: checked, no cycle */
        vector<int> visited(numCourses, 0);
        for (int id = 0; id < numCourses; id++) {
            if (hasCycle(id, visited, graph))
                return false;
        }
        return true;
    }
};


// v1:260ms
class Solution {
    bool hasCycle(int n, vector<bool>& explored, vector<bool>& path, map<int, vector<int>>& graph) {
        /* already checked and no cycle from n */
        if (explored[n]) return false; 

        /* check all neighbors */
        for (int i = 0; i < graph[n].size(); i++) {
            int nei_id = graph[n][i];
            /* detect the cycle: nei_id already in path */
            if (path[nei_id]) return true;
            
            /* set the marker */
            path[nei_id] = true;
            
            /* DFS */
            if (hasCycle(nei_id, explored, path, graph))
                return true;
            
            /* backtrace reset */
            path[nei_id] = false;
        }
        /* no cycle found, mark this node can finished */
        explored[n] = true;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        /* using map to stor the graph, it's easy to search the edge for each node */
        map<int, vector<int>> graph;
        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i].first].push_back( prerequisites[i].second );
        }
        
        /* explored[] is used to record the node alread checked and no cycle */
        vector<bool> explored(numCourses, false);
        /* path[] is used to check the cycle during DFS */
        vector<bool> path(numCourses, false);
        
        for (int i = 0; i < numCourses; i++) {
            if (explored[i]) continue;
            if (hasCycle(i, explored, path, graph))
                return false;
        }
        return true;
    }
};