class Solution {
public:
    int m, n;
    vector<vector<char>> grid;

    // 3D memo:
    // memo[i][j][balance]
    vector<vector<vector<int>>> memo;

    bool dfs(int i, int j, int balance) {

        // Current cell process karo
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        // Invalid prefix
        if (balance < 0)
            return false;

        // Destination
        if (i == m - 1 && j == n - 1) {
            return balance == 0;
        }

        // Already calculated
        if (memo[i][j][balance] != -1)
            return memo[i][j][balance];

        bool ans = false;

        // Down
        if (i + 1 < m) {
            ans = ans || dfs(i + 1, j, balance);
        }

        // Right
        if (j + 1 < n) {
            ans = ans || dfs(i, j + 1, balance);
        }

        return memo[i][j][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        this->grid = grid;

        m = grid.size();
        n = grid[0].size();

        int len = m + n - 1;

        // Valid parentheses string ki length even honi chahiye
        if (len % 2 == 1)
            return false;

        // Starting ')' hua to immediately invalid
        if (grid[0][0] == ')')
            return false;

        // memo[m][n][balance]
        memo.assign(
            m,
            vector<vector<int>>(
                n,
                vector<int>(len + 1, -1)
            )
        );

        return dfs(0, 0, 0);
    }
};