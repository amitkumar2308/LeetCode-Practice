class Solution {
public:
    int solve(vector<int>& nums,int left, int right, vector<vector<int>>& dp){
        if(left+1==right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int maxCoins = 0;
        
        for(int i = left+1; i<right; i++){
            int coins = nums[left]*nums[i]*nums[right];

            coins += solve(nums,left,i,dp);
            coins += solve(nums,i,right,dp);

            maxCoins = max(maxCoins,coins);
        
        }

     return dp[left][right] = maxCoins;

    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
       vector<int> arr(n+2);

       arr[0] = 1;
       arr[n+1] = 1;

       for(int i=0; i<n; i++){
        arr[i+1] = nums[i];
       }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return solve(arr, 0, n + 1, dp);
    }
    
};