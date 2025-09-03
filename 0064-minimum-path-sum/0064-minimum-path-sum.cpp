class Solution {
public:
    // recursion + memo
     int solve(int i, int j, vector<vector<int>>& grid,vector<vector<int>>&dp){
         int row = grid.size();
         int col = grid[0].size();
  
         //base cases
         if(i==row-1 && j==col-1) return grid[i][j];
         if(i>=row || j>=col) return 1e9;
         if (dp[i][j] !=-1) return dp[i][j];

         int down = solve(i+1,j,grid,dp);
         int right = solve(i,j+1,grid,dp);
         return dp[i][j] = grid[i][j] + min(down,right);
     }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));
        return solve(0,0,grid,dp);
    }
};