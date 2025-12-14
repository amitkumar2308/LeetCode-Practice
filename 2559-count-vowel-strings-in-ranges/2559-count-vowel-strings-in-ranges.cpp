class Solution {
public:
    bool isVowel(char c){
         return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    bool isValid(string& word){
         return isVowel(word[0]) && isVowel(word.back());
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
           int n = words.size();
           vector<int> prefix(n+1,0);
           for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + (isValid(words[i]) ?1:0);
           }
        vector<int> ans;
        for(auto& q:queries){
            int l = q[0];
            int r = q[1];

            ans.push_back(prefix[r+1] - prefix[l]);
        }
    return ans;
    }
};