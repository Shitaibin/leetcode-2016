/**
 * 二分搜索。
 * l = r时时关键。
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l, r, m;
        l = 0, r = nums.size()-1;
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        
        if (l == r) {
            if (nums[l] == target) return l;
            else if (nums[l] < target) return l+1;
            else return l;
        }
    }
};