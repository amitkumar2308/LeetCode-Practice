class Solution {
public:
    int mod = 1e9+7;

    int solve(int i, int j, int moves, int m, int n, vector<vector<vector<int>>>&dp){
        if(i<0 || j<0 || i>=m || j>=n) return 1;

        if(moves==0) return 0;

        if(dp[i][j][moves]!=-1) return dp[i][j][moves];

        long long up = solve(i-1,j,moves-1,m,n,dp);
        long long down =solve(i+1,j,moves-1,m,n,dp);
        long long left =solve(i,j-1,moves-1,m,n,dp);
        long long right =solve(i,j+1,moves-1,m,n,dp);

        return dp[i][j][moves] = (up+down+left+right)%mod;


    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m,vector<vector<int>>
        (n,vector<int>(maxMove+1,-1))
        );

        return solve(startRow,startColumn,maxMove,m,n,dp);


    }
};