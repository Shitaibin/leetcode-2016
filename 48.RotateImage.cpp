/**
 * 坐标变换为：(i,j) -> (j,n-1-i)。
 * n > 1时才需要变换。
 * 需要想到一个办法，只让每个值移动一次，并且in-place：使用一个for循环。
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                //cout << i << "," << j << endl ;
                int x = j, y = n - 1 - i;
                
                int v = matrix[i][j];
                //cout << x << " " << y << endl;
                for (int k = 0; k < 3; k++) {
                    int new_v = matrix[x][y];
                    matrix[x][y] = v;
                    v = new_v;
                    
                    int old_y = y;
                    y = n - 1 - x;
                    x = old_y;
                    //cout << x << " " << y << endl;
                }
                
                
                //assert (x == i && y == j);
                matrix[i][j] = v;
            }
        }
    }
};