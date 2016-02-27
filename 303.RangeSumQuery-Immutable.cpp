class NumArray {
private:
    int size;
    vector<long long> sums;
public:
    // 注意初始化的方式
    NumArray(vector<int> &nums): size(nums.size()), sums(size+1, 0) {
        for (int i = 0; i<size; i++) {
            sums[i+1] = sums[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);