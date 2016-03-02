// backtracking, BUT TLE
// greedy, Accept

// v1: backtracking, BUT TLE
class Solution {
private:
    bool canJumpHelper(vector<int>& nums, int start, int end) {
        if (start == nums.size()-1) {
            return true;
        }
        if (nums[start] == 0) {
            return false;
        }
        for (int i=start; i<=end; i++) {
            // if this is not the right next, try another next
            if (canJumpHelper(nums, start+1, start+nums[start])) {
                return true;
            }
        }
        // none right next
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
         if (nums.empty()) return false;
         return canJumpHelper(nums, 0, nums[0]);
    }
};

// v2: greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false;
        
        // the basic idea is traverse array, maintain the most far can go
        int coverPos = 0;
        // the condition i<=coverPos means traverse all of covered position 
        for (int i = 0; i <= coverPos && i<nums.size(); i++) {
            if (coverPos < nums[i]+i) {
                coverPos = nums[i]+i;
            }
            if (coverPos >= nums.size()-1) {
                return true;
            }
        }
        return false;
    }
};