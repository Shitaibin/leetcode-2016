// 公司：未知
// 
// 最初想到的是v1，使用快速选择，效率一般。
// 其他人给出了使用STL堆的方法，即v2，效率比较好。
// 后来使用STL的nth_element(v3)，效率又提高一节。
// v4:v1的增强版，使用median作为pivot，性能接近v3.
// 
// 选取一个好的pivot能够获得较好的性能，选取第一个元素作为
// pivot的快排和快选性能一般，最坏情况甚至降到O(N^2)。
// 
// STL为了避免这个问题，从头、尾、中间选择pivot，并且当
// 元素数量较少时（Windows STL实现中限定为32），使用插入排序。
// 
// 
// QucikSelect: https://en.wikipedia.org/wiki/Quickselect


// 附件问题：
// 是选用快选好，还是选择大顶堆好？
// 选用max heap还是min heap好。
// 
// 从个版本的运行时间来看，快选的性能要好于heap。
// 另外heap的方案v2还删除了本来的元素，为了执行删除操作，
// 从v2得到了v5，但性能没有提升，反而运行时间变长了。
// 
// 而对于两种不同的heap，如果选取的h>N/2，还是选用min heap较好，
// 因为不需要删除太多的元素，否则，选max heap可以较少的删除元素。




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
    // pivot之前的都小于它，之后的都大于等于它。
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
        // 把nums转化为符合max heap约束的vector
        // 指定第3个参数为，less<int>()可构造min heap
        make_heap(nums.begin(), nums.end());
        while (--k) {
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

// v4:13ms
class Solution {
    void move_median_to_begin(vector<int>& nums, int beg, int end) {
        // at least 3 number
        int mid = beg + (end - beg) / 2;
        // if ((nums[beg] >= nums[mid] && nums[beg] <= nums[end]) ||
        //     (nums[beg] >= nums[end] && nums[beg] <= nums[mid])) {
        //         // beg is median
        //         return;
        //     }
        if ((nums[mid] >= nums[beg] && nums[mid] <= nums[end]) ||
            (nums[mid] >= nums[end] && nums[mid] <= nums[beg])) {
                // mid is median
                swap(nums[mid], nums[beg]);
                return;
            }
        if ((nums[end] >= nums[beg] && nums[end] <= nums[mid]) ||
            (nums[end] >= nums[mid] && nums[end] <= nums[beg])) {
                // end is median
                swap(nums[end], nums[beg]);
                return;
            }
    }
    
    int partition(vector<int>& nums, int beg, int end) {
        if (beg == end) return beg;
        if (beg == end-1) {
            if (nums[beg] > nums[end])
                swap(nums[beg], nums[end]);
            return beg;
        }
        
        move_median_to_begin(nums, beg, end);
        
        int pivot = nums[beg];
        int i = beg + 1;
        int part = beg;
        while (i <= end) {
            if (nums[i] < pivot)
                swap(nums[++part], nums[i]);
            i++;
        }
        swap(nums[beg], nums[part]);
        return part;
    }
    
    int findKth(vector<int>& nums, int beg, int end, int k) {
        int pivot = partition(nums, beg, end);
        if (pivot == nums.size()-k)
            return nums[pivot];
        if (pivot > nums.size()-k)
            return findKth(nums, beg, pivot-1, k);
        else
            return findKth(nums, pivot+1, end, k);
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKth(nums, 0, nums.size()-1, k);
    }
};