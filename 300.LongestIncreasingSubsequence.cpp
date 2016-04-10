// 最长递增子数列

// O(N^2)
// dp[i] = max{dp[j]+1 | [i] > [j], 0<=j<i}
// result: max{dp[i] | 0<=i<n}

class Solution {
    static const int bufsize = 10000;
    int dp[bufsize];
    
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return n;
        
        dp[0] = 1;
        int max_len = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            max_len = max(max_len, dp[i]); // update the max length
        }
        return max_len;
    }
};


//--------------------------------------------------------------

// O(NlogN)
// "贪"
// 使用栈保存数据，约束是约束从小到大。
// 如果当前值比栈顶元素大，进栈。
// 否则，查找第一个大于等于该值的元素，执行替换。
// 这样在当前位置而言，栈的大小仍代表最大LIS的长度。
// 但又能让他继续添加，比当前位置大的元素入栈。

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        vector<int> stack;
        stack.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > stack.back()) {
                // push
                stack.push_back(nums[i]);
            }
            else {
                int low = 0, high = stack.size()-1;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (stack[mid] >= nums[i]) {
                        high = mid - 1;
                    }
                    else {
                        low = mid + 1;
                    }
                }
                stack[low] = nums[i];
            }
        }
        return stack.size();
    }
};