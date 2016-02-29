// v1: iteration
class Solution {
private:
    int searchLeft(vector<int>& nums, int l, int r, int val) {
        while (l < r) {
            int m = l + (r-l)/2;
            if (nums[m] < val) {
                l = m+1;
            } else {
                r = m; // not using m-1
            }
        }
        return l;
    }
    
    int searchRight(vector<int>& nums, int l, int r, int val) {
        while (l < r) {
            int m = (l+r) /2;
            if (nums[m] > val) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        if (nums[l] == val) {
            return l;
        } else {
            return l-1;
        }
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        if (nums.empty()) {A
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        
        int l = 0, r = nums.size()-1;
        int m;
        while (l <= r) {
            m = (l+r) /2;
            if (nums[m] == target) {
                ret.push_back(searchLeft(nums, l, m, target));
                ret.push_back(searchRight(nums, m, r, target));
                return ret;
            }
            if (nums[m] < target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        
        
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
    }
    
};

// v2: recursive
class Solution {
private:
    int binary_search(vector<int>& nums, int l, int r, int val) {
        while (l <= r) {
            int m = l + (r-l)/2;
            if (nums[m] == val) {
                return m;
            }
            if (nums[m] > val) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = binary_search(nums, 0, nums.size()-1, target);
        
        int low = -1, high = -1;
        if (pos != -1) {
            low = high = pos;
            int l = low;
            do {
                low = l;
                l = binary_search(nums, 0, low-1, target);
            } while (l != -1);
            
            int h = high;
            do {
                high = h;
                h = binary_search(nums, high+1, nums.size()-1, target);
            } while (h != -1);
        }
        
        vector<int> ret;
        ret.push_back(low);
        ret.push_back(high);
        return ret;
    }
};