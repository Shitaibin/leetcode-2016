// 公司：未知

// 转化为二分搜索
// 数据特征使得我们可以在行或列上进行二分搜索，时间复杂度为O(MlogN)
// 或O(NlogM)。
// 这两个数据特征合起来，可以使我们在矩阵的副对角线上进行二分搜索。
// 一个元素必然比它左边的大，比它右边的小。
// 实现方案为v1。v2在v1的基础上优化，通过在矩阵上画出搜索轨迹，
// 这是符合搜索特征的，时间从272ms降到248ms。


// v2: 优化v1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int i = 0, j = matrix[0].size()-1;
        while (i < matrix.size() && j >= 0) {
            if (target == matrix[i][j]) {
                return true;
            }
            while (j >= 0 && target < matrix[i][j]) {
                j--;
            } 
            while (i < matrix.size() && target > matrix[i][j]) {
                i++;
            }
        }
        return false;
    }
};


// v1: 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int i = 0, j = matrix[0].size()-1;
        while (i < matrix.size() && j >= 0) {
            if (target == matrix[i][j]) {
                return true;
            }
            else if (target < matrix[i][j]) {
                j--;
            }
            else {
                i++;
            }
        }
        return false;
    }
};