typedef long long utype; // lintcode
//typedef int utype; //leetcode

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        if (rand() % 2)
            return rob1(A);
        return rob2(A);
    }
    
    long long rob1(vector<int> &A) {
        int n = A.size();
        if (!n) return 0;
        vector<utype> dp(n, 0);
        dp[0] = A[0];
        if (n > 1) dp[1] = max(A[0], A[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+A[i]);
        }
        return dp[n-1];
    }
    
    long long rob2(vector<int> &A) {
        utype n1 = 0; // dp[i-1]
        utype n2 = 0; // dp[i-2]
        for (int i = 0; i < A.size(); i++) {
            utype current = max(n1, n2 + A[i]);
            n2 = n1;
            n1 = current;
        }
        return n1;
    }
};