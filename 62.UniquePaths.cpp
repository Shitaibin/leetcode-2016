class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> v(n,1);
        vector<vector<int>> grid(m, v);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        
        return grid[m-1][n-1];
    }
};