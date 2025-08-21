class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        // dp[i][j] = min steps to convert word1[0..i-1] -> word2[0..j-1]
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        // Base case: word1 empty -> need j insertions
        for(int j=0; j<=n; j++){
            dp[0][j] = j;
        }

        //Base case: word2 empty -> need i deletions

        for(int i=0; i<=m; i++){
            dp[i][0] = i;
        }


        //fill up dp table
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = 1+ min({
                        dp[i-1][j],   //deletion of last char word1
                        dp[i][j-1], //insert last char of word 2
                        dp[i-1][j-1]  //replce last char of word1 with word 2
                    });
                }
            }
        }

    return dp[m][n];

    }
};