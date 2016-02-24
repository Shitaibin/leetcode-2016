class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto it_left = nums.begin();
        k = nums.size()-k%nums.size();
        while (k--) {
            it_left++;
        }
        reverse(nums.begin(), it_left);
        reverse(it_left, nums.end());
        reverse(nums.begin(), nums.end());
    }
};