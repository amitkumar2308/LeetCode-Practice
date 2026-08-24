class Solution {
public:
    // vector<long long> prefix;
    // vector<long long> memo;
    // long long solve(int i, int n) {
    //     //  int n = stones.size();

    //     if (i == n - 1)
    //         return 0;

    //     if (memo[i] != LLONG_MIN)
    //         return memo[i];

    //     // if(n==1) return 0;
    //     long long best = LLONG_MIN;

    //     for (int j = i + 1; j < n; j++) {
    //         long long currentScore = prefix[j];
    //         long long opponent = solve(j, n);
    //         best = max(best, currentScore - opponent);
    //     }

    //     return memo[i] = best;
    // }
    int stoneGameVIII(vector<int>& stones) {

        int n = stones.size();
        vector<long long>prefix(n);

        prefix[0] = stones[0];


        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + stones[i];
        }

        long long dp = prefix[n-1];

        for(int i=n-2; i>=1; i--){
            dp = max(dp,prefix[i]-dp);
        }
        return dp;
    }
};