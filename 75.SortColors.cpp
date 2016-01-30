class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3] = {0};
        
        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
        }
        
        int i = 0, end = 0;
        for (int c = 0; c < 3; c++) {
            end += counts[c];
            for (; i < end; i++) {
                nums[i] = c;
            }
        }
    }
};