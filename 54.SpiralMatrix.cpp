/*
 * 1. 把每一行/列的节点都访问完，再移到下一个位置
 * 2. 写出条件来，放便写下一个for循环
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int row = matrix.size();
        if (row <= 0) return v;
        int col = matrix[0].size();
        if (col <= 0) return v;
        
        int r, c; // current visiting row and column
        for (r=0, c=0; r<(row+1)/2 && c<(col+1)/2; r++, c++) {
            // top
            for (int i=c; i < col-c; i++) {
                v.push_back(matrix[r][i]);
            }
            // right: row `r` has been visited
            for (int i=r+1; i < row-r; i++) {
                v.push_back(matrix[i][col-c-1]);
            }
            // bottom: row `r` and col `col-c-1` has been vistited
            for (int i=col-c-2; row-r-1 > r && i >=c; i--) {
                v.push_back(matrix[row-r-1][i]);
            }
            // left: row `r`, col `col-c-1` and row `row-r-1` has been vistited
            for (int i=row-r-2; c < col-c-1 && i>r; i--) {
                v.push_back(matrix[i][c]);
            }
        }
        return v;
    }
};