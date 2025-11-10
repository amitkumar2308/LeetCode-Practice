class Solution {
public:
    vector<vector<string>> res;

    // helper recursive function
    void solve(int n, int row,
               vector<string>& board,
               vector<int>& cols,
               vector<int>& diag1,
               vector<int>& diag2) {

        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col])
                continue;

            // place queen
            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 1;

            // recursive call for next row
            solve(n, row + 1, board, cols, diag1, diag2);

            // backtrack
            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<int> cols(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);

        solve(n, 0, board, cols, diag1, diag2);
        return res;
    }
};