/* X^X = 0
 * X^0 = X
 * 对整个数组进行异或得到的是 X^Y，X，Y分别是出现一次的数字。
 * 找到X^Y为1的某个位，那么X和Y必然在此位一个为0，一个为1，
 * 根据此位可以将所有的数字分成两个不同的组，分别进行异或就
 * 可以得到X和Y。
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int allxor = 0;
        for (int e : nums) {
            allxor ^= e;
        }
        int mask = 1;
        while ((mask & allxor) == 0) {
            mask <<= 1;
        }
        
        // divide to two group numbers
        int zero = 0;
        int one = 0;
        for (int e : nums) {
            if (mask & e) {
                one ^= e;
            } else {
                zero ^= e;
            }
        }
        vector<int> ret;
        ret.push_back(zero);
        ret.push_back(one);
        return ret;
    }
};