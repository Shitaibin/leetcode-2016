// https://github.com/haoel/leetcode/blob/master/algorithms/cpp/singleNumber/singleNumber.II.cpp
/*
 *  This solution is clear & straightforward implementation.
 *  
 *  We use an array of 32 length(e.g. count[32]) to count the the bits for all of numbers. 
 *
 *  Because the same number appear 3 times, which means the sum of i-th bits for all numbers should be 3 times.
 *
 *  In other word, the sum of the i-th bits mod 3, it must be 0 or 1. 1 means that is the single number bit.
 *
 *  This solution can be easy to extend to "every element appears k times except for one."
 *
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};
        int ret = 0;
        for (int i = 0; i< 32; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] >> i) & 1) {
                    count[i]++;
                }
            }
            ret |= ((count[i] % 3) << i);
        }
        return ret;
    }
};