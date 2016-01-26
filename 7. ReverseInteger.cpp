/**
 * 1. 越界
 */

class Solution {
public:
    int reverse(int x) {
        int positive = 1;
        if (x < 0) {
            positive = -1;
            x = -x;
        }
            
        long long ret = 0;
        while (x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        
        ret *= positive;
        
        int final_ret = (int)ret;
        if (final_ret != ret) 
            return 0;
        return final_ret;
    }
};