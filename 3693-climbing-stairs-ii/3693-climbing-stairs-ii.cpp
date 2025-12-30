class Solution {
public:
    int solve(int n, vector<int>& costs,vector<int>&dp){
        if(n==0) return 0;
        if(n<1) return INT_MAX;
        if(dp[n]!=-1) return dp[n];

        int ans = INT_MAX;

        int from1 = solve(n-1,costs,dp);
            if(from1!=INT_MAX){
                ans = min(ans,from1+costs[n-1]+1);
            }
        

        int from2 = solve(n-2,costs,dp);
            if(from2!=INT_MAX){
                ans = min(ans,from2+costs[n-1]+4);
            }
        

        int from3 = solve(n-3,costs,dp);
            if(from3!=INT_MAX){
                ans = min(ans,from3+costs[n-1]+9);
            }
        

       return dp[n] = ans;

    }
    int climbStairs(int n, vector<int>& costs) {
        
        vector<int>dp(n+1,-1);
        return solve(n,costs,dp);


    }
};