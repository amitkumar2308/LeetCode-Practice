class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int x : nums) {
            vector<long long> newDp(k, 0);

            // Start a new subarray with only x
            newDp[x % k]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0) continue;

                int newR = (r * 1LL * (x % k)) % k;
                newDp[newR] += dp[r];
            }

            dp = newDp;

            // Every subarray ending at current x
            // contributes to final answer
            for (int r = 0; r < k; r++) {
                result[r] += dp[r];
            }
        }

        return result;
    }
};