class Solution {
private:
    void combinationSumHelper(vector<int> &candidates, int start, int target, vector<int> &solution, vector<vector<int>> &result) {
        if (target < 0) {
            return ;
        }
        if (target == 0) {
            result.push_back(solution);
        }
        for (int i = start; i < candidates.size(); i++) {
            // skip duplicates
            if (i > start && candidates[i-1]==candidates[i]) {
                continue;
            }
            solution.push_back(candidates[i]); //包含当前当前元素的结果
            combinationSumHelper(candidates, i, target-candidates[i], solution, result); //当前数值可以重复多次，所以仍从i开始
            solution.pop_back(); //不包含当前元素的结果
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) {
            return result;
        }

        sort(candidates.begin(), candidates.end());

        vector<int> solution;
        combinationSumHelper(candidates, 0, target, solution, result);
    }
};