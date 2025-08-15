class Solution {
public:
    int noofpath(int i,int &n, vector<int>& dp){
        if(i>n){
            return 0;
        }
        if(i==n){
           return 1;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        return dp[i] =  noofpath(i+1,n,dp)+noofpath(i+2,n,dp);

    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return noofpath(0,n,dp);
    }
};