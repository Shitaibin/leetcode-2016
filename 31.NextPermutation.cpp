/*
 * 样例数据太少，试一下1234的变化，这样才方便找规律，3个数字太狭隘了。
 * 
 * 规律：
 *  1) 从后向前找nums[i-1] < nums[i]
 *  2) 从n-1到i找第一个j，nuns[j] > nums[i-1]
 *  3) swap(nums[i], nums[j])
 *  4) 对子数组[i, n)排序。
 *
 * 边界：nums为逆序，即找不到满足1)的i。
 */
 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) 
            return;
        int n = nums.size();
        for (int i = n-1; i > 0; i--) {
            if (nums[i-1] < nums[i]) {
                int j;
                for (j = n-1; j > i && nums[j] <= nums[i-1]; j--) {}
                swap(nums[i-1], nums[j]);
                sort(nums.begin()+i, nums.end());
                return;
            }
            // edge case
            if (i == 1) {
                sort(nums.begin(), nums.end());
                return;
            }
        }
    }
};