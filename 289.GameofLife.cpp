class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m == 0) return;
        
        int n = board[0].size();
        
        vector<vector<int> > new_board(board);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // count alive neighbors
                int count = 0;
                for (int ii = max(0, i-1); ii < min(m, i+1+1); ii++) {
                    for (int jj = max(0, j-1); jj < min(n, j+1+1); jj++) {
                        if (board[ii][jj] == 1) count++;
                    }
                }
                    
                if (board[i][j] == 1) {
                    // alive
                    count--;
                    if (count < 2) new_board[i][j] = 0;
                    else if (count > 3) new_board[i][j] = 0;
                } else {
                    // dead
                    if (count == 3) new_board[i][j] = 1; // realive
                }
            }
        }
        
        board = new_board;
        return;
    }
};