class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //if (nums.empty()) return;
        int cnt = 0;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cnt++;
            } else {
                nums[idx++] = nums[i];
            }
        }
        for (int i = nums.size() - cnt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};

// v2: https://github.com/haoel/leetcode/blob/master/algorithms/cpp/moveZeroes/moveZeroes.cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1, p2; // p1 the first zero's index, p2 the first non-zero's index after p1
        for (p1 = 0; p1 < nums.size() && nums[p1] != 0; p1++);
        for (p2 = p1+1; p2 < nums.size(); p2++) {
            if (nums[p2] != 0) {
                nums[p1++] = nums[p2];
            }
        }
        for ( ; p1 < nums.size(); p1++) {
            nums[p1] = 0;
        }
    }
};