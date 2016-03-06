// trick
// v2: iterative
// https://github.com/haoel/leetcode/blob/master/algorithms/cpp/combinations/combinations.cpp#L77
// 不适合用在重复元素中，因此90题，不使用此方案，使用最原始的回溯
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> d; //map
        
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
                    solution.push_back(i+1);
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
};

// v1: backtracking, very slow
class Solution {
private:
    void combineHelper(vector<int> v, int left, int start, vector<int> solution, vector<vector<int> > &result){
        if (left == 0) {
            result.push_back(solution);
        }
        // using `start` can skip duplicate combinations
        // always take numbers after start, not all left numbers
        for (int i = start; i < v.size(); i++) {
            solution.push_back(v[i]);
            combineHelper(v, left-1, i+1, solution, result); 
            solution.pop_back();
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        if (n == 0 || k == 0) {
            return result;
        }
        
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
        }
        
        vector<int> solution;
        combineHelper(v, k, 0, solution, result);
        return result;
    }
};