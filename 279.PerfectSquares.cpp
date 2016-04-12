// 公司：Google
// 
// 马上想到了Coin Change，就这样得到了v1，O(N^2)。但从结果来看，效率太低。
// 
// 想了好久好久，以为要改用其他算法才能满足要求，看了耗子的方法，使用
// cache就使得算法得到了极大的改善。
// 
// v1:588 ms
// v2:16 ms
// v3:12 ms
// 
// 耗子没有使用square来维护square number，反而获得了更好的结果，
// 在使用cache的情况下，再还使用square，维护代价增高了，所以应当去掉。

// v3: 耗子的。
class Solution {
public:
    int numSquares(int n) {
        if ( n <=0 ) return 0;
        
        static vector<int> dp(1, 0);
        if (dp.size() >= (n+1) ) return dp[n];
        
        for (int i=dp.size(); i<=n; i++ ) {
            int m = n;
            for (int j=1; i-j*j >= 0; j++) {
                m = min (m, dp[i-j*j] + 1);
            }
            dp.push_back(m);
        }
        return dp[n];
    }
};



// v2: O(N^2)。using cache to optimize DP。
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp(1, 0);
        if (dp.size() >= (n+1)) return dp[n];
        
        const int INF = (1<<30);
        int sqrt_n = floor(sqrt(n));
        static vector<int> squares;
        
        // update squares
        for (int i = (squares.size()+1); i <= sqrt_n; i++) {
            squares.push_back(i*i);
        }
        
        // update dp
        for (int i = dp.size(); i <= n; i++) {
            int m = INF;
            for (int j = 0; j < sqrt_n; j++) {
                if (i >= squares[j])
                    m = min(m, dp[i-squares[j]] + 1);
                else break;
            }
            dp.push_back(m);
        }
        return dp[n];
    }
};

// v1:O(n^2)
class Solution {
public:
    int numSquares(int n) {
        const int INF = (1<<30);
        int sqrt_n = floor(sqrt(n));
        vector<int> squares;
        
        // create `coins`
        for (int i = 1; i <= sqrt_n; i++) {
            squares.push_back(i*i);
        }
        
        // dp[i] = min{dp[i-squares[j]]+1}, i>=squares[j]
        // j <- 0 to sqrt_n
        vector<int> dp(n+1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = INF;
            for (int j = 0; j < sqrt_n; j++) {
                if (i >= squares[j]) {
                    dp[i] = min(dp[i], dp[i-squares[j]] + 1);
                }
            }
        }
        return dp[n];
    }
};