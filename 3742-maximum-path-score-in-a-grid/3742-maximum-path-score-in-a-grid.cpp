class Solution {
public:
    int m;
    int n;
    vector<vector<vector<int>>>dp;

    int solve(vector<vector<int>>& grid, int k, int i, int j, int cost) {
        if (i >= m || j >= n)
            return INT_MIN;

        int newCost = cost + (grid[i][j] > 0 ? 1 : 0);

        if (newCost > k)
            return INT_MIN;

        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if(dp[i][j][newCost]!=-1) return dp[i][j][newCost];
        int right = solve(grid, k, i, j + 1, newCost);
        int down = solve(grid, k, i + 1, j, newCost);

        if (right == INT_MIN && down == INT_MIN)
            return dp[i][j][newCost] = INT_MIN;

        return dp[i][j][newCost] = max(right, down) + grid[i][j];
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        dp = vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans = solve(grid, k, 0, 0, 0);
        return ans == INT_MIN ? -1 : ans;
    }
};