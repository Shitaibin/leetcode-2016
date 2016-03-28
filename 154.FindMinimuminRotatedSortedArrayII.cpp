class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int high = nums.size()-1;
        // skip duplicates
        while (high > 0 && nums[high] == nums[0]) {
            high--;
        }
        // sorted
        if (nums[0] < nums[high]) {
            return nums[0];
        }
        
        // rotated
        int low = 0;
        while (low < high-1) {
            // skip duplicates
            while (low < high-1 && nums[low] == nums[low+1]) {
                low++;
            }
            // skip duplicates
            while (low < high-1 && nums[high] == nums[high-1]) {
                high--;
            }
            
            if (low < high-1) {
                int mid = low + (high-low)/2;
                if (nums[mid] > nums[low]) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            
        }
        return nums[high];
    }
};