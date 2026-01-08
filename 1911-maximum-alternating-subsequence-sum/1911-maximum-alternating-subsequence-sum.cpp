class Solution {
public:
    int n;
    long long solve(int pos, int mode, vector<int>& nums, vector<vector<long long>>& dp) {
        if (pos == n)
            return 0;
        if(dp[pos][mode]!=-1) return dp[pos][mode];

        long long skip = solve(pos + 1, mode, nums,dp);

        long long take;

        if (mode == 0) {
            take = nums[pos] + solve(pos + 1, 1, nums,dp);

        } else {
            take = -nums[pos] + solve(pos + 1, 0, nums,dp);
        }

        return dp[pos][mode]=max(skip, take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, 0, nums,dp);
    }
};