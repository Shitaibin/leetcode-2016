class Solution {
    static const size_t bufsize = 2000;
    bool palindrome[bufsize][bufsize];
    int dp[bufsize];
    string str;
 
public:
    int minCut(string s) {
        const int n = s.size();
        if (n <= 1) return 0;
        
        s.insert(s.begin(), 'x');
        str = s;
        
       
        // sub string: s[i,j] is palindrome or not
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         if (is_palindrome(i, j)) {
        //             palindrome[i][j] = true;
        //         } else {
        //             palindrome[i][j] = false;
        //         }
        //     }
        // }
        // DP的方式去判断字符串子串是不是回文
        // dp[i][j] = dp[i+1][j-1], for s[i]=s[j], i<j
        // dp[i][j] = true, for s[i]=s[j], i=j
        // 自后向前的DP1
        // for (int i = n; i >= 1; i--) {
        //     for (int j = i; j <= n; j++) {
        //         if (s[i]==s[j] && (j-i<2 || palindrome[i+1][j-1]) ) {
        //             palindrome[i][j] = true;
        //         } else {
        //             palindrome[i][j] = false;
        //         }
        //     }
        // }
        // 自前向后的DP2
        for (int i = 1; i <= n; i++) {
            // i在后，j在前
            for (int j = i; j >= 1; j--) {
                if (s[i] == s[j] && (i-j<2 || palindrome[j+1][i-1]) ) {
                    palindrome[j][i] = true;
                } else {
                    palindrome[j][i] = false;
                }
            }
        }

        // dp[i]: 长度为i的字符串分成回文的最小段数
        dp[0] = 0;
        dp[1] = 1;
        const int INF = (1<<30);
        for (int i = 2; i <= n; i++) {
            dp[i] = INF;
            for (int j = 0; j < i; j++) {
                if (palindrome[j+1][i]) {
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        
        return dp[n]-1;
    }
};