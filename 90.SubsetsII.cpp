// 使用最朴素的回溯

class Solution {
private:
    vector<vector<int> > combine(vector<int> &nums, int k) {
        vector<vector<int> > result;
        vector<int> solution;
        int n = nums.size();
        getCombination(nums, n, 0, k, solution, result);
        return result;
    }

    void getCombination(vector<int> &nums, int n, int start, int k, vector<int>& solution, vector<vector<int> > &result) {
        if (k == 0) {
            // got a solution
            result.push_back(solution);
            return;
        }
        
        for (int i = start; i < n; i++) {
            solution.push_back(nums[i]);
            getCombination(nums, n, i+1, k-1, solution, result);
            solution.pop_back();
            // skip duplication
            while (i < n-1 && nums[i+1] == nums[i]) {
                i++;
            }
        }
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> >result;
        sort(nums.begin(), nums.end());
        for (int i=0; i<=nums.size(); i++) {
            vector<vector<int> > r = combine(nums, i);
            result.insert(result.end(), r.begin(), r.end());
        }
        return result;
    }
};