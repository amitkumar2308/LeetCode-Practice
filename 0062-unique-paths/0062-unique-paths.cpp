class Solution {
public:
    // int solve(int i, int j, int m, int n,vector<vector<int>> &dp){
    //     if(i==m-1 && j==n-1) return 1;
    //     if(i>=m || j>=n) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     return solve(i+1,j,m,n,dp) + solve(i,j+1,m,n,dp);
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

    return dp[m-1][n-1];
    }
};