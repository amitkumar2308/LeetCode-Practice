class Solution {
public:
    int rows, cols;
    void bfs(vector<vector<char>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            if (row < 0 || row >= rows || col < 0 || col >= cols)
                continue;

            if (grid[row][col] == '0')
                continue;

            grid[row][col] = '0';

            q.push({row + 1, col}); // down
            q.push({row - 1, col}); // up
            q.push({row, col + 1}); // right
            q.push({row, col - 1}); // left
        };
    };
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        rows = grid.size();
        cols = grid[0].size();
        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    ++count;
                    bfs(grid, i, j);
                }
            }
        }

        return count;
    }
};