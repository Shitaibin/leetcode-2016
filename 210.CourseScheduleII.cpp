公司：Facebook

/* 拓扑排序算法，来自Hints
 * https://class.coursera.org/algo-003/lecture/52
 *
 */

// v2：基于Kahn算法的拓扑排序：找出所有入度为0的点，加入集合S，从S中任选1点访问，然后移除出度的边，再将入度为0的点加入集合S。


// v1：504ms，基于DFS的拓扑排序，不是很高效。
class Solution {
    int cur_label;
    
    bool hasCycle(int n, vector<int>& visited, vector<int>& order, map<int, vector<int>>& graph) {
        if (visited[n] == 2) return false;
        if (visited[n] == 1) return true;

        /* add to current path, visited once */
        visited[n] = 1;
        for (int i = 0; i < graph[n].size(); i++) {
            /* DFS */
            if (hasCycle(graph[n][i], visited, order, graph))
                return true;
        }
        /* no cycle found, mark this node*/
        visited[n] = 2;

        /* set topological order */
        order[n] = cur_label;
        cur_label--;
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        /* cur_bael, order[] is used for topological sort */
        cur_label = numCourses-1;
        vector<int> order(numCourses, -1);
        
        /* using map to stor the graph, it's easy to search the edge for each node */
        map<int, vector<int>> graph;
        for (int i = 0; i < prerequisites.size(); i++) {
        	/* different with Course Schedule */
            graph[ prerequisites[i].second ].push_back( prerequisites[i].first );
        }

        /* visited[] is used to vistied state */
        /* 0: not visited, 1: visted once, 2: checked, no cycle */
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(i, visited, order, graph))
                return (vector<int>());
        }
        
        /* put the class id in to the right order */
        vector<int> result(numCourses);
        for (int i = 0; i < numCourses; i++) {
            result[order[i]] = i;
        }
        return result;
    }
};