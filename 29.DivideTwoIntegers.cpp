class Solution {
public:
    int divide(int dividend, int divisor) {
        int positive = 1;
        if (((dividend>>31)&1) != ((divisor>>31)&1)) {
            positive = -1;
        }
        long long a = abs((long long)dividend); // care: 越界
        long long b = abs((long long)divisor);
        cout << a << " " << b << endl;
        long long ret = positive * do_divide(a, b); // care：越界
        if (ret > INT_MAX || ret < INT_MIN) {
            return INT_MAX;
        }
        return ret;
    }
    
    long long do_divide(long long dividend, long long divisor) {
        long long ret = 0;
        cout << dividend << " " << divisor << endl;
        while (dividend >= divisor) {
            // 如果一次一次减太慢了，使用指数试的方法，分别减去divisor的2,4,8.。倍，如果太大， 再从新开始，知道dividend为余数
            for (long long pow = 0; (divisor << pow) <= dividend; pow++) {
                dividend -= (divisor << pow);
                ret += (1 << pow);
            }
        }
        return ret;
    }
};