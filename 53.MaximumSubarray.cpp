class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int largest_sum = nums[0];
        int cur_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            if (cur_sum > largest_sum) {
                largest_sum = cur_sum;
            }
            if (cur_sum < 0) {
                cur_sum = 0;
            } 
        }
        return largest_sum;
    }
};