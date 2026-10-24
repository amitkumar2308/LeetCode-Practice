class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;

        int l = 0, ans=0;

        for(int r=0; r<s.size(); r++){
            if(mp.find(s[r])!=mp.end()){
                l = max(l,mp[s[r]]+1);
            }

            mp[s[r]] = r;
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};