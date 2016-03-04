// v1: backtracking
// v2: using 78.Problem Combinations, iterative

// v1: backtracking
class Solution {
private:
    void subsetsHelper(vector<int>& nums, int start, int size, vector<int> solution, vector<vector<int>>& result) {
        if (size == 0) {
            result.push_back(solution);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            solution.push_back(nums[i]);
            subsetsHelper(nums, i+1, size-1, solution, result);
            solution.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> solution;
        // empty set
        result.push_back(solution);
        
        if (nums.size() <= 0) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        for (int sub_size = 1; sub_size <= n; sub_size++) {
            // using backtracking, get all subset, which size is sub_size
            subsetsHelper(nums, 0, sub_size, solution, result);
        }
        return result;
    }
};

// v2: using 78.Problem Combinations, iterative
class Solution {
private:
    vector<vector<int>> combine(vector<int>& nums, int k) {
        vector<vector<int>> result;
        vector<int> d; //map
        
        int n = nums.size();
        
        // initial solution
        for (int i = 0; i < n; i++) {
            d.push_back( (i<k) ? 1 : 0 );
        }
        
        //1) from the left, find the [1,0] pattern, change it to [0,1]
        //2) move all of the 1 before the pattern to the most left side
        //3) check all of 1 move to the right
        while (1) {
            // get current solution
            vector<int> solution;
            for (int i = 0; i<n; i++) {
                if (d[i]) {
                    // solution.push_back(i+1);
                    solution.push_back(nums[i]);
                }
            }
            result.push_back(solution);
            
            // try to found next solution
            // step 1), find [1,0] pattern
            bool found = false;
            int ones = 0;
            for (int i = 0; i<n-1; i++) {
                if (d[i]==1 && d[i+1]==0) {
                    d[i] = 0;
                    d[i+1] = 1;
                    found = true;
                    // step 2) move all of right 1 before i to the most left side
                    for (int j = 0; j<i; j++) {
                        d[j] = (ones > 0) ? 1 : 0;
                        ones--;
                    }
                    break; // go to next solution
                }
                if (d[i] == 1) ones++;
            }
            
            if (!found) {
                // end
                break;
            }
        }
        return result;
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> solution;
        // empty set
        result.push_back(solution);
        
        if (nums.size() <= 0) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int sub_size = 1; sub_size <= nums.size(); sub_size++) {
            // using backtracking, get all subset, which size is sub_size
            vector<vector<int>> subs = combine(nums, sub_size);
            // extend result: put sub in subs to result
            result.insert(result.end(), subs.begin(), subs.end());
        }
        return result;
    }
};