// 公司：Facebook

// 从1扩张，把1变成0.

// v1: O(M*N)。DFS
class Solution {
    int m;
    int n;
    
    void numIslandsDFS(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= m) return ;
        if (j < 0 || j >= n) return ;
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            numIslandsDFS(grid, i-1, j);
            numIslandsDFS(grid, i+1, j);
            numIslandsDFS(grid, i, j-1);
            numIslandsDFS(grid, i, j+1);
        }
    }
    
    
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
        if (n == 0) return 0;
        
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    grid[i][j] = '0';
                    numIslandsDFS(grid, i-1, j);
                    numIslandsDFS(grid, i+1, j);
                    numIslandsDFS(grid, i, j-1);
                    numIslandsDFS(grid, i, j+1);
                }
            }
        }
        return count;
    }
};