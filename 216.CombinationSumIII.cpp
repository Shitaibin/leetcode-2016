// 第一次写完后并不是bugfree，是RUNTIME ERROR
// 但我调试了很久没有发现错误，后来从写了Helper，过掉。
// 这说明，如果这段代码很短，并且有错误，可你就是找不到。
// 所以，重写。
// 
// solution用不用引用是0ms与3ms的区别
class Solution {
    void combinationSum3Helper(vector<int>& nums, int start, int k, int n,
                                vector<int>& solution, vector<vector<int>>& result) {
        if (k == 0 && n == 0) {
            result.push_back(solution);
        }
        else if (k > 0 && n > 0) {
            if (n < nums[start]) return;
            
            for (int i = start; i < nums.size(); i++) {
                solution.push_back(nums[i]);
                combinationSum3Helper(nums, i+1, k-1, n-nums[i], solution, result);
                solution.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for (int i = 1; i <= 9; i++) {
            nums.push_back(i);
        }

        vector<vector<int>> result;
        vector<int> solution;
        combinationSum3Helper(nums, 0, k, n, solution, result);
        return result;
    }
};