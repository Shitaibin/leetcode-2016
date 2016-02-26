class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.empty()) return ret;
        
        int start = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1] + 1) {
                continue;
            } else {
                int end = nums[i-1];
                ret.push_back(makeRange(start, end));
                start = nums[i];
            }
        }
        ret.push_back(makeRange(start, nums.back()));
        return ret;
    }
    
    string makeRange(int start, int end) {
        ostringstream oss;
        if (start == end) {
            oss << start;
        } else {
            oss << start << "->" << end;
        }
        return oss.str();
    }
};