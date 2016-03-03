// v2
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int l = 0, r = m*n-1;
        while (l <= r) {
            int mid = (l+r) / 2;
            if (matrix[mid/n][mid%n] == target) {
                return true;
            }
            if (matrix[mid/n][mid%n] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
        
    }
};

// v1
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        
        int l = 0, r = matrix.size()-1;
        while (l <= r) {
            int mid = (l+r) / 2;
            if (matrix[mid][0] == target) {
                return true;
            }
            if (matrix[mid][0] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        // bug1, forget it
        // invalid row `r`
        if (r < 0) 
            return false;
        
        // number maybe in matrix[r]
        vector<int> v = matrix[r];
        l = 0, r = v.size()-1;
        while (l <= r) {
            int mid = (l+r) / 2;
            if (v[mid] == target) {
                return true;
            }
            if (v[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
        
    }
};