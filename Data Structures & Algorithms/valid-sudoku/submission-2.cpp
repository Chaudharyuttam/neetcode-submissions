class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {

        // horizontal
        for(int j = 0; j < 9; j++) {
            if(j != col && board[row][j] == dig) {
                return false;
            }
        }

        // vertical
        for(int i = 0; i < 9; i++) {
            if(i != row && board[i][col] == dig) {
                return false;
            }
        }

        // 3*3 box
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;

        for(int i = srow; i < srow + 3; i++) {
            for(int j = scol; j < scol + 3; j++) {
                if((i != row || j != col) && board[i][j] == dig) {
                    return false;
                }
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board, int row, int col) {

        if(row == 9)
            return true;

        int nextrow = row;
        int nextcol = col + 1;

        if(nextcol == 9) {
            nextrow = row + 1;
            nextcol = 0;
        }

        if(board[row][col] != '.') {

            if(!isSafe(board, row, col, board[row][col]))
                return false;

            return helper(board, nextrow, nextcol);
        }
        return helper(board, nextrow, nextcol);
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return helper(board, 0, 0);
    }
};