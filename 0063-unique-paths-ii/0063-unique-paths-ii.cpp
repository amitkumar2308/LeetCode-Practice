class Solution {
public:
    int solve(int i, int j, int m , int n,vector<vector<int>> obstacleGrid, vector<vector<int>>&dp){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n || obstacleGrid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];


        return solve(i+1,j,m,n, obstacleGrid,dp) + solve(i,j+1,m,n, obstacleGrid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); //row
        int n = obstacleGrid[0].size(); //col

        vector<vector<int>>dp(m,vector<int>(n,-1));
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        return solve(0,0,m,n,obstacleGrid,dp);

        


    }
};