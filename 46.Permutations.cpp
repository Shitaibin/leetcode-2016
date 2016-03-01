class Solution {
private:
    void permuteHelper(vector<int> &nums, vector<int> &solution, vector<vector<int>> &result) {
        if (nums.empty()) {
            // got a solution
            result.push_back(solution);
            return;
        }
        
        for (auto it = nums.begin(); it != nums.end(); it++) {
            solution.push_back(*it);
            vector<int> left_nums(nums);
            left_nums.erase(left_nums.begin() + (it-nums.begin())); //bug
            permuteHelper(left_nums, solution, result);
            solution.pop_back();
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) 
            return result;

        vector<int> solution;
        permuteHelper(nums, solution, result);
        return result;
    }
};