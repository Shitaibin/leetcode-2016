
// 公司：未知


// v1: 104ms。O(N)。
// 手动模拟算法，容易掌握。
// 滑动窗口：
// 1. 移除第一个
// 2. 加入下一个
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 使用双端队列存放那些可能的最大值的下标
        deque<int> dq;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            // 移除步骤
            // 移除离开窗口的下标，如果他在队列里
            if (!dq.empty() && dq.front() == (i - k))
                dq.pop_front(); // pop the max
            
            // 添加步骤
            // 移除所有小于当前值的下标，因为它在队列里时，
            // 这些下标永远不可能是最大值的下标
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i); // 当前元素下标入队

            // 队列的第一个元素永远是最大值的下标
            if (i >= (k - 1))
                result.push_back(nums[ dq.front() ]);
        }
        return result;
    }
};

// v2: 252ms. O(NlogN)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        // 使用multiset存储当前窗口的k个数字
        multiset<int> w;
        
        for (int i = 0; i < nums.size(); i++) {
            // 删除移除窗口的数字
            if (i >= k)
                w.erase(w.find(nums[i-k]));
            w.insert(nums[i]);
            if (i >= (k - 1))
                result.push_back(*(w.rbegin()));
        }
        return result;
    }
};