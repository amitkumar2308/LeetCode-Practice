class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int left = 0, maxLen = 0;

        for(int right = 0; right<s.size(); right++){
            char c = s[right];

            if(mp.find(c)!=mp.end(c) && mp[c]>=left){
                left = mp[c] + 1;
            }

            mp[c] = right;


            maxLen = max(maxLen, right-left+1);
        }
       
    return maxLen;
    }
};