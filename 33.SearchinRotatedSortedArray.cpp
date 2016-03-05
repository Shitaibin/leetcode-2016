// https://github.com/haoel/leetcode/blob/master/algorithms/cpp/searchInRotatedSortedArray/searchInRotatedSortedArray.cpp

/*
 *    Using binary search idea, 
 *    1) Spliting the array to two part, one part should be non-rotated, another one is rotated.
 *    2) Checking the "key" whether is possible in non-rotated sorted part.
 *        2.1) if it is, then go to the classcial binary searh.
 *        2.2) if it not, then keep spliting the rorated part.
 *
 */
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