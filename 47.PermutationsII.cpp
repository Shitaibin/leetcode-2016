class Solution {
private:
    void permuteUniqueHelper(vector<int> &nums, vector<int> &solution, vector<vector<int>> &result) {
        if (nums.empty()) {
            // got a solution
            result.push_back(solution);
            return;
        }
        
        for (auto it = nums.begin(); it != nums.end(); it++) {
            // skip duplications
            // if (it != nums.begin() && *(it-1) == *it) {
            //     continue;
            // }
            
            // solution.push_back(*it);
            // vector<int> left_nums(nums);
            // left_nums.erase(left_nums.begin() + (it-nums.begin())); 
            if (i>0 && nums[i-1] == nums[i]) {
                continue;
            }
            
            solution.push_back(nums[i]);
            vector<int> left_nums(nums);
            left_nums.erase(left_nums.begin() + i);
            permuteUniqueHelper(left_nums, solution, result);
            solution.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) 
            return result;

        sort(nums.begin(), nums.end());
        vector<int> solution;
        permuteUniqueHelper(nums, solution, result);
        return result;
    }
};