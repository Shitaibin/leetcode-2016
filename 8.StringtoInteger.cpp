/**
 * 关键在越界的判断
 */

class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;

        int i;
        for (i=0; i<str.size() && str[i] == ' '; ++i);
        
        if (i == str.size())
            return 0;
            
        if (str[i] == '+') {
            ++i;
        } else if (str[i] == '-') {
            sign = -1;
            ++i;
        }
        
        long ret = 0;
        for (; i<str.size() && isdigit(str[i]); ++i) {
            ret = ret * 10 + str[i] - '0';
            // overflow
            if (ret > INT_MAX) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
        }
        
        return sign * ret;
    }
};