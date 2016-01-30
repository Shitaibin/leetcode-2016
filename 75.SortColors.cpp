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


// v2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int red_end = -1, blue_front = n, cur = 0;
        
        while (cur < blue_front) {
            if (cur >= blue_front) break;
            if (cur > red_end && nums[cur] == 0) {
                swap(nums[++red_end], nums[cur]);
            } else if (cur < blue_front && nums[cur] == 2) {
                swap(nums[--blue_front], nums[cur]);
            } else {
                cur++;
            }
        }
    }
};