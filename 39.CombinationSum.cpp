// 两种状态：包含当前元素，不包含当前元素
// 测试发现，[2,2]6,得到的结果是[[2,2,2],[2,2,2],[2,2,2],[2,2,2]]
// 说明测试程序是没有去重的。或者说测试case都是无重复的数字。
class Solution {
private:
    void combinationSumHelper(vector<int>& candidates, int start, int target, vector<int> &solution, vector<vector<int>>& result) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            result.push_back(solution);
            return; // We got a solution, If we not return here, it will go deeper.
            // In deeper level, it will also check this block, and add solutions,
            // So, it leads to bug
        }
        
        // Solution 2:
        // for (int i = start; i < candidates.size(); i++) {
        //     solution.push_back(candidates[i]);
        //     combinationSumHelper(candidates, i, target-candidates[i], solution, result);
        //     solution.pop_back();
        // }
        
        // Solution 1: bug, has duplicates
        // Fixed in line 9
        if (start < candidates.size()) {
            // With
            solution.push_back(candidates[start]);
            combinationSumHelper(candidates, start, target-candidates[start], solution, result);
            solution.pop_back();
            
            // Without it
            // Skip duplicates
            while (start < candidates.size()-1 && candidates[start+1] == candidates[i]) start++;
            combinationSumHelper(candidates, start+1, target, solution, result);
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
        return result;
    }
};