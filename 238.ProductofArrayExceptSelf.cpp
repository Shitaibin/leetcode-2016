class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(len, 1);
        
        // result from left to right
        // now result is not include nums[i]
        for (int i = 1; i < len; i++) {
            result[i] = result[i-1] * nums[i-1];
        }
        
        // from right to left
        int fact = 1;
        for (int i = len-2; i >= 0; i--) {
            fact *= nums[i+1];
            result[i] *= fact;
        }
        
        return result;
    }
};