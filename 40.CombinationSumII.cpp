// 两种状态：包含当前元素，不包含当前元素
class Solution {
private:
    void combinationSum2Helper(vector<int> &candidates, int start, int target, vector<int> &solution, vector<vector<int>> &result) {
        if (target < 0) {
            return ;
        }
        if (target == 0) {
            result.push_back(solution);
        }
        for (int i = start; i < candidates.size(); i++) {
            // skip duplicates
            // 避免重复解
            if (i > start && candidates[i-1]==candidates[i]) {
                continue;
            }
            solution.push_back(candidates[i]); //包含当前当前元素的结果
            combinationSum2Helper(candidates, i+1, target-candidates[i], solution, result); //每个元素只使用1次
            solution.pop_back(); //不包含当前元素的结果
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if (candidates.empty()) {
            return result;
        }

        sort(candidates.begin(), candidates.end());

        vector<int> solution;
        combinationSum2Helper(candidates, 0, target, solution, result);
        return result;
    }
};