class Solution {
public:
    // int solve(int i,string & s, vector<int>& dp) {
    //     if(i==s.size()) return 1;
    //     if(s[i]=='0') return 0;
    //     if(dp[i]!=-1) return dp[i];

    //     int ways = 0;

    //     //take 1 digit
    //     ways += solve(i+1,s,dp);

    //     //take 2 digits
    //     if(i+1<s.size()){
    //         int two = (s[i]-'0')*10 + (s[i+1]-'0');
    //         if(two>=10 && two<=26){
    //             ways+=solve(i+2,s,dp);
    //         }
    //     }

    // return ways;
    // }

    int numDecodings(string s){
        int n = s.size();
        if(n==0 || s[0]=='0') return 0; 
        //vector<int>dp(n+1,0);

        int prev2 = 1; //dp[0]
        int prev1= 1;  //dp[1]  (since s[0] != '0')

        for(int i=2; i<=n; i++){
        int curr = 0;
        if(s[i-1]!='0')
            curr += prev1; //take single digit
        
        int two = (s[i-2]-'0')*10 + (s[i-1]-'0');
        if(two>=10 && two<=26)
            curr += prev2;

            prev2 = prev1;
            prev1 = curr;
        


        }




        return prev1;
    }
};