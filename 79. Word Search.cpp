class Solution {
private:
    int d[4][2] = {{-1, 0}, {1, 0},  {0, -1}, {0, 1}}; // direction
    
    bool search(vector<vector<char>> &board, int i, int j, string &word, int k) {
        if (k == word.size()) {
            // got a solution
            return true;
        }
        
        if (board[i][j] != word[k]) {
            return false;
        }
        
        // equal at index k
        char bk = board[i][j];
        board[i][j] = '*'; // has been visited
        for (int m = 0; m < 4; m++) {
            int x = i + d[m][0];
            int y = j + d[m][1];
            if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
                if ( search(board, x, y, word, k+1) ){
                    return true;
                }
            }
        }
        board[i][j] = bk; // remove visit mark
        
        // boundary
        // only one character, no four adject position
            // if (k == word.size()-1)
            //     return true;
            // else
            //     // not find next position
            //     return false;
        // simple replace
        return k == word.size()-1;
        
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty()) 
            return false;
            
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if ( search(board, i, j, word, 0) ) {
                    return true;
                }
            }
        }
        
        return false;
    }
};