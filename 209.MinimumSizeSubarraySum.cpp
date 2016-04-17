// 公司：未知


// v1:使用两个指针。
// v2:使用二分搜索。效率不高，但为了看如何从无序序列使用二分搜索，尝试了一下。
需要根无序的数据构建有序的序列，才能使用二分搜索。
构建一个数组，存放从开始位置到当前的和，该数据升序。
从每个位置，向前二分搜索，
计算sum[mid+1, i]，因为不包含mid，当mid等于0时，我们会漏掉数据，
因此在sum前边插入一个0.


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



// v2: O(NlogN)。
// 二分搜索
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int n = nums.size();
        vector<int> sum(nums);
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i-1] + nums[i];
        }
        sum.insert(sum.begin(), 0);
        
        int min_len = n + 1;
        for (int i = 1; i <= n; i++) {
            if (sum[i] >= s) {
                int beg = 0, end = i;
                while (beg <= end) {
                    int mid = beg + (end - beg) / 2;
                    if (sum[i] - sum[mid] >= s) {
                        min_len = min((i - mid), min_len);
                        beg = mid + 1;
                    }
                    else {
                        end = mid - 1;
                    }
                }
            }
        }
        return (min_len == (n + 1) ? 0 : min_len);
    }
};