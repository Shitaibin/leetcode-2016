class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        // not rotate
        if (nums.front() < nums.back()) {
            return nums[0];
        }
        
        // rotate
        int low = 0, high = nums.size()-1;
        while (low < high-1) {
            int mid = low + (high-low)/2;
            if (nums[mid] > nums[low]) { // search right
                low = mid;
            } else {
                high = mid; // search left
            }
        }
        return nums[high];
    }
};