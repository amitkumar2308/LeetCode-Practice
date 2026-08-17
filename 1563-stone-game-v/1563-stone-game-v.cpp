class Solution {
public:
    int solve(vector<int>& stoneValue,vector<int>& prefix,vector<vector<int>>&dp,int l,int r){

        if(l==r)return 0;
        int ans =  0;
        
        if(dp[l][r]!=-1) return dp[l][r];
        for(int k=l; k<r; k++){
            int leftSum = prefix[k+1] - prefix[l];
            int rightSum = prefix[r+1] - prefix[k+1];


            if(leftSum<rightSum){
                ans = max(ans,leftSum + solve(stoneValue,prefix,dp,l,k));
            }else if(rightSum<leftSum){
                ans = max(ans,rightSum + solve(stoneValue,prefix,dp,k+1,r));
            }else{
                ans = max(ans,leftSum + max(solve(stoneValue,prefix,dp,l,k),solve(stoneValue,prefix,dp,k+1,r)));
            }

            

        }
        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n =  stoneValue.size();
        
         

        // Prefix sum
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(stoneValue,prefix,dp,0,n-1);


    }
};