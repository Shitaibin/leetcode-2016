/**
 * 1. 越界：就算越界，得到的值与x不同。
 * 2. 负数：不对称。
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int t = x, ret = 0;
        while (x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        
        return ret == t;
    }
};