class Solution {
public:
    int solve(int i, vector<int>& points, vector<int>&dp){
        if(i==0) return points[0];
        if(i==1) return max(points[0],points[1]);

        if(dp[i]!= -1) return dp[i];

        return dp[i] = max(solve(i-1, points,dp),solve(i-2,points,dp)+points[i]);

       
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(),nums.end());
        vector<int>points(maxVal+1,0);

        for(int x:nums) points[x]+=x;
        vector<int>dp(maxVal+1,-1);
        return solve(maxVal,points,dp);
    }
};