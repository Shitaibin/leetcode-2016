// 这个DP有点复杂。
// 当前的值依赖于之前所有的值。
// dp[i] = dp[0] * dp[i-1] + dp[1] * dp[i-2] + ... + dp[i-1] * dp[0]
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j=0; j<i; j++ ) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};