class Solution {
public:
    int m,n;
    int solve(string &text1, string &text2,int i,int j, vector<vector<int>> &dp){
        if(i>=m || j>=n) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]){
            return dp[i][j] = 1+solve(text1,text2,i+1,j+1,dp);
        }
        return dp[i][j]= max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));

    }
    int longestCommonSubsequence(string text1, string text2) {
         m = text1.length();
         n = text2.length();

         vector<vector<int>> dp(m, vector<int>(n, -1));


        return solve(text1,text2,0,0,dp);
    }
};