class Solution {
private:
    vector<vector<int>> threeSum(vector<int>& nums, int target) {
        vector<vector<int>> rets;
        if (nums.size() < 3)
            return rets;
        
        sort(nums.begin(), nums.end());
        int cur_pos = 0;
        while (cur_pos < nums.size() - 2) {
            int start = cur_pos + 1, end = nums.size()-1;
            while (start < end) {
                int sum = nums[cur_pos] + nums[start] + nums[end];
                if (sum == target) {
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
                } else if (sum > target) {
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
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if (nums.size() < 4) return ret;
        
        sort(nums.begin(), nums.end());
        // transform 4Sum to 3Sum problem
        for (int i = 0; i < nums.size()-3; i++) {
            // skip the duplication
            if (i > 0 && nums[i-1] == nums[i]) continue;
            vector<int> t(nums.begin()+i+1, nums.end());
            vector<vector<int>> result = threeSum(t, target-nums[i]);
            for (int j = 0; j < result.size(); j++) {
                result[j].insert(result[j].begin(), nums[i]);
                ret.push_back(result[j]);
            }
        }
        return ret;
    }
};