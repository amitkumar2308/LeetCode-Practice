class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        for(string w:strs){
            string sortstr = w;
            sort(sortstr.begin(),sortstr.end());
            mp[sortstr].push_back(w);
        }

        vector<vector<string>>result;
        for(auto &s:mp){
            result.push_back(s.second);
        }

        return result;
    }
};