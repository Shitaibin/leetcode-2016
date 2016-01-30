class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        n -= 2;
        int a = 1, b = 2, s;
        while (n--) {
            s = a + b;
            a = b;
            b = s;
        }
        return s;
    }
};