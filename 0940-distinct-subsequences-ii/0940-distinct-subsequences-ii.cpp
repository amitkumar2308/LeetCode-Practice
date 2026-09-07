class Solution {
public:
    int distinctSubseqII(string s) {

        const long long MOD = 1e9 + 7;

        // dp[i] = number of distinct subsequences
        // including empty subsequence
        long long dp = 1;

        // last[c] = dp value before previous occurrence of c
        vector<long long> last(26, 0);

        for (char ch : s) {

            int c = ch - 'a';

            long long newDp = (2 * dp) % MOD;

            // Remove duplicates created by previous occurrence
            newDp = (newDp - last[c] + MOD) % MOD;

            last[c] = dp;

            dp = newDp;
        }

        // Remove empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};