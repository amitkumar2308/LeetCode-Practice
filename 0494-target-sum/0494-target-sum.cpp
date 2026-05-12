class Solution {
public:
    int dfs(int i,int j,vector<int>& nums, int target,vector<vector<int>>&dp){
            if(i==nums.size()){
                return j == target ?1:0;
            }

            if(dp[i][j+1000]!=-1) return dp[i][j+1000];

            int plus = dfs(i+1,j+nums[i],nums,target,dp);
            int minus = dfs(i+1,j-nums[i],nums,target,dp);

            return dp[i][j+1000] = plus+minus;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n =  nums.size();

        vector<vector<int>>dp(n,vector<int>(2001,-1));
        return dfs(0,0,nums,target,dp);
    }
};