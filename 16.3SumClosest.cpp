class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int distance = INT_MAX;
        int result;
        
        for (int i = 0; i < n-2;  i++) {
            // skip the duplication
            if (i>0 && nums[i-1] == nums[i]) continue;
            
            int low = i+1;
            int high = n-1;
            // convert the 3sum to 2sum problem
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                
                if (sum-target == 0) {
                    // get the final solution
                    return target;
                } else {
                    // tracking the minmal distance
                    if (abs(sum-target) < distance) {
                        distance = abs(sum-target);
                        result = sum;
                    }
                    
                    if (sum-target > 0) {
                        // skip the duplication
                        while (high>low && nums[high] == nums[high-1]) high--;
                        // move the high pointer
                        high--;
                    } else {
                        while (low<high && nums[low] == nums[low+1]) low++;
                        low++;
                    }
                }
            }
        }
        return result; // error1: return in for loop
    }
};