/**
 * 以第一行，第一列当做dashboard，但需要先判断第一行与第一列是否
 * 包含0，之后再处理。
 */


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        
        int n = matrix[0].size();
        bool zero_in_first_row = false, zero_in_first_col = false;
        
        //cout << m << " " << n << endl;
        
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                zero_in_first_row = true;
                break;
            }
        }
        
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                zero_in_first_col = true;
                break;
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        // rows
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        // columns
        for (int i = 1; i < n; i++) {
            if (matrix[0][i] == 0) {
                for (int j = 0; j < m; j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        
        if (zero_in_first_row) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
        
        if (zero_in_first_col) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};