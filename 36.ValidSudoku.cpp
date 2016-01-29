/**
 * v1：生成每个单元的临时的vector，然后判断每个单元是否有重复。
 * v2：不生成临时的vector，直接判断本单元是否重复。
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return check_rows(board) && check_columns(board) && check_cells(board);
    }
    
    bool check_rows(vector<vector<char>>& board) {
        char ch;
        for (int i = 0; i < 9; i++) {
            vector<bool> flag(10, false);
            for (int j = 0; j < 9; j++) {
                ch = board[i][j];
                if (ch >= '0' && ch <= '9') {
                    if (flag[ch - '0']) return false;
                    flag[ch - '0'] = true;
                }
            }
        }
        return true;
    }
    
    bool check_columns(vector<vector<char>>& board) {
        char ch;
        for (int i = 0; i < 9; i++) {
            vector<bool> flag(10, false);
            for (int j = 0; j < 9; j++) {
                ch = board[j][i];
                if (ch >= '0' && ch <= '9') {
                    if (flag[ch - '0']) return false;
                    flag[ch - '0'] = true;
                }
            }
        }
        return true;
    }
    
    bool check_cells(vector<vector<char>>& board) {
        char ch;
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<bool> flag(10, false);
                for (int x = i; x < i+3; x++) {
                    for (int y = j; y < j+3; y++) {
                        ch = board[x][y];
                        if (ch >= '0' && ch <= '9') {
                            if (flag[ch - '0']) return false;
                            flag[ch - '0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};