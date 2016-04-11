
// 公司：未知

// 初看像LIS的变形，但使用LIS的DP解法，运行时间600+。
// 使用LIS的“贪心策略”，也有O(NlogN)的复杂度。
// 使用贪心策略的变形，可以将复杂度降到O(N)。
// 使用min与mid两个变量，记录执行到当前位置的最小值和比
// 最小值稍大的值（除min之外的最小值）。
// 当遇到新min时，更新min而没有更新mid，意味着，我还
// 保留了之前的数据，如果出现大于mid的值，就得到了一个
// 递增三元组。

// 其实这也是DP加贪心的问题。

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX;
        int mid = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < min) {
                min = nums[i];
            }
            else if (nums[i] > min) {
                if (nums[i] > mid) return true;
                else mid = nums[i];
            }
        }
        return false;
    }
};