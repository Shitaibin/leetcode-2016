// v3:
struct position{
    int row, col;
    void set(int r, int c) { row = r; col = c; }
    position(int r, int c): row(r), col(c) {}
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size()<=0 || board[0].size()<=0) return;

        int row = board.size();
        int col = board[0].size();
    
        queue<position> q;
        position p(0,0);
    
        //left & right edge
        for (int r=0; r<row; r++){
            if ( board[r][0] == 'O') {
                board[r][0] = 'N';
                p.set(r, 0);
                q.push(p) ; 
            }
            if ( board[r][col-1] == 'O') {
                board[r][col-1] = 'N';
                p.set(r, col-1);
                q.push(p) ; 
            }
        }
        //top & bottom edge
        for (int c=1; c<col-1; c++){
            if ( board[0][c] == 'O') {
                board[0][c] = 'N';
                p.set(0, c);
                q.push(p) ; 
            }
            if ( board[row-1][c] == 'O') {
                board[row-1][c] = 'N';
                p.set(row-1, c);
                q.push(p) ; 
            }
        }
    
        while (!q.empty()){
            p = q.front();
            q.pop(); 
            int r = p.row;
            int c = p.col;
            if (r < row-1 && board[r+1][c] == 'O') {
                board[r+1][c] = 'N';
                p.set(r+1, c);
                q.push(p);
            }
            if (r > 0 && board[r-1][c] == 'O') {
                board[r-1][c] = 'N';
                p.set(r-1, c);
                q.push(p);
            }
            if (c < col-1 && board[r][c+1] == 'O') {
                board[r][c+1] = 'N';
                p.set(r, c+1);
                q.push(p);
            }
            if (c>0 && board[r][c-1] == 'O') {
                board[r][c-1] = 'N';
                p.set(r, c-1);
                q.push(p);
            }
        }
    
    
        // print(board);
        // change 'N' to 'O', change 'O' to 'X'
        for (int r=0; r<row; r++) {
            for (int c=0; c<col; c++) {
                if (board[r][c] == 'O') {
                    board[r][c]='X';
                } else if (board[r][c] == 'N') {
                    board[r][c]='O';
                }
            }
        }
            
    }
};


// v2: iterative, using queue to store next positions
// 20ms, we create lots of positions, when push it to 
// queue, it will create once again, it means for one
// points, we create it twice.
// optimize 1: queue store the pointer of position
//      but, it's be the opposite, using 24ms
// optimize 2: just create position once, when met 'O'
//      just change the value, it works, using 16ms,
//      so, we got v3, from @haoel
struct position {
    int row, col;
    position(int r, int c): row(r), col(c) {}
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) {
            return;
        }
        
        int row = board.size();
        int col = board[0].size();
        
        // Using queue store next positions
        queue<position> q;
        
        // left & right edges
        for (int r = 0; r < row; r++) {
            if (board[r][0] == 'O') {
                // board[r][0] = 'N';
                q.push(position(r, 0));
            }
            if (board[r][col-1] == 'O') {
                q.push(position(r, col-1));
            }
        }
        
        // top & bottom edegs
        for (int c = 0; c < col; c++) {
            if (board[0][c] == 'O') {
                q.push(position(0, c));
            }
            if (board[row-1][c] == 'O') {
                q.push(position(row-1, c));
            }
        }
        
        // find next position and transform it
        while (q.size()) {
            position p = q.front();
            q.pop();
            
            int r = p.row;
            int c = p.col;
            board[r][c] = 'N';
            

            if (r < row-1 && board[r+1][c] == 'O') {
                q.push(position(r+1, c));
            }
            if (r > 0 && board[r-1][c] == 'O') {
                q.push(position(r-1, c));
            }
            if (c < col-1 && board[r][c+1] == 'O') {
                q.push(position(r, c+1));
            }
            if (c > 0 && board[r][c-1] == 'O') {
                q.push(position(r, c-1));
            }
            
        }
        
        // transform
        // Closed: 'O' -> 'X'
        // Open: 'N' -> 'O'
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'N') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};


// v1: recursive, Runtime Error
class Solution {
private:
    // 边上的O一定的开放的，标记为N
    // 与边上的N相连的，一定也是N
    // Runtime error when col = 250
    void markOpen(vector<vector<char> > &board, int row, int col, int r, int c) {
        if (board[r][c] == 'O') {
            board[r][c] = 'N';
            
            if (r < row-1) {
                markOpen(board, row, col, r+1, c);
            }
            if (r > 0) {
                markOpen(board, row, col, r-1, c);
            }
            if (c < col-1) {
                markOpen(board, row, col, r, c+1);
            }
            if (c > 0) {
                markOpen(board, row, col, r, c-1);
            }
        }
    }

    // Runtime error when col = 250
    void solve_recursive(vector<vector<char>>& board){
        if (board.size() == 0 || board[0].size() == 0) {
            return;
        }
        
        int row = board.size();
        int col = board[0].size();
        
        // left & right edges
        for (int r = 0; r < row; r++) {
            markOpen(board, row, col, r, 0);
            markOpen(board, row, col, r, col-1);
        }
        
        // top & bottom edegs
        for (int c = 0; c < col; c++) {
            markOpen(board, row, col, 0, c);
            markOpen(board, row, col, row-1, c);
        }
        
        // transform
        // Closed: 'O' -> 'X'
        // Open: 'N' -> 'O'
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'N') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    

public:
    void solve(vector<vector<char>>& board) {
        
    }
};