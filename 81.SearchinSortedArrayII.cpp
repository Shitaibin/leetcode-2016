// 小心在重复的词rotate
// 因为分割之后，不容易确定它是旋转的数组还是正常的数组。
// 所以，每次跳过左边的重复。

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return nums[0] == target;
        }
        
        int low = 0, high = n-1;
        while (low <= high) {
            if (nums[low] < nums[high] && (target < nums[low] || target > nums[high])) {
                return false;
            }
            
            // skip duplicates
            while (low < high && nums[low] == nums[low+1]) {
                low++;
            }
            
            int mid = low + (high-low)/2;
            if (nums[mid] == target) {
                return true;
            }
            // the target in non-rotate array : left
            if (nums[low] < nums[mid] && target >= nums[low] && target < nums[mid]) {
                high = mid-1;
                continue;
            }
            // the target in non-rotate array: right
            if (nums[mid] < nums[high] && target > nums[mid] && target <= nums[high]) {
                low = mid+1;
                continue;
            }
            // the target in rotate array: left
            if (nums[mid] < nums[low]) {
                high = mid-1;
                continue;
            }
            // the target in rotate array:right
            if (nums[mid] < nums[high]) {
                low = mid+1;
                continue;
            }
            
            // reach here means nothing found
            low++;
            cout << "nothing found?!, but never execute!!!" << endl;
        }
        return false;
    }
};