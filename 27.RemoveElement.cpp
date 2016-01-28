/**
 * 减少不必要的移动
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i, j;
        i = 0, j = nums.size() - 1;
        while (i<=j) {
            while (j >= i && nums[j] == val) --j;
            while (i <= j && nums[i] != val) ++i;
            if (i < j) nums[i++] = nums[j--]; //i<j时，一定不存在越界
        }
        return j+1;
    }
};