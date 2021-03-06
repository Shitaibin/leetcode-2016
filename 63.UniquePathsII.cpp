// v1: not good
// v2: better

// v1
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty())
            return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<int> v(n,1);
        vector<vector<int>> grid(m, v);
        
        // check column 1
        bool has_obstacle = false;
        for (int i=0; i<m; i++) {
            if (has_obstacle || obstacleGrid[i][0] == 1) {
                grid[i][0] = 0;
                has_obstacle = true;
            }
        }
        // check row 1
        has_obstacle = false;
        for (int i=0; i<n; i++) {
            if (has_obstacle || obstacleGrid[0][i] == 1) {
                grid[0][i] = 0;
                has_obstacle = true;
            }
        }
        
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                // obstacle
                if (obstacleGrid[i][j] == 1) {
                    grid[i][j] = 0;
                    continue;
                }
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};

// v2: O(1) space
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty())
            return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
    
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                // obstacle
                if (obstacleGrid[i][j] == 1) {
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                // init first point if not obstacle
                if (i == 0 && j == 0 && obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = 1;
                }
                if (i > 0) {
                    obstacleGrid[i][j] += obstacleGrid[i-1][j];
                }
                if (j > 0) {
                    obstacleGrid[i][j] += obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};