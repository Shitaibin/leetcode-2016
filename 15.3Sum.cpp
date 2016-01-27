/**
 * 1. 越界：a+b越界，a+b+c正常。如a，b为正，c为负。没遇到。
 * 2. 复杂度。超时。
 * 3. 不足3个元素。
 */


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rets;
        if (nums.size() < 3)
            return rets;
        
        sort(nums.begin(), nums.end());
        int cur_pos = 0;
        while (cur_pos < nums.size() - 2) {
            int start = cur_pos + 1, end = nums.size()-1;
            while (start < end) {
                int sum = nums[cur_pos] + nums[start] + nums[end];
                if (sum == 0) {
                    vector<int> t;
                    t.push_back(nums[cur_pos]);
                    t.push_back(nums[start]);
                    t.push_back(nums[end]);
                    rets.push_back(t);
                    
                    ++start;
                    --end;
                    while (start < end && nums[start] == nums[start - 1])
                        ++start;
                    while (end > start && nums[end] == nums[end + 1])
                        --end;
                } else if (sum > 0) {
                    --end;
                } else {
                    ++start;
                }
            }
            ++cur_pos;
            while (cur_pos < nums.size()-2 && nums[cur_pos] == nums[cur_pos-1])
                ++cur_pos;
        }
        return rets;
    }
};