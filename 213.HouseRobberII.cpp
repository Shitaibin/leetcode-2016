// 公司：未知

// 把圆化成直线，
// 要么考虑第一个，不考虑最后一个
// 要么考虑最后一个，不考虑第一个

class Solution {
    int rob_in_line(vector<int> nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        
        int n1 = nums[0];
        int n2 = 0;
        for (int i = 2; i <= n; i++) {
            int cur = max(n1, n2 + nums[i-1]);
            n2 = n1;
            n1 = cur;
        }
        return n1;
    }
    
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int rob_with_1 = rob_in_line(vector<int>(nums.begin(), nums.end()-1));
        int rob_with_n = rob_in_line(vector<int>(nums.begin()+1, nums.end()));
        return max(rob_with_1, rob_with_n);
    }
};