class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        long long nsum = n * (n+1) / 2;
        for (int i = 0; i < n; i++) {
            nsum -= nums[i];
        }
        return nsum;
    }
};