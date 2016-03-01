// v1: backtracking
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


// v2:
// https://github.com/haoel/leetcode/blob/master/algorithms/cpp/permutations/permutations.cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(nums);
        
        if (nums.size() < 2) {
            return result;
        }
        
        for (int pos = 0; pos < nums.size()-1; pos++) {
            int result_size = result.size();
            for (int i = 0; i < result_size; i++) {
                vector<int> v = result[i];
                //take each number to the first place
                for (int j = pos+1; j < v.size(); j++) {
                    swap(v[j], v[pos]);
                    result.push_back(v);
                }
            }
        }
        return result;
    }
};