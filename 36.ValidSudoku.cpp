class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // rows
        for (int i = 0; i < 9; i++) {
            if (!validCell(board[i])) return false;
        }
        
        // columns
        for (int i = 0; i < 9; i++) {
            vector<char> col;
            for (int j = 0; j < 9; j++) {
                col.push_back(board[j][i]);
            }
            if (!validCell(col)) return false;
        }
        
        // 3x3 cells
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<char> cell;
                cell.push_back(board[i][j]);
                cell.push_back(board[i][j+1]);
                cell.push_back(board[i][j+2]);
                cell.push_back(board[i+1][j]);
                cell.push_back(board[i+1][j+1]);
                cell.push_back(board[i+1][j+2]);
                cell.push_back(board[i+2][j]);
                cell.push_back(board[i+2][j+1]);
                cell.push_back(board[i+2][j+2]);
                
                if (!validCell(cell)) {
                    //cout << i << " " << j << endl;
                    return false;
                }
            }
        }
        return true;
    }
    
    bool validCell(vector<char> cell) {
        int char_map[10] = {0};
        for (int i = 0; i < cell.size(); ++i) {
            if (cell[i] == '.') continue;
            int num = cell[i] - '0';
            if (char_map[num] == 0) {
                char_map[num] = 1;
            } else {
                return false;
            }
        }
        return true;
    }
};