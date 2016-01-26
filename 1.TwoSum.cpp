/*
 * 1. 可能存在重复值。
 * 2. 数组不一定有序。
 * 3. 使用二分搜索。
 * 4. 使用multimap代替结构体和排序，效率降低。
 */


struct _nums_index {
	int val;
	int old_index;
	_nums_index (int v, int o) : val(v), old_index(o) {}
};

int cmp(const _nums_index &a, const _nums_index &b) {
	return a.val < b.val;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<_nums_index> nums_index;
		for (int i=0; i<nums.size(); ++i) {
			nums_index.push_back(_nums_index(nums[i], i+1));
		}
		
		sort(nums_index.begin(), nums_index.end(), cmp);
	
		vector<int> ret;	
		for (int i=0, j=nums_index.size()-1; i<=j; ) {
			int sum = nums_index[i].val + nums_index[j].val;
			if (sum == target) {
				ret.push_back(nums_index[i].old_index);
				ret.push_back(nums_index[j].old_index);
				break;
			} else if (sum < target) {
				++i;
			} else {
				--j;
			}
		}
		
		sort(ret.begin(), ret.end());
		return ret;
    }
};