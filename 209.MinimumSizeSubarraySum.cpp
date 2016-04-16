

// v1: O(N)。看Tag后才做出来的。
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int n = nums.size();
        if (n == 0) return 0;
        
        int sum = nums[0], min_len = n+1;
        for (int i = 0, j = 0; i < n && j <= i; ) {
            if (sum >= s) {
                min_len = min(min_len, (i - j + 1));
                sum -= nums[j++];
            }
            else {
                sum += nums[++i];
            }
        }
        return (min_len == (n + 1) ? 0 : min_len);
    }
};