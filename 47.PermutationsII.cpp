class Solution {
    void permuteUniqueHelper(vector<int>& nums, vector<int>& solution, vector<vector<int>>& result) {
        if (nums.empty()) {
            result.push_back(solution);
            return;
        }
        
        for (auto it = nums.begin(); it != nums.end(); it++) {
            // make sure it is valid, or RUNTIME ERROR
            if (it != nums.begin() && *it == *(it-1)) {
                continue;
            }
            
            solution.push_back(*it);
            vector<int> clone_nums(nums);
            clone_nums.erase( clone_nums.begin() + (it - nums.begin()) );
            permuteUniqueHelper(clone_nums, solution, result);
            solution.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        vector<int> solution;
        permuteUniqueHelper(nums, solution, result);
        return result;
    }
};

// v2: faster
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(nums);
        
        if (nums.size() < 2) {
            return result;
        }
        
        // pos is the first place 
        for (int pos = 0; pos < nums.size(); pos++) {
            int result_size = result.size();
            for (int i = 0; i < result_size; i++) {
                sort(result[i].begin()+pos, result[i].end());
                for (int j = pos+1; j < result[i].size(); j++) {
                    // do not take it out, each we should make a new copy
                    vector<int> v(result[i]);
                    // skip duplicates
                    if (j>0 && v[j] == v[j-1]) {
                        continue;
                    }
                    // swap with the first place
                    swap(v[pos], v[j]);
                    result.push_back(v);
                }
            }
        }
        
        return result;
    }
};