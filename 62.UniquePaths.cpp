class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int grid[110][110] = {1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i-1 >= 0)
                    grid[i][j] += grid[i-1][j];
                if (j-1 >= 0)
                    grid[i][j] += grid[i][j-1];
            }
        }
        
        return grid[m-1][n-1];
    }
};