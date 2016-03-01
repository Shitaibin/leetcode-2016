class Solution {
private:
    void permuteUniqueHelper(vector<int> &nums, vector<int> &solution, vector<vector<int>> &result) {
        if (nums.empty()) {
            // got a solution
            result.push_back(solution);
            return;
        }
        
        for (auto it = nums.begin(); it != nums.end(); it++) {
            // skip duplications
            // if (it != nums.begin() && *(it-1) == *it) {
            //     continue;
            // }
            
            // solution.push_back(*it);
            // vector<int> left_nums(nums);
            // left_nums.erase(left_nums.begin() + (it-nums.begin())); 
            if (i>0 && nums[i-1] == nums[i]) {
                continue;
            }
            
            solution.push_back(nums[i]);
            vector<int> left_nums(nums);
            left_nums.erase(left_nums.begin() + i);
            permuteUniqueHelper(left_nums, solution, result);
            solution.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) 
            return result;

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
        vector<vector<int> > result;
        result.push_back(nums);
    
        if (nums.size() <2){
            return result;
        }
            
        int pos=0;
        while(pos<nums.size()-1){
            int size = result.size();
            for(int i=0; i<size; i++){
                //sort the array, so that the same numsber will be together
                sort(result[i].begin()+pos, result[i].end());
                //take each numsber to the first
                for (int j=pos+1; j<result[i].size(); j++) {
                    vector<int> v = result[i]; // put this out of for loop will make TLE! Why?
                    //skip the same numsber 
                    if (j>0 && v[j]==v[j-1]){
                        continue;
                    }
                    swap(v[j], v[pos]);
                    result.push_back(v);
                }
            }
            pos++;
        }
        return result;
    }
};