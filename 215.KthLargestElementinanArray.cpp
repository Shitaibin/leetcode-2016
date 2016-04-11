// 公司：未知
// 
// 最初想到的是v1，使用快速选择，效率一般。
// 其他人给出了使用STL堆的方法，即v2，效率比较好。
// 后来使用STL的nth_element，效率又提高一节。
// 
// 选取一个好的pivot能够获得较好的性能，选取第一个元素作为
// pivot的快排和快选性能一般，最坏情况甚至降到O(N^2)。
// 
// STL为了避免这个问题，从头、尾、中间选择pivot，并且当
// 元素数量较少时（Windows STL实现中限定为32），使用插入排序。
// 
// QucikSelect: https://en.wikipedia.org/wiki/Quickselect


// 附件问题：是选用快选好，还是选择大顶堆好？



// v1: 72ms
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, 0, nums.size() - 1, k);
    }

    // O(klogN)
    int findKth(vector<int>& nums, int beg, int end, int k) {
        int p = partition(nums, beg, end);
        if (end + 1 - p == k) return nums[p];
        //else
        if (end + 1 - p > k)
            return findKth(nums, p + 1, end, k);
        else
            return findKth(nums, beg, p - 1, k - (end + 1 - p));
    }

    // 这个划分函数的效率比较高
    // O(N)
    int partition(vector<int>& nums, int beg, int end) {
        if (beg == end) return beg;
        if (beg + 1 == end) {
            if (nums[beg] > nums[end])
                swap(nums[beg], nums[end]);
            return beg;
        }
        int pivot = nums[beg];
        int i = beg + 1;
        int part = beg;
        while (i <= end) {
            if (nums[i] < pivot) {
                part++;
                swap(nums[part], nums[i]);
            }
            i++;
        }
        swap(nums[part], nums[beg]);
        return part;
    }
};

// v2:20ms
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 默认构造一个max heap
        // 指定第3个参数为，less<int>()可构造min heap
        make_heap(nums.begin(), nums.end());
        for (int i = 0; i < k-1; i++) {
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return nums.front();
    }
};

// v3:12ms
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // greater<int>(): 参数类型为int的函数对象
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        return nums[k-1];
    }
};