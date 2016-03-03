// dynamic, AC
// backtracking, TLE

// v1: dynamic, AC
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i-1 >= 0 && j-1 >= 0) {
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]); //key
                    continue;
                }
                if (i-1 >= 0) {
                    grid[i][j] += grid[i-1][j];
                }
                if (j-1 >= 0) {
                    grid[i][j] += grid[i][j-1];
                }
            }
        }
        
        return grid[m-1][n-1];
    }
};

// v2: backtracking, TLE
class Solution {
private:
    int min_path_sum = INT_MAX;
    
    void search(vector<vector<int>>& grid, int i, int j, int m , int n, int path_sum) {
        path_sum += grid[i][j];
        
        // got a new solution
        if (i == m-1 && j == n-1) {
            if (path_sum < min_path_sum) {
                min_path_sum = path_sum;
            }
            return;
        }
        // never forget boundary
        if (i < m-1) {
            search(grid, i+1, j, m, n, path_sum);
        }
        if (j < n-1) {
            search(grid, i, j+1, m, n, path_sum);
        }
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size()-1;
        
        search(grid, 0, 0, m, n, 0);
        return min_path_sum;
    }
};