class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat;
        if (n == 0) return mat;
        
        for (int i = 0; i < n; ++i) {
            mat.push_back(vector<int>(n, 0));
        }
        
        int i= 0, j = 0;
        int cur = 1, m;
        for (m = n-1; m > 0; m -= 2) {
            for (int k = 0; k < m; k++)
                mat[i][j+k] = cur++;
            j += m;
            
            for (int k = 0; k < m; k++)
                mat[i+k][j] = cur++;
            i += m;
            
            for (int k = 0; k < m; k++)
                mat[i][j-k] = cur++;
            j -= m;
            
            for (int k = 0; k < m; k++)
                mat[i-k][j] = cur++;
            
            // move to new position
            i -= m-1;
            ++j;
        }
        
        if (n%2) 
            mat[n/2][n/2] = n * n;
    }
};