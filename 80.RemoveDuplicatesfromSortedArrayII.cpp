class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
            
        int l = 1;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[l] && nums[i] == nums[l-1]) {
                continue;
            }
            nums[++l] = nums[i];
        }
        return l+1;
    }
};