class Solution {
public:
    bool isPalindrome(string &s, int l, int r){
         while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
         }
         return true;
    }
    
    int maxPalindromes(string s, int k) {
        int n = s.length();

        vector<int>dp(n+1,0);
        for(int r=0; r<n; r++){
            dp[r+1] = dp[r];
            for(int l=0; l<=r; l++){
                if(r-l+1<k) continue;

                if(isPalindrome(s,l,r)){
                    dp[r+1] = max(dp[r+1],dp[l]+1);
                }
            }
        }
        return dp[n];
    }
};