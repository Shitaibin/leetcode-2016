
// 公司：Airbnb

/* 如果DP写起来很复杂，你肯定想错了，用相反的角度思考一下，也许才是对的。*/

/**
 * 更多讨论：
 * https://leetcode.com/discuss/38489/easy-solution-with-detailed-explanations-8ms-time-and-space
 * 列出了如何使用1维数组解决的方案，去手动模拟吧
 */

// v1: O(m*n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int m = matrix.size();
        if (m == 0) return 0;
        const int n = matrix[0].size();
        if (n == 0) return 0;
        
        int max_len = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = matrix[i][j] - '0';
                if (i != 0 && j != 0 && dp[i][j] != 0) {
                    dp[i][j] = min( min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] ) + 1;
                }
                
                if (dp[i][j] > max_len) {
                    max_len = dp[i][j];
                }
            }
        }
        return max_len * max_len;
    }
};