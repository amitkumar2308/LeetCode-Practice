class Solution {
public:
    bool isAnagram(string s, string t) {

         if(s.size()!=t.size()) return false;
         vector<int>freq(26,0);

         for(char c:s){
            freq[c-'a']++;
         }

         for(char x:t){
            freq[x-'a']--;
         }

         for(int cnt:freq){
             if(cnt!=0) return false;
         }

         return true;
    }
};