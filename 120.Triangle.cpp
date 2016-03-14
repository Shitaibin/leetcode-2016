class Solution {
    void minimumTotalHelper(vector<vector<int>>& triangle, int i, int j, int cur_sum, int &result) {
        if (i >= triangle.size()) {
            if (result > cur_sum) {
                result = cur_sum;
            }
            return; // forget this
        }
        
        cur_sum += triangle[i][j];
        for (int k = j; k <= j+1 && k < triangle[i].size(); k++) {
            minimumTotalHelper(triangle, i+1, k, cur_sum, result);
        }
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int result = INT_MAX;
        minimumTotalHelper(triangle, 0, 0, 0, result);
        return result;
    }
};