class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        if (nums.size() == 1) {
            return (nums[0] == target ? 0 : -1);
        }
        
        int l = 0, h = nums.size()-1;
        while (l <= h) {
            if (nums[l] <= nums[h] && (target < nums[l] || target > nums[h])) {
                return -1;
            }
            
            int mid = l + (h-l)/2;
            if (nums[mid] == target) return mid;
            
            // target in non-rorated array: left
            if (nums[l] < nums[mid] && target >= nums[l] && target <= nums[mid]) {
                h = mid-1;
                continue;
            }
            // target in non-rotated array: right
            if (nums[mid] < nums[h] && target >= nums[mid] && target <= nums[h]) {
                l = mid + 1;
                continue;
            }
            // target in rotate array: left part is rotate
            if (nums[l] > nums[mid]) {
                h = mid - 1;
                continue;
            }
            // target in rotate array: right part is roate
            if (nums[mid] > nums[h]) {
                l = mid + 1;
                continue;
            }
        }
        return -1;
    }
};