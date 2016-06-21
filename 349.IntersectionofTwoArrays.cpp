// 公司：未知

// Given two arrays, write a function to compute their intersection.

// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

// Note:
// Each element in the result must be unique.
// The result can be in any order.



// 排序加两个指针:O(NlogN)
// 排序复杂度你懂的，所以。。。
// 如果数据具有范围，可以考虑使用O(N)的排序方法。都可以不排序了，
// 直接使用统计，开两个统计数组，在两个统计数组中都出现的，必然
// 是交集。
class Solution {
    int next(vector<int> nums, int i) {
        i++;
        while (i < nums.size() && nums[i-1] == nums[i]) i++;
        return i;
    }
    
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> inter;
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size(); ) {
            if (nums1[i] == nums2[j]) {
                inter.push_back(nums1[i]);
                i = next(nums1, i);
                j = next(nums2, j);
            } else if (nums1[i] < nums2[j]) {
                // move i
                i = next(nums1, i);
            } else {
                // move j
                j = next(nums2, j);
            }
        }
        return inter;
    }
};


// 集合：O(NlogN)
// 集合使用红黑树实现，所以效率。。。
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for (int i = 0; i < nums1.size(); i++) {
            s.insert(nums1[i]);
        }
        
        set<int> ret;
        for (int i = 0; i < nums2.size(); i++) {
            if (s.find(nums2[i]) != s.end()) {
                ret.insert(nums2[i]);
            }
        }
        
        vector<int> x;
        for (auto it = ret.begin(); it != ret.end(); it++) {
            x.push_back(*it);
        }
        return x;
    }
};