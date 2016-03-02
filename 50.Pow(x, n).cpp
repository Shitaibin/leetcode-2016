/* n 可以是负数、0、正数。
 * n 可能是很大的负数，越界。
 */

// v1
class Solution {
public:
    double myPow(double x, int n) {
        int negative = n<0 ? 1 : 0;
        
        double tmp = x, result = 1.0;
        for (long long times = abs((long long)n); times>0; times/=2) {
            if (times%2) {
                result *= tmp;
            }
            tmp = tmp * tmp;
        }
        
        if (negative) {
            result = 1.0 / result;
        }
        
        return result;
    }
};

// v2
class Solution {
public:
    double myPow(double x, int n) {
        bool sign = false;
        unsigned int exp = n;
        if(n<0){
            exp = -n;
            sign = true;
        }
        double result = 1.0;
        while (exp) {
            if (exp & 1){
                result *= x;
            }
            exp >>= 1;
            x *= x;
        }
    
        return sign ? 1/result : result;
    }
};