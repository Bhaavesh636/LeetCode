class Solution {
public:
    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') continue;

                for (char ch = '1'; ch <= '9'; ch++) {
                    if (isValid(board, r, c, ch)) {
                        board[r][c] = ch;

                        if (solve(board))
                            return true;

                        board[r][c] = '.';
                    }
                }

                return false;
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board,
                 int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch ||
                board[i][col] == ch ||
                board[3 * (row / 3) + i / 3]
                     [3 * (col / 3) + i % 3] == ch)
                return false;
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};