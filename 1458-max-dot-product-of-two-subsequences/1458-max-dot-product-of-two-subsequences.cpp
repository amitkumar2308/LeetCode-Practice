class Solution {
public:
    int n,m;
    
    int solve(int i,int j,vector<int>& nums1,vector<int>& nums2, vector<vector<int>>&dp){
        if(i==n || j==m) return -1e9;

        if(dp[i][j]!=-1e9) return dp[i][j];

        int take  = nums1[i]*nums2[j] + max(0,solve(i+1,j+1,nums1,nums2,dp));
        int skip1 = solve(i,j+1,nums1,nums2,dp);
        int skip2 = solve(i+1,j,nums1,nums2,dp);

        return dp[i][j]=max({take,skip1,skip2});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        vector<vector<int>>dp(n, vector<int>(m,-1e9));

        return solve(0,0,nums1,nums2,dp);

    }
};